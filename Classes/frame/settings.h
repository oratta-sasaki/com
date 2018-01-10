#pragma once

#include "cocos2d.h"
#include "lib/com_include.h"

using namespace cocos2d;

#define SYSTEM_FRAME_RATE 60
#define SYSTEM_WINDOW_WIDTH 800
#define SYSTEM_WINDOW_HEIGHT 600

#define SCREEN_SIZE (Director::getInstance()->getVisibleSize())



#define IMG_HELLO "HelloWorld.png"

#define TEXT_HELLO "test world. v2"

#define ICON_FEALTY "ui/box_green.png"
#define ICON_ENEMY  "ui/box_red.png"

#define ICON_BTN		"ui/circle_green.png"
#define ICON_BTN_PRESS	"ui/circle_orange.png"

#define SKILL_SWORD "item/sword_silver.png"


enum StatusType {
	statusHP = 0x01001000,
	statusATC,
	statusDEF,
	statusSPD,


} ;

enum ActionCommandCode {
	CMD_ATTACK = 0x02001001,
	CMD_RAND_ATTACK,
	CMD_ATTACK_SP1,

};




