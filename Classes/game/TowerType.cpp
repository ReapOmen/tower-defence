#include "TowerType.h"
#include "cocos2d.h"
using std::tuple;
using std::vector;
using std::map;
using std::string;

const vector<tuple<string, float, float>> TowerType::towers = {
    std::make_tuple("regular", 8, 20),
    std::make_tuple("sniper", 10, 30)
};

const map<string, string> TowerType::towerResources = {
    {"regular", "tower.png"},
    {"sniper", "tower.png"}
};

tuple<string, float, float> TowerType::get(int i) {
    return TowerType::towers[i];
}

string TowerType::getResource(const string& name) {
    return TowerType::towerResources.at(name);
}
