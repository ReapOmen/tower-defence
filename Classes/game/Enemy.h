#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <tuple>
#include "EnemyType.h"

class Enemy {

public:
    Enemy();

    Enemy(const std::tuple<float, float, int, std::string>& enemyType);

    float getSpeed() const;

    float getHealth() const;

    int getBounty() const;

    std::string getName() const;

    void setSpeed(float speed);

    void setHealth(float health);

    void setBounty(int bounty);

    void setName(const std::string& name);

private:
    float _speed;
    float _health;
    int _bounty;
    std::string _name;
};

#endif // ends __ENEMY_H__
