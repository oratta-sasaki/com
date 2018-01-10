#pragma once

#include "../core/StatePhase.h"
#include "../core/EventAction.h"
#include "../core/ActionCommand.h"

class PhaseExecute : public StatePhase {
public:
	PhaseExecute();
	~PhaseExecute();
	CREATE_FUNC(PhaseExecute);
	virtual bool init();

	virtual void start();
	virtual void action();
	virtual void command();

protected:
	void next_step();

private:
//	vector<ActionCommand> all_action;

};


