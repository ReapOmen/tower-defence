#include "EnemyType.h"
#include "cocos2d.h"
using std::tuple;
using std::vector;
using std::map;
using std::string;

const vector<tuple<float, float, int, string>> EnemyType::enemies = {
    std::make_tuple(5.0f, 8.0f, 10, "regular"),
    std::make_tuple(7.0f, 10.0f, 15, "knight")
};

const map<string, string> EnemyType::enemyResources = {
    {"regular", "tower.png"},
    {"sniper", "tower.png"}
};

tuple<float, float, int, string> EnemyType::get(int i) {
    return EnemyType::enemies[i];
}

string EnemyType::getResource(const string& name) {
    return EnemyType::enemyResources.at(name);
}
