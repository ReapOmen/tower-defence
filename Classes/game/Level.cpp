#include "Level.h"

USING_NS_CC;
using std::vector;
using std::unique_ptr;

Level::Level(const vector<Vec2>& path)
    : _path(std::move(path)), _towers(vector<unique_ptr<Tower>>()), gold(100) {
}

void Level::addTower(Tower* tower) {
    int cost = tower->getCost();
    if (cost <= gold) {
        _towers.emplace_back(tower);
        gold -= cost;
    }
}

const vector<unique_ptr<Tower>>& Level::getTowers() const {
    return _towers;
}

int Level::getGold() const {
    return gold;
}
