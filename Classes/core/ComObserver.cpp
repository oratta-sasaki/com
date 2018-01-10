#include "ComObserver.h"


ComObserver::ComObserver()
{
}

ComObserver::~ComObserver()
{
}

void ComObserver::regist(void* responsible, int key, ComSubject method)
{
	ComObserverMaster::getInstance()->regist(this, key, SubjectTarget(responsible, method));
}

void ComObserver::unregist(void* responsible)
{
	ComObserverMaster::getInstance()->unregist(this, responsible);
}

void ComObserver::unregist(void* responsible, int key)
{
	ComObserverMaster::getInstance()->unregist(this, responsible, key);
}

void ComObserver::setStatus(int key, int value)
{
	ComObserverMaster::getInstance()->set(this, key, value);
}

void ComObserver::addStatus(int key, int value)
{
	ComObserverMaster::getInstance()->add(this, key, value);
}
