#pragma once

#include "../frame/settings.h"
#include "ComObserver.h"

/**
* キャラのステータスパラメータのみを管理するクラス
* オブザーバ管理機能の作成が必要で、
* このパラメータを使用する場合には、基本的にはサブジェクトを経由することを想定する
*/
class UnitStatus : public ComObserver{
public:
	UnitStatus();
	~UnitStatus();

	void statusReset();
	void damage(int value);

protected:


private:
	map<StatusType, int> status_list;

};

