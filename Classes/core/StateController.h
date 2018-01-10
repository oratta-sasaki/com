#pragma once

#include "../frame/settings.h"
//#include "../battle/BattleContext.h"

//class BattleContext;

class StateController : public Node {
public:
	StateController();
	~StateController();
	CREATE_FUNC(StateController);

	// Ÿ‚Ìó‘Ô‚Ö•Ï‰»‚³‚¹‚é
	virtual void nextState(int state, int next) {};


protected:

};



