#ifndef __TOWER_H__
#define __TOWER_H__

#include <tuple>

class Tower {

public:
    Tower();
    Tower(const std::tuple<std::string, float, float>& towerType);
    float getRange() const;
    float getAttackPower() const;
    std::string getName() const;
    void setRange(float range);
    void setAttackPower(float attackPower);
    void setName(const std::string& name);

private:
    float _range;
    float _attackPower;
    std::string _name;
};

#endif // ends __TOWER_H__
