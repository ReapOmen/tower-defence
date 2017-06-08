#include "TowerType.h"
#include "cocos2d.h"
using std::tuple;
using std::vector;
using std::map;
using std::string;

const vector<tuple<float, float, int, string>> TowerType::towers = {
    std::make_tuple(40.0f, 8.0f, 20, "regular"),
    std::make_tuple(60.0f, 10.0f, 30, "sniper")
};

const map<string, string> TowerType::towerResources = {
    {"regular", "tower.png"},
    {"sniper", "tower.png"}
};

tuple<float, float, int, string> TowerType::get(int i) {
    return TowerType::towers[i];
}

string TowerType::getResource(const string& name) {
    return TowerType::towerResources.at(name);
}
