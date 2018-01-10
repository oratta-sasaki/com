#pragma once

#include "../frame/settings.h"
#include "../core/StatePhase.h"
#include "../core/ActionCommand.h"
#include "../core/BattleUnit.h"

class StatePhase;

class BattleContext : public Node {
public:
	BattleContext();
	~BattleContext();
	static BattleContext* create(const std::function<void()> &ref);
	virtual bool init();

// ** �@�\�E�����ݒ�
	void addFealty(vector<BattleUnit*> fealty);
	void addEnemy(vector<BattleUnit*> enemy);

	// ���j�b�g�ւ̃A�N�Z�X
	vector<BattleUnit*> getUnitFealty() { return fealty; };
	vector<BattleUnit*> getUnitEnemy() { return enemy; };
	// �R�}���h�o�^�n
	void setCommand(vector<ActionCommand> command_list){ commands = command_list; };
	void clearCommand() { commands.clear(); };
	/// ���݃X�^�b�N����Ă���擪�̃R�}���h�����o��
	ActionCommand getCommand();

private:
	std::function<void()> commandDelegate;
//	Node* layer;
	StatePhase* phase;

	vector<BattleUnit*> fealty;
	vector<BattleUnit*> enemy;
	vector<ActionCommand> commands;

};


