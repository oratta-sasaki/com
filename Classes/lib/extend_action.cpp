#include "extend_action.h"

CallFuncParent::CallFuncParent()
{
}

CallFuncParent::~CallFuncParent()
{
}

void CallFuncParent::execute()
{
	if (_callFuncO)
	{
		(_selectorTarget->*_callFuncO)(_target);
	}
}

CallFuncParent * CallFuncParent::create(Ref* selectorTarget, SEL_CallFuncO selector)
{
	CallFuncParent *ret = new (std::nothrow) CallFuncParent();

	if (ret && ret->initWithTarget(selectorTarget, selector))
	{
		ret->autorelease();
		return ret;
	}

	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool CallFuncParent::initWithTarget(Ref* selectorTarget, SEL_CallFuncO selector)
{
	if (CallFunc::initWithTarget(selectorTarget))
	{
		_callFuncO = selector;
		return true;
	}

	return false;
}

CallFuncParent * CallFuncParent::clone() const
{
	// no copy constructor
	auto a = new (std::nothrow) CallFuncParent();

	if (_selectorTarget)
	{
		a->initWithTarget(_selectorTarget, _callFuncO);
	}

	a->autorelease();
	return a;
}

