#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <vector>
#include <memory>
#include "Tower.h"
#include "cocos2d.h"

class Level {
public:

    Level(const std::vector<cocos2d::Vec2>& path);

    void addTower(Tower* tower);

    void sellTower(int i);

    const std::vector<std::unique_ptr<Tower>>& getTowers() const;

    int getGold() const;

    void update();

private:
    int gold;
    std::vector<std::unique_ptr<Tower>> _towers;
    std::vector<cocos2d::Vec2> _path;
    // std::vector<Enemy> enemies;
};

#endif
