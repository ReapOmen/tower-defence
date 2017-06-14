#include "Enemy.h"

USING_NS_CC;
using std::string;
using std::get;

Enemy::Enemy()
    : _pos(Vec2::ZERO), _speed(0.0f), _health(0.0f), _bounty(0), _name("") {

}

Enemy::Enemy(const std::tuple<float, float, int, string>& enemyType)
    : _pos(Vec2::ZERO),
      _speed(get<EnemyType::SPEED>(enemyType)),
      _health(get<EnemyType::HEALTH>(enemyType)),
      _bounty(get<EnemyType::BOUNTY>(enemyType)),
      _name(get<EnemyType::NAME>(enemyType)) {
}

float Enemy::getSpeed() const {
    return _speed;
}

float Enemy::getHealth() const {
    return _health;
}

int Enemy::getBounty() const {
    return _bounty;
}

string Enemy::getName() const {
    return _name;
}

Vec2 Enemy::getPosition() const {
    return _pos;
}

void Enemy::setSpeed(float speed) {
    _speed = speed;
}

void Enemy::setHealth(float health) {
    _health = health;
}

void Enemy::setBounty(int bounty) {
    _bounty = bounty;
}

void Enemy::setName(const string& name) {
    _name = name;
}

void Enemy::update() {
    _pos.add(Vec2(_speed, 0));
}
