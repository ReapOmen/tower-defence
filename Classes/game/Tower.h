#ifndef __TOWER_H__
#define __TOWER_H__

#include <tuple>
#include "TowerType.h"

class Tower {

public:
    Tower();

    Tower(const std::tuple<float, float, int, std::string>& towerType);

    float getRange() const;

    float getAttackPower() const;

    int getCost() const;

    std::string getName() const;

    void setRange(float range);

    void setAttackPower(float attackPower);

    void setCost(int cost);

    void setName(const std::string& name);

private:
    float _range;
    float _attackPower;
    int _cost;
    std::string _name;
};

#endif // ends __TOWER_H__
