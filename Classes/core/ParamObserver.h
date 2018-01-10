#pragma once

#include "frame/settings.h"

class ParamObserver
{
	// 設計未定
	// オブザーバとしての登録と管理、
	// そのあたりができるだけ簡単に使えるようになる形の決定
public:
	static ParamObserver* getInstance();
	ParamObserver();
	~ParamObserver();

//	void regist(void* pointer, std::function<void(int)> callback);

protected:

private:
//	map<void*, 


};







