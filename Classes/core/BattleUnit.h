#pragma once

#include "../frame/settings.h"
#include "UnitStatus.h"

/*
* �L�����N�^�[��������Node
* �X�e�[�^�X���͕ێ����邱��
*/
class BattleUnit:public Node{
public:
	BattleUnit();
	~BattleUnit();
	static BattleUnit* createAlly();
	static BattleUnit* createEnemy();

	virtual bool init();

	bool isAlly();
	void damage(int value);

protected:
	void makeView(string data, bool ally);

private:
	UnitStatus* status;
	LabelTTF* hp_label;
	bool is_ally;


};

