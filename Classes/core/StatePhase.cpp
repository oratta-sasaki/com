#include "StatePhase.h"

StatePhase::StatePhase()
{

}

StatePhase::~StatePhase()
{

}

void StatePhase::execute(BattleContext* context, std::function<void()> method)
{
	this->context = context;
	this->end_method = method;
	start();
}

void StatePhase::stateEnd(int next)
{
	this->next = next;
	end_method();
}
