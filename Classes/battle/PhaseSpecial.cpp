#include "PhaseSpecial.h"
#include "BattleSetting.h"


PhaseSpecial::PhaseSpecial()
{
}


PhaseSpecial::~PhaseSpecial()
{
}

bool PhaseSpecial::init()
{
	return Node::init();
}

void PhaseSpecial::start()
{
	auto fealty = context->getUnitFealty();
	std::copy(fealty.begin(), fealty.end(), std::back_inserter(all_units));
	auto enemy = context->getUnitEnemy();
	std::copy(enemy.begin(), enemy.end(), std::back_inserter(all_units));

	next_step();
}

void PhaseSpecial::action()
{
}

void PhaseSpecial::command()
{
}

void PhaseSpecial::next_step()
{
	if (all_units.size() == 0){
		stateEnd(STATE_SELECT_COMMAND);
		return;
	}

	Node* unit = all_units[0];
	all_units.erase(all_units.begin());

	unit->runAction(Sequence::create(
		RotateBy::create(0.3f, -360),
		CallFunc::create([this](){ next_step(); }),
		NULL
	));
}

