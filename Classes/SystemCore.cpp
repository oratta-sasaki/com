#include "SystemCore.h"
#include "SimpleAudioEngine.h"
#include "frame/settings.h"
#include "core/BaseWindow.h"
#include "window/AnotherBattleWindow.h"

USING_NS_CC;

Scene* SystemCore::createScene()
{
	return SystemCore::create();
}

// on "init" you need to initialize your instance
bool SystemCore::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

//	auto window = BaseWindow::create();
	auto window = AnotherBattleWindow::create();
	this->addChild(window);

	return true;
}


void SystemCore::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
