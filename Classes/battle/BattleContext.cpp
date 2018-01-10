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

// �R�}���h����
ActionCommand makeAction(ActionCommand command, std::function<void()> method)
{
	return command;
}

#pragma mark - �@�\�E�����ݒ�
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

/// ���݃X�^�b�N����Ă���擪�̃R�}���h�����o��
ActionCommand BattleContext::getCommand()
{
	if (commands.size() == 0) return ActionCommand();

	auto cmd = commands.front();
	commands.erase(commands.begin());
	return cmd;
}
