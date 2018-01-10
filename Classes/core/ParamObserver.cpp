#include "ParamObserver.h"


ParamObserver* ParamObserver::getInstance()
{
	static ParamObserver observer;
	return &observer;
}

ParamObserver::ParamObserver()
{
}


ParamObserver::~ParamObserver()
{
}
