#pragma once

#include "../frame/settings.h"
//#include "../battle/BattleContext.h"

//class BattleContext;

class StateController : public Node {
public:
	StateController();
	~StateController();
	CREATE_FUNC(StateController);

	// 次の状態へ変化させる
	virtual void nextState(int state, int next) {};


protected:

};



