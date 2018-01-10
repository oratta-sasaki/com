#include "PhaseCommand.h"
#include "BattleSetting.h"

PhaseCommand::PhaseCommand()
{

}

PhaseCommand::~PhaseCommand()
{

}

bool PhaseCommand::init()
{
	return Node::init();
}

void PhaseCommand::start()
{
	auto menu = Menu::create();

	auto btn1 = MenuItemImage::create(ICON_BTN, ICON_BTN_PRESS, [menu,this](Ref* ref) {
		menu->removeFromParent();
		this->makeCommandAttack();
	});
	btn1->setPosition(0, 0);
	menu->addChild(btn1);

	auto btn2 = MenuItemImage::create(ICON_BTN, ICON_BTN_PRESS, [menu,this](Ref* ref) {
		menu->removeFromParent();
		this->makeCommandDefence();
	});
	btn2->setPosition(60, 0);
	menu->addChild(btn2);

	auto btn3 = MenuItemImage::create(ICON_BTN, ICON_BTN_PRESS, [menu,this](Ref* ref) {
		menu->removeFromParent();
		this->makeCommandEnd();
	});
	btn3->setPosition(120, 0);
	menu->addChild(btn3);

	menu->setPosition(ccp(20,20) + btn1->getContentSize()/2);
	context->addChild(menu);
}

void PhaseCommand::action()
{
}

void PhaseCommand::command()
{
}

void PhaseCommand::makeCommandAttack()
{
	for (auto unit : context->getUnitFealty()) {
		command_list.push_back(ActionCommand(unit, COMMAND_ATTACK));
	}
	for (auto unit : context->getUnitEnemy()) {
		command_list.push_back(ActionCommand(unit, COMMAND_ATTACK));
	}
	context->setCommand(command_list);
	this->stateEnd(STATE_BATTLE_ACTIVE);
}

void PhaseCommand::makeCommandDefence()
{
	for (auto unit : context->getUnitFealty()) {
		command_list.push_back(ActionCommand(unit, COMMAND_DEFENCE));
	}
	for (auto unit : context->getUnitEnemy()) {
		command_list.push_back(ActionCommand(unit, COMMAND_ATTACK));
	}
	this->stateEnd(STATE_SPECIAL_ACTIVE);
}

void PhaseCommand::makeCommandEnd()
{
	context->setCommand(command_list);
	this->stateEnd(STATE_BATTLE_END);
}

