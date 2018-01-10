#pragma once

#include "../frame/settings.h"

/**
* cocos系のActionを複数実行するときに、
* 全てのActionを終了したかどうかを監視することを目的としたクラス
*/
class ActionObserver : public Node {
public:
	ActionObserver();
	virtual ~ActionObserver();
	static ActionObserver* create();
	static ActionObserver* create(std::function<void()> callfunc_method);
	virtual bool init(std::function<void()> callfunc_method);

	/// イベントを登録する
	void registObject(Ref* _node);
	/// イベントを終了とする
	void unregist(Ref* _node);
	/// イベントを全てキャンセルする
	void cancelObserver();

	/// 終了イベントのコールファンクを登録
	void setEndCallFunc(std::function<void()> callfunc_method);
	/// 終了イベントを呼び出す為のファンクションを呼び出す
	ActionInstant* getUnregistAction();

private:
	/// 現在実行中と判断されるオブジェクト
	std::vector<void*> event_flg_;

	/// 全オブジェクト終了時のコールバック
	std::function<void(void)> method_;

};



