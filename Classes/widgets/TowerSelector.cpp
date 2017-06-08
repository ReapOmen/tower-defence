#include "TowerSelector.h"

USING_NS_CC;
using std::get;
using ui::Button;

TowerSelector* TowerSelector::create(const Vec2& pos) {
    TowerSelector* selector  = new TowerSelector();
    if (selector->init()) {
        selector->autorelease();
        selector->initOptions(pos);
        return selector;
    }
    CC_SAFE_DELETE(selector);
    return NULL;
}

void TowerSelector::initOptions(const Vec2& pos) {
    setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);
    setPosition(pos);
    float width = 0.0f;
    int tag = 0;
    for (const auto& tower : TowerType::towers) {
        Button* towerButton = Button::create(TowerType::getResource(get<TowerType::NAME>(tower)));
        towerButton->setTag(tag);
        width = towerButton->getContentSize().width;
        towerButton->addTouchEventListener(CC_CALLBACK_2(TowerSelector::action, this));
        pushBackCustomItem(towerButton);
        ++tag;
    }
    setItemsMargin(10);
    setGravity(ListView::Gravity::CENTER_HORIZONTAL);
    // because <pos> is the top-right corner we can assume that
    // the Y value is the maximum height of this layout
    setContentSize(Size(width, pos.y));
    setBackGroundColorType(ui::LayoutBackGroundColorType::SOLID);
    setBackGroundColor(Color3B::WHITE);
    hide();
}

void TowerSelector::show() {
    setSwallowTouches(true);
    setOpacityForAll(255);
}

void TowerSelector::hide() {
    setSwallowTouches(false);
    setOpacityForAll(0);
}

void TowerSelector::setOpacityForAll(GLubyte val) {
    setOpacity(val);
    for (auto& child : getChildren()) {
        child->setOpacity(val);
    }
}

void TowerSelector::action(Ref* sender, Widget::TouchEventType type) {
    if (type == Widget::TouchEventType::ENDED && getOpacity() > 0) {
        LevelScene* parent = dynamic_cast<LevelScene*>(getParent());
        if (parent) {
            parent->addTower(dynamic_cast<Button*>(sender)->getTag());
        }
    }
}
