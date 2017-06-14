#include "Level.h"

USING_NS_CC;
using std::vector;
using std::unique_ptr;

Level::Level(const vector<Vec2>& path)
    : _gold(100),
      _towers(vector<unique_ptr<Tower>>()),
      _enemies(vector<unique_ptr<Enemy>>()),
      _path(std::move(path)),
      _internalTime(0.0f) {
}

void Level::addTower(Tower* tower) {
    int cost = tower->getCost();
    if (cost <= _gold) {
        _towers.emplace_back(tower);
        _gold -= cost;
    }
}

void Level::addEnemy(Enemy* enemy) {
    _enemies.emplace_back(enemy);
    notifyListeners("enemy");
}

const vector<unique_ptr<Enemy>>& Level::getEnemies() const {
    return _enemies;
}

const vector<unique_ptr<Tower>>& Level::getTowers() const {
    return _towers;
}

void Level::update(float dt) {
    for (auto& enemy : _enemies) {
        enemy->update();
    }
    _internalTime += dt;
    if (_internalTime > 0.8f) {
        _internalTime = 0.0f;
        addEnemy(new Enemy(EnemyType::get(EnemyType::NORMAL), _path[0]));
    }
}

int Level::getGold() const {
    return _gold;
}
