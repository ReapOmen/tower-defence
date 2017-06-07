#ifndef __TOWER_SELECTOR_H__
#define __TOWER_SELECTOR_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "game/TowerType.h"
#include "LevelScene.h"

class TowerSelector : public cocos2d::ui::ListView {

public:

    static TowerSelector* create(const cocos2d::Vec2& pos);

    void initOptions(const cocos2d::Vec2& pos);

    void show();

    void hide();

private:

    void setOpacityForAll(GLubyte val);

    void action(Ref* sender, Widget::TouchEventType type);
};
#endif
