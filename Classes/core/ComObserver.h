#pragma once

#include "ComObserverMaster.h"

/*
* ComObserverMasterを内部で持っていて、すべてのデータのSubject発信はMaster側で管理する
*/
class ComObserver
{
public:
	ComObserver();
	~ComObserver();

	void regist(void* responsible, int key, ComSubject method);
	void unregist(void* responsible);
	void unregist(void* responsible, int key);

	void setStatus(int key, int value);
	void addStatus(int key, int value);

private:

};

