#pragma once

#include "../frame/settings.h"
#include "../battle/BattleContext.h"

class BattleContext;

class StatePhase : public Node{
public:
	StatePhase();
	~StatePhase();
	CREATE_FUNC(StatePhase);

	virtual void execute(BattleContext* context, std::function<void()> method);
	int getNext() { return next; };

protected:

	virtual void start() {};
	virtual void action() {};
	virtual void command() {};

	virtual void stateEnd(int next);

protected:
	BattleContext* context;
	std::function<void()> end_method;
	int next;

};



