#include "SelectableSprite.h"

USING_NS_CC;

SelectableSprite* SelectableSprite::create(Sprite* initSprite) {
    SelectableSprite* sprite = new SelectableSprite();
    if (sprite->initWithSpriteFrame(initSprite->getSpriteFrame())) {
        sprite->initOptions(initSprite->getPosition());
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return NULL;
}

void SelectableSprite::initOptions(const Vec2& p) {
    setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    setPosition(p);
}

void SelectableSprite::select() {
    if (getChildrenCount() == 0) {
        Rect rect = getBoundingBox();
        DrawNode* node = DrawNode::create();
        Vec2 spritePos = getPosition();
        // the circle will get drawn at the position you specified
        // + the position of the sprite which is why we subtract it
        Vec2 circleCenter = Vec2(rect.getMidX() - spritePos.x,
                                 rect.getMidY() - spritePos.y);
        float radius = std::max(rect.getMaxX() - rect.getMinX(),
                                rect.getMaxY() - rect.getMinY());
        node->drawCircle(circleCenter, radius / 2, 0.0f, 50, false, Color4F::GREEN);
        addChild(node);
    }
}

void SelectableSprite::unselect() {
    removeAllChildrenWithCleanup(true);
}
