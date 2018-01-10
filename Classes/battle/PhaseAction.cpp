#include "PhaseAction.h"
#include "BattleSetting.h"

PhaseAction::PhaseAction()
{
}

PhaseAction::~PhaseAction()
{
}

void PhaseAction::start()
{
	observer_ = ActionObserver::create([this]() { stateEnd(STATE_SELECT_COMMAND); });
	this->addChild(observer_);

	next_step();
}

void PhaseAction::command()
{

}

void PhaseAction::next_step()
{
	auto cmd = context->getCommand();

	switch (cmd.command){
	case 0:
		stateEnd(STATE_SELECT_COMMAND);
		break;
	case COMMAND_ATTACK:
		useAttack(cmd.attacker);
		break;
	case COMMAND_DEFENCE:
		useDefence(cmd.attacker);
		break;
	}
}

void PhaseAction::useAttack(BattleUnit* unit)
{
	Node* target;
	if (unit->isAlly()){
		auto list = context->getUnitEnemy();
		std::random_shuffle(list.begin(), list.end());
		target = list[0];
	}else{
		auto list = context->getUnitFealty();
		std::random_shuffle(list.begin(), list.end());
		target = list[0];
	}

	auto img = Sprite::create(SKILL_SWORD);
	img->setPosition(unit->getPosition());
	unit->getParent()->addChild(img, unit->getZOrder());

	img->runAction(Sequence::create(
		MoveTo::create(0.5f, target->getPosition()),
		CallFunc::create([target, this]()
	{
		if (auto bu = dynamic_cast< BattleUnit* >(target)){
			bu->damage(4);
		}
		next_step();
	}),
		CallFuncN::create([](Node* node){
		node->removeFromParent();
	}),
		DelayTime::create(0.5f),
		NULL
		));

}
void PhaseAction::useDefence(BattleUnit* unit)
{
	unit->runAction(Sequence::create(
		RotateTo::create(0.4f, 360),
		CallFunc::create([this](){ this->next_step();  }),
		NULL
	)
	);
}

