#ifndef __SELECTABLE_SPRITE_H__
#define __SELECTABLE_SPRITE_H__

#include "cocos2d.h"
#include <algorithm>

class SelectableSprite : public cocos2d::Sprite {

public:

    static SelectableSprite* create(cocos2d::Sprite* sprite);

    void initOptions(const cocos2d::Vec2& p);

    virtual void select();

    virtual void unselect();
};

#endif
