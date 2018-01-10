#pragma once
#include "../frame/settings.h"

class CallFuncParent : public CallFunc
{
public:
	static CallFuncParent * create(Ref* target, SEL_CallFuncO selector);
	//
	// Overrides
	//
	virtual CallFuncParent* clone() const override;
	virtual void execute() override;

	CallFuncParent();
	virtual ~CallFuncParent();
	bool initWithTarget(Ref* target, SEL_CallFuncO selector);

protected:
	SEL_CallFuncO _callFuncO;

};

