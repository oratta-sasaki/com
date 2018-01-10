#include "BattleUnit.h"



BattleUnit::BattleUnit()
{
}

BattleUnit::~BattleUnit()
{
	if (status){
		status->unregist(this);	// Ó”CÒŒ ŒÀ‚ÅƒIƒuƒU[ƒo‚ğíœ‚·‚é
		CC_SAFE_DELETE(status);
	}
}

BattleUnit* BattleUnit::createAlly()
{
	auto ret = new BattleUnit();
	if (ret && ret->init()){
		ret->makeView(ICON_FEALTY,true);
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}

BattleUnit* BattleUnit::createEnemy()
{
	auto ret = new BattleUnit();
	if (ret && ret->init()){
		ret->makeView(ICON_ENEMY,false);
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}

bool BattleUnit::init()
{
	if (!Node::init()) return false;

	status = new UnitStatus();
	status->setStatus(statusHP, 100);
	status->setStatus(statusATC, 11);

	return true;
}

void BattleUnit::makeView(string data, bool ally)
{
	is_ally = ally;
	auto image = Sprite::create(data);
	addChild(image);

	hp_label = LabelTTF::create("0", "Align", 20);
	if (ally){
		hp_label->setPosition(ccp(0, 10));
	}else{
		hp_label->setPosition(ccp(image->getContentSize().width, 10));
	}
	image->addChild(hp_label);

	// observer‚É“o˜^‚·‚é
	auto hp = hp_label;
	status->regist(this, statusHP, [hp](int value){ hp->setString(to_string(value)); });
}

bool BattleUnit::isAlly()
{
	return is_ally;
}

void BattleUnit::damage(int damage)
{
	status->addStatus(statusHP, -damage);
}


