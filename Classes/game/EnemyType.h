#ifndef __ENEMY_TYPE_H__
#define __ENEMY_TYPE_H__

#include <tuple>
#include <map>
#include <vector>
#include <algorithm>

class EnemyType {

public:
    /** Associates the tower with an index in the vector of towers */
    constexpr static const int NORMAL = 0, KNIGHT = 1;
    /** Used when extracting information about the tower from the tuple returned
        by get.*/
    constexpr static const int SPEED = 0, HEALTH = 1, BOUNTY = 2, NAME = 3;

    static std::tuple<float, float, int, std::string> get(int i);

    static std::string getResource(const std::string& name);

    static const std::vector<std::tuple<float, float, int, std::string>> enemies;

private:
    static const std::map<std::string, std::string> enemyResources;
};

#endif
