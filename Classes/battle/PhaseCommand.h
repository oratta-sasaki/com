#pragma once

#include "../core/StatePhase.h"
#include "core/ActionCommand.h"

class PhaseCommand : public StatePhase {
public:
	PhaseCommand();
	~PhaseCommand();
	CREATE_FUNC(PhaseCommand);
	virtual bool init();

	virtual void start();
	virtual void action();
	virtual void command();

protected:
	// �^�[�����䂦�ɁA���̃t�F�[�Y�őS�L�����N�^�[�̍s�������肷��
	// �s���̏����͎��ɔC����
	void makeCommandAttack();
	void makeCommandDefence();
	void makeCommandEnd();

private:
	vector<ActionCommand> command_list;

};


