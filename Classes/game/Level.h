#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <vector>
#include <memory>
#include "Tower.h"
#include "Enemy.h"
#include "cocos2d.h"
#include "utils/EventPusher.h"

class Level : public EventPusher {
public:

    Level(const std::vector<cocos2d::Vec2>& path);

    void addTower(Tower* tower);

    void sellTower(int i);

    void addEnemy(Enemy* enemy);

    const std::vector<std::unique_ptr<Enemy>>& getEnemies() const;

    const std::vector<std::unique_ptr<Tower>>& getTowers() const;

    int getGold() const;

    void update(float dt);

private:
    int _gold;
    std::vector<std::unique_ptr<Tower>> _towers;
    std::vector<std::unique_ptr<Enemy>> _enemies;
    std::vector<cocos2d::Vec2> _path;
    float _internalTime;
};

#endif
