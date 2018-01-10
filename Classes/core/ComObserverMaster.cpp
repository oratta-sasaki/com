#include "ComObserverMaster.h"


ComObserverMaster::ComObserverMaster()
{
}

ComObserverMaster::~ComObserverMaster()
{
}

ComObserverMaster* ComObserverMaster::getInstance()
{
	static ComObserverMaster observer;
	return &observer;
}

void ComObserverMaster::set(void* obj, int key, int value)
{
	params[obj][key] = value;
	for (auto sub : subjects[obj][key]){
		sub.subject(params[obj][key]);
	}
}

void ComObserverMaster::add(void* obj, int key, int value)
{
	params[obj][key] += value;
	for (auto sub : subjects[obj][key]){
		sub.subject(params[obj][key]);
	}
}

int ComObserverMaster::get(void* obj, int key)
{
	return params[obj][key];
}

void ComObserverMaster::regist(void* obj, int key, SubjectTarget subject)
{
	subjects[obj][key].push_back(subject);
	// 値を反映する
	update(obj, key, subject);
	
}

void ComObserverMaster::unregist(void* obj, void* responser)
{
	for (auto key_target : subjects[obj]){
		for (auto data : key_target.second){
			if (data.responser == responser){
				// remove
			}
		}
	}
}

void ComObserverMaster::unregist(void* obj, void* responser, int key)
{
	for (auto data : subjects[obj][key]){
		if (data.responser == responser){
			// remove
		}
	}
}

void ComObserverMaster::remove(void* obj)
{
	// これに関するデータをすべて消す

}

// 更新を反映する
void ComObserverMaster::update(void* obj, int key, SubjectTarget subject)
{
	if (params.count(obj) == 0) return;
	if (params[obj].count(key) == 0) return;
	if (subject.subject == NULL) return;
	subject.subject(params[obj][key]);

}


