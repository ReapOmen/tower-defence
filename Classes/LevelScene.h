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

class TowerSelector;

class LevelScene : public cocos2d::Layer {

public:

    static cocos2d::Scene* createScene();

    bool init();

    void addTower(int i);

    CREATE_FUNC(LevelScene);

private:

    SelectableSprite* _selected;

    std::unique_ptr<Level> _level;

    TowerSelector* _selector;

    std::vector<TowerSprite*> _towers;

    void addEvents();
};

#endif
