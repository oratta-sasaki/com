#include "PhaseEnd.h"
#include "BattleSetting.h"

PhaseEnd::PhaseEnd()
{

}

PhaseEnd::~PhaseEnd()
{

}

bool PhaseEnd::init()
{
	return Node::init();
}

void PhaseEnd::start()
{
	observer_ = ActionObserver::create([this]() { viewEndButton(); });
	this->addChild(observer_);

	float add_delay = 0.04f;
	float delay = 0;

	for (auto unit : context->getUnitEnemy()) {
		unit->runAction(Sequence::create(
			DelayTime::create(delay),
			FadeTo::create(0.3f, 0),
			observer_->getUnregistAction(),
			NULL
		));
		observer_->registObject(unit);

		delay += add_delay;
	}

}

void PhaseEnd::action()
{
}

void PhaseEnd::command()
{
}

void PhaseEnd::viewEndButton()
{
	auto menu = Menu::create();

	auto btn1 = MenuItemImage::create(ICON_BTN, ICON_BTN_PRESS, [menu, this](Ref* ref) {
		menu->removeFromParent();
		this->stateEnd(STATE_BATTLE_START);
	});
	btn1->setPosition(0, 0);
	menu->addChild(btn1);

	menu->setPosition(SCREEN_SIZE/2);
	context->addChild(menu);

}

