#pragma once

#include "../frame/settings.h"
//#include "../battle/BattleContext.h"

//class BattleContext;

class StateController : public Node {
public:
	StateController();
	~StateController();
	CREATE_FUNC(StateController);

	// ���̏�Ԃ֕ω�������
	virtual void nextState(int state, int next) {};


protected:

};



