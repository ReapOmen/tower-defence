#include "EnemySprite.h"

USING_NS_CC;

EnemySprite::EnemySprite()
    : _enemy(new Enemy()) {

}

EnemySprite::EnemySprite(Enemy* tower)
    : _enemy(tower) {

}

EnemySprite* EnemySprite::create(const std::string& img, Enemy* tower, const Vec2& pos) {
    EnemySprite* sprite = new EnemySprite(tower);
    if (sprite->initWithFile(img)) {
        sprite->autorelease();
        sprite->initOptions(pos);
        return sprite;
    }

    CC_SAFE_DELETE(sprite);
    return NULL;
}

void EnemySprite::initOptions(const Vec2& pos) {
    setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    setPosition(pos);
}
