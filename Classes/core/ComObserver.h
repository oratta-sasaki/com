#pragma once

#include "ComObserverMaster.h"

/*
* ComObserverMaster������Ŏ����Ă��āA���ׂẴf�[�^��Subject���M��Master���ŊǗ�����
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

