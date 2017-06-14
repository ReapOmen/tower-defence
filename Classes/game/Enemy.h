#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <tuple>
#include "cocos2d.h"
#include "EnemyType.h"

class Enemy {

public:
    Enemy();

    Enemy(const std::tuple<float, float, int, std::string>& enemyType);

    float getSpeed() const;

    float getHealth() const;

    int getBounty() const;

    std::string getName() const;

    cocos2d::Vec2 getPosition() const;

    void setSpeed(float speed);

    void setHealth(float health);

    void setBounty(int bounty);

    void setName(const std::string& name);

    void update();

private:
    cocos2d::Vec2 _pos;
    float _speed;
    float _health;
    int _bounty;
    std::string _name;
};

#endif // ends __ENEMY_H__
