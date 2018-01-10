#ifndef __SYSTEM_CORE_H__
#define __SYSTEM_CORE_H__

#include "cocos2d.h"

class SystemCore : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(SystemCore);
};

#endif // __SYSTEM_CORE_H__
