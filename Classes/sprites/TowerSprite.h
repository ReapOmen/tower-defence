#ifndef __TOWER_SPRITE_H__
#define __TOWER_SPRITE_H__

#include <memory>
#include "cocos2d.h"
#include "SelectableSprite.h"
#include "game/Tower.h"

class TowerSprite : public SelectableSprite {

public:
    TowerSprite();

    TowerSprite(Tower* tower);

    static TowerSprite* create(const std::string& img, Tower* tower, const cocos2d::Vec2& pos);

    virtual void select() override;

    void initOptions(const cocos2d::Vec2& pos);

private:
    Tower* _tower;
};

#endif
