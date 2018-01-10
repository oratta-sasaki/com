#include "PhaseInit.h"
#include "BattleSetting.h"

PhaseInit::PhaseInit():
	observer_()
{
}

PhaseInit::~PhaseInit()
{

}

bool PhaseInit::init()
{
	return Node::init();
}

void PhaseInit::start()
{
	observer_ = ActionObserver::create([this]() { stateEnd(STATE_SELECT_COMMAND); });
	this->addChild(observer_);

	auto move = Point(SCREEN_SIZE.width / 3, 0);
	float add_delay = 0.14f;

	auto fealty_pos = Point(-50, SCREEN_SIZE.height - 50);
	float delay = 0;

	for (auto unit : context->getUnitFealty()) {
		unit->setOpacity(255);
		unit->setVisible(true);
		unit->setPosition(fealty_pos);
		unit->runAction(Sequence::create(
			DelayTime::create(0.4f + delay),
			MoveBy::create(0.6, move),
			observer_->getUnregistAction(),
			NULL
		));
		observer_->registObject(unit);

		fealty_pos -= Point(0, 70);
		delay += add_delay;
	}

	auto enemy_pos = Point(SCREEN_SIZE.width + 50, SCREEN_SIZE.height - 50);
	delay = 0;
	for (auto unit : context->getUnitEnemy()) {
		unit->setOpacity(255);
		unit->setVisible(true);
		unit->setPosition(enemy_pos);
		unit->runAction(Sequence::create(
			DelayTime::create(0.3f + delay),
			MoveBy::create(0.6, move*-1),
			observer_->getUnregistAction(),
			NULL
		));
		observer_->registObject(unit);

		enemy_pos -= Point(0, 70);
		delay += add_delay;
	}
}

