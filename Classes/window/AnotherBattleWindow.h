#pragma once

#include "../core/BaseWindow.h"
#include "../battle/BattleContext.h"

class AnotherBattleWindow : public BaseWindow
{
public:
	AnotherBattleWindow();
	~AnotherBattleWindow();
	static AnotherBattleWindow* create();

public:

	// ����View�̐����iDesign���g���ăQ�[���̊�b��ʂ��쐬����j
	virtual void makeView();

	// �R�}���h�҂��ɂȂ���
	virtual void commandWaiting();


private:
	BattleContext* context;


};

