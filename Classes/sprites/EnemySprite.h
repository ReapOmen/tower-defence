#ifndef __ENEMY_SPRITE_H__
#define __TOWER_SPRITE_H__

#include <memory>
#include "cocos2d.h"
#include "SelectableSprite.h"
#include "game/Enemy.h"

class EnemySprite : public SelectableSprite {

public:
    EnemySprite();

    EnemySprite(Enemy* enemy);

    static EnemySprite* create(const std::string& img, Enemy* enemy, const cocos2d::Vec2& pos);

    void initOptions(const cocos2d::Vec2& pos);

private:
    Enemy* _enemy;
};

#endif
