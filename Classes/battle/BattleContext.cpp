#include "BattleContext.h"

BattleContext::BattleContext()
{

}

BattleContext::~BattleContext()
{

}

BattleContext* BattleContext::create(const std::function<void()> &ref)
{
	auto ret = new BattleContext();
	if (ret && ret->init()) {
		ret->autorelease();
		ret->commandDelegate = ref;
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}


bool BattleContext::init()
{
	return Node::init();
}

// コマンド生成
ActionCommand makeAction(ActionCommand command, std::function<void()> method)
{
	return command;
}

#pragma mark - 機能・挙動設定
//void BattleContext::setLayer(Node* _layer)
//{
//	this->layer = _layer;
//}

void BattleContext::addFealty(vector<BattleUnit*> fealty)
{
	this->fealty = fealty;
}

void BattleContext::addEnemy(vector<BattleUnit*> enemy)
{
	this->enemy = enemy;
}

/// 現在スタックされている先頭のコマンドを取り出す
ActionCommand BattleContext::getCommand()
{
	if (commands.size() == 0) return ActionCommand();

	auto cmd = commands.front();
	commands.erase(commands.begin());
	return cmd;
}
