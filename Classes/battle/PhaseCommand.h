#pragma once

#include "../core/StatePhase.h"
#include "core/ActionCommand.h"

class PhaseCommand : public StatePhase {
public:
	PhaseCommand();
	~PhaseCommand();
	CREATE_FUNC(PhaseCommand);
	virtual bool init();

	virtual void start();
	virtual void action();
	virtual void command();

protected:
	// ターン制ゆえに、このフェーズで全キャラクターの行動を決定する
	// 行動の処理は次に任せる
	void makeCommandAttack();
	void makeCommandDefence();
	void makeCommandEnd();

private:
	vector<ActionCommand> command_list;

};


