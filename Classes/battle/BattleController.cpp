#include "BattleController.h"
#include "BattleSetting.h"
#include "PhaseInit.h"
#include "PhaseCommand.h"
#include "PhaseExecute.h"
#include "PhaseEnd.h"
#include "PhaseSpecial.h"
#include "PhaseAction.h"

BattleController::BattleController() :
	now_state(NULL)
{

}

BattleController::~BattleController() 
{

}

void BattleController::execute(BattleContext* context)
{
	context_ = context;
	nextState(0, STATE_BATTLE_START);
}


// ŽŸ‚Ìó‘Ô‚Ö•Ï‰»‚³‚¹‚é
void BattleController::nextState(int state, int next) 
{
	switch (next) {
	case STATE_BATTLE_START:
		setState(PhaseInit::create());
		break;
	case STATE_SELECT_COMMAND:
		setState(PhaseCommand::create());
		break;
	case STATE_BATTLE_ACTIVE:
		setState(PhaseExecute::create());
		break;
	case STATE_SPECIAL_ACTIVE:
		setState(PhaseSpecial::create());
		break;
	case STATE_BATTLE_END:
		setState(PhaseEnd::create());
		break;
	case STATE_COMMAND_ACTION:
		setState(PhaseAction::create());
		break;
	default:
		break;
	}



}

void BattleController::setState(StatePhase* state)
{
	if (now_state) {
		now_state->removeFromParent();
	}
	now_state = state;
	addChild(now_state);
	now_state->execute(context_, [this]() { this->nextState(); });
}

void BattleController::nextState()
{
	auto next = now_state->getNext();
	nextState(now_id, next);
	now_id = next;
}

