#pragma once

#include "frame/settings.h"
#include "core/BattleUnit.h"

class ActionCommand{
public:	// 機能ができるまで自由アクセス
	BattleUnit* attacker;
	int command;

public:
	ActionCommand(BattleUnit* attacker, int command) :attacker(attacker), command(command){};
	ActionCommand() : command(0){};
	~ActionCommand(){};
};

