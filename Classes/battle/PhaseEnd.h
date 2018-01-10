#pragma once

#include "../core/StatePhase.h"
#include "../lib/ActionObserver.h"

class PhaseEnd : public StatePhase {
public:
	PhaseEnd();
	~PhaseEnd();
	CREATE_FUNC(PhaseEnd);
	virtual bool init();

	virtual void start();
	virtual void action();
	virtual void command();

protected:
	virtual void viewEndButton();

private:
	ActionObserver* observer_;

};


