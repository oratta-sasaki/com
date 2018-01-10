#pragma once

#include "../core/StatePhase.h"
#include "../lib/ActionObserver.h"

class PhaseAction : public StatePhase {
public:
	PhaseAction();
	~PhaseAction();
	CREATE_FUNC(PhaseAction);

	virtual void start();
	virtual void command();

protected:
	void next_step();

	void useAttack(BattleUnit* unit);
	void useDefence(BattleUnit* unit);

private:
	ActionObserver* observer_;

};
