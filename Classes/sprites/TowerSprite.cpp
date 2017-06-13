#include "TowerSprite.h"

USING_NS_CC;
#define CC_DEBUG 1

TowerSprite::TowerSprite()
    : _tower(new Tower()) {

}

TowerSprite::TowerSprite(Tower* tower)
    : _tower(tower) {

}

TowerSprite* TowerSprite::create(const std::string& img, Tower* tower, const Vec2& pos) {
    TowerSprite* sprite = new TowerSprite(tower);
    if (sprite->initWithFile(img)) {
        sprite->autorelease();
        sprite->initOptions(pos);
        return sprite;
    }

    CC_SAFE_DELETE(sprite);
    return NULL;
}

void TowerSprite::initOptions(const Vec2& pos) {
    setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    setPosition(pos);
}

void TowerSprite::select() {
    if (getChildrenCount() == 0) {
        Rect rect = getBoundingBox();
        DrawNode* node = DrawNode::create();
        Vec2 spritePos = getPosition();
        // the circle will get drawn at the position you specified
        // + the position of the sprite which is why we subtract it
        Vec2 circleCenter = Vec2(rect.getMidX() - spritePos.x,
                                 rect.getMidY() - spritePos.y);
        node->drawCircle(circleCenter, _tower->getRange(), 0.0f, 50, false, Color4F(Color3B(0, 255, 255)));
        addChild(node);
    }
}
