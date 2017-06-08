#ifndef __TOWER_TYPE_H__
#define __TOWER_TYPE_H__

#include <tuple>
#include <map>
#include <algorithm>

class TowerType {

public:
    /** Associates the tower with an index in the vector of towers */
    constexpr static const int NORMAL = 0, SNIPER = 1;
    /** Used when extracting information about the tower from the tuple returned
        by get.*/
    constexpr static const int RANGE = 0, ATTACK = 1, COST = 2, NAME = 3;

    static std::tuple<float, float, int, std::string> get(int i);

    static std::string getResource(const std::string& name);

    static const std::vector<std::tuple<float, float, int, std::string>> towers;

private:
    static const std::map<std::string, std::string> towerResources;
};

#endif
