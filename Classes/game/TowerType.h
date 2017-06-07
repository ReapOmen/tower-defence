#ifndef __TOWER_TYPE_H__
#define __TOWER_TYPE_H__

#include <tuple>
#include <map>
#include <algorithm>

class TowerType {

public:
    constexpr static const int NORMAL = 0, SNIPER = 1;
    static std::tuple<std::string, float, float> get(int i);
    static std::string getResource(const std::string& name);
    static const std::vector<std::tuple<std::string, float, float>> towers;

private:
    static const std::map<std::string, std::string> towerResources;
};

#endif
