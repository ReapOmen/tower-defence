#ifndef __LEVEL_SCENE_H__
#define __LEVEL_SCENE_H__

#include <memory>
#include <vector>
#include "cocos2d.h"
#include "sprites/SelectableSprite.h"
#include "sprites/TowerSprite.h"
#include "widgets/TowerSelector.h"
#include "game/Level.h"
#include "game/TowerType.h"
#include "game/Tower.h"
#include "sprites/TowerSprite.h"
#include "utils/Listener.h"

class TowerSelector;

class LevelScene : public cocos2d::Layer, public Listener {

public:
    static cocos2d::Scene* createScene();

    bool init();

    void addTower(int i);

    void update(float dt) override;

    void notify(std::string message) override;

    CREATE_FUNC(LevelScene);

private:
    SelectableSprite* _selected;

    std::unique_ptr<Level> _level;

    TowerSelector* _selector;

    void addEvents();

    void initMap();
};

#endif
