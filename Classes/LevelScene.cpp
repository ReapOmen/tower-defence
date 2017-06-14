#include "LevelScene.h"
#include "sprites/EnemySprite.h"

USING_NS_CC;
#define COCOS2D_DEBUG 1

Scene* LevelScene::createScene() {
    Scene* scene = Scene::create();
    Layer* layer = LevelScene::create();
    scene->addChild(layer);
    return scene;
}

bool LevelScene::init() {
    if (!Layer::init()) {
        return false;
    }
    addEvents();
    _selected = nullptr;
    initMap();
    auto size = Director::getInstance()->getVisibleSize();
    _selector = TowerSelector::create(Vec2(size.width, size.height));
    addChild(_selector);
    scheduleUpdate();
    _level->addListener(this);
    return true;
}

void LevelScene::update(float dt) {
    _level->update(dt);
    int i = 0;
    for (const auto& sprite : getChildren()) {
        auto enemy = dynamic_cast<EnemySprite*>(sprite);
        if (enemy) {
            enemy->setPosition(_level->getEnemies()[i++]->getPosition());
        }
    }
}

void LevelScene::notify(std::string message) {
    if (message == "enemy") {
        auto& enemies = _level->getEnemies();
        Enemy* e = enemies[enemies.size() - 1].get();
        addChild(EnemySprite::create(EnemyType::getResource(e->getName()), e, Vec2::ZERO));
    }
}

void LevelScene::addEvents() {
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    // XXX: used to enable onTouchEnded, find an alternative
    listener->onTouchBegan = [&](Touch* touch, Event* event) {return true;};
    listener->onTouchEnded = [&](Touch* touch, Event* event) {
        Vec2 p = touch->getLocation();
        _selected = nullptr;
        bool shouldHide = true;
        for (auto child : this->getChildren()) {
            auto sprite = dynamic_cast<SelectableSprite*>(child);
            if (sprite) {
                if (sprite->getBoundingBox().containsPoint(p) && !_selected) {
                    sprite->select();
                    _selected = sprite;
                    if (!dynamic_cast<TowerSprite*>(child) ||
                            !dynamic_cast<EnemySprite*>(child)) {
                        this->_selector->show();
                        shouldHide = false;
                    }

                } else {
                    sprite->unselect();
                }
            }
        }
        if (shouldHide) {
            this->_selector->hide();
        }
        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30);
}

void LevelScene::addTower(int i) {
    Tower* tower = new Tower(TowerType::get(i));
    if (_selected && _level->getGold() >= tower->getCost()) {
        Vec2 pos = _selected->getPosition();
        removeChildByTag(_selected->getTag());
        std::string img = TowerType::getResource(tower->getName());
        addChild(TowerSprite::create(img, tower, pos));
        _level->addTower(tower);
        _selector->hide();
    }
}

void LevelScene::initMap() {
    TMXTiledMap* map = TMXTiledMap::create("level1.tmx");
    map->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    addChild(map);
    map->getChildrenCount();
    TMXLayer* layer = map->getLayer("layer1");
    TMXLayer* pathLayer = map->getLayer("path");
    std::vector<Vec2> path = std::vector<Vec2>();
    Size s = layer->getLayerSize();
    int tag = 0;
    for (int x = 0; x < s.width; ++x) {
        for (int y = 0; y < s.height; ++y) {
            Vec2 p = Vec2(x, y);
            int gid = layer->getTileGIDAt(p);
            int pGid = pathLayer->getTileGIDAt(p);
            if (gid != 0) {
                auto removedSprite = layer->getTileAt(p);
                SelectableSprite* newSprite = SelectableSprite::create(removedSprite);
                newSprite->setTag(tag);
                layer->removeTileAt(p);
                addChild(newSprite);
                ++tag;
            }
            if (pGid != 0) {
                path.push_back(pathLayer->getTileAt(p)->getPosition());
            }
        }
    }
    _level = std::move(std::unique_ptr<Level>(new Level(path)));
}
