#pragma once

#include "../core/StatePhase.h"
#include "../lib/ActionObserver.h"

class PhaseInit : public StatePhase {
public:
	PhaseInit();
	~PhaseInit();
	CREATE_FUNC(PhaseInit);
	virtual bool init();

	virtual void start();

private:
	ActionObserver* observer_;

};


