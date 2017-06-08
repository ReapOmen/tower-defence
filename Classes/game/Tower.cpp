#include "Tower.h"
using std::string;
using std::get;

Tower::Tower()
    : _range(0.0f), _attackPower(0.0f), _cost(0), _name("") {

}

Tower::Tower(const std::tuple<float, float, int, string>& towerType)
    : _range(get<TowerType::RANGE>(towerType)),
      _attackPower(get<TowerType::ATTACK>(towerType)),
      _cost(get<TowerType::COST>(towerType)),
      _name(get<TowerType::NAME>(towerType)) {
}

float Tower::getRange() const {
    return _range;
}

float Tower::getAttackPower() const {
    return _attackPower;
}

int Tower::getCost() const {
    return _cost;
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

void Tower::setCost(int cost) {
    _cost = cost;
}

void Tower::setName(const string& name) {
    _name = name;
}
