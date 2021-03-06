#pragma once

#include "core/StateController.h"
#include "BattleContext.h"

class BattleController : public StateController {
public:
	BattleController();
	virtual ~BattleController();
	CREATE_FUNC(BattleController);

	void execute(BattleContext* context);

	// 次の状態へ変化させる
	virtual void nextState(int state, int next);

	virtual void setState(StatePhase* state);

	virtual void nextState();

protected:
	BattleContext* context_;
	StatePhase* now_state;
	int now_id;



};