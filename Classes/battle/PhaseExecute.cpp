#include "PhaseExecute.h"
#include "BattleSetting.h"
#include "core/BattleUnit.h"

PhaseExecute::PhaseExecute()
{
}

PhaseExecute::~PhaseExecute()
{
}

bool PhaseExecute::init()
{
	if(Node::init() == false) return false;
	return true;
}

void PhaseExecute::start()
{
	next_step();
}

void PhaseExecute::action()
{
}

void PhaseExecute::command()
{
}

void PhaseExecute::next_step()
{
	auto act = context->getCommand();
	if (act.command == 0){
		stateEnd(STATE_SELECT_COMMAND);
		return;
	}

	Node* attacker = act.attacker;
	Node* target = NULL;

	// ターゲットのルールとかが出来上がっていないので、それを大雑把に作成する
	if (act.command == 1){
		auto list = context->getUnitEnemy();
		std::random_shuffle(list.begin(), list.end());
		target = list[0];
	} else if (act.command == 2){
		auto list = context->getUnitEnemy();
		std::random_shuffle(list.begin(), list.end());
		target = list[0];
	}else if (act.command == COMMAND_ATTACK){
		auto list = context->getUnitEnemy();
		std::random_shuffle(list.begin(), list.end());
		target = list[0];

	}else if (act.command == COMMAND_DEFENCE){
		auto list = context->getUnitEnemy();
		std::random_shuffle(list.begin(), list.end());
		target = list[0];

	}

	auto img = Sprite::create(SKILL_SWORD);
	img->setPosition(attacker->getPosition());
	target->getParent()->addChild(img, attacker->getZOrder());

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


	/*
	auto act = all_action[0];
	all_action.erase(all_action.begin());

	auto actionNode = context->makeAction(act, [this](){ this->next_step(); });
	addChild(actionNode);

	auto action = ActionCommand::createNormalAttack(context, unit.unit, unit.target);
	unit.unit->getParent()->addChild(action);
	action->start();

	Node* attacker = unit.unit;
	// 対象を決定する
	Node* target = NULL;
	if (unit.target == 1){
		auto list = context->getUnitEnemy();
		std::random_shuffle(list.begin(), list.end());
		target = list[0];
	} else if (unit.target == 2){
		auto list = context->getUnitFealty();
		std::random_shuffle(list.begin(), list.end());
		target = list[0];
	}
	
	auto img = Sprite::create(SKILL_SWORD);
	img->setPosition(attacker->getPosition());
	unit.unit->getParent()->addChild(img, attacker->getZOrder());

	img->runAction(Sequence::create(
		MoveTo::create(0.5f, target->getPosition()),
		CallFunc::create([target,this]()
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
	*/
}

