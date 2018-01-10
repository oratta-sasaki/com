#pragma once

#include "../core/StatePhase.h"

class PhaseSpecial:public StatePhase{
public:
	PhaseSpecial();
	~PhaseSpecial();
	CREATE_FUNC(PhaseSpecial);
	virtual bool init();

	virtual void start();
	virtual void action();
	virtual void command();

protected:
	void next_step();

private:
	vector<CCNode*> all_units;
};

