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

	// 初期Viewの生成（Designを使ってゲームの基礎画面を作成する）
	virtual void makeView();

	// コマンド待ちになった
	virtual void commandWaiting();


private:
	BattleContext* context;


};

