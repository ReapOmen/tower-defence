#include "Tower.h"

#include "cocos2d.h"
using std::string;
using std::get;

Tower::Tower()
    : _range(0.0f), _attackPower(0.0f) {

}

Tower::Tower(const std::tuple<string, float, float>& towerType)
    : _name(get<0>(towerType)),
      _attackPower(get<1>(towerType)),
      _range(get<2>(towerType)) {
}

float Tower::getRange() const {
    return _range;
}

float Tower::getAttackPower() const {
    return _attackPower;
}

string Tower::getName() const {
    return _name;
}

void Tower::setRange(float range) {
    _range = range;
}

void Tower::setAttackPower(float attackPower) {
    _attackPower = attackPower;
}

void Tower::setName(const string& name) {
    _name = name;
}
