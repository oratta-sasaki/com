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

// ** 機能・挙動設定
	void addFealty(vector<BattleUnit*> fealty);
	void addEnemy(vector<BattleUnit*> enemy);

	// ユニットへのアクセス
	vector<BattleUnit*> getUnitFealty() { return fealty; };
	vector<BattleUnit*> getUnitEnemy() { return enemy; };
	// コマンド登録系
	void setCommand(vector<ActionCommand> command_list){ commands = command_list; };
	void clearCommand() { commands.clear(); };
	/// 現在スタックされている先頭のコマンドを取り出す
	ActionCommand getCommand();

private:
	std::function<void()> commandDelegate;
//	Node* layer;
	StatePhase* phase;

	vector<BattleUnit*> fealty;
	vector<BattleUnit*> enemy;
	vector<ActionCommand> commands;

};


