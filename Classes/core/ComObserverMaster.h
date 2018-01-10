#pragma once

#include "lib/com_include.h"

/// パラメータ更新が発生したときに、変更通知を受け取る
typedef std::function<void(int)> ComSubject;
/// パラメータ更新時のルール（数値の下限上限など）
typedef std::function<int(int)> ParamMethod;

struct SubjectTarget {
	void* responser;
	ComSubject subject;
	SubjectTarget(void* obj, ComSubject method) :responser(obj), subject(method){};
};

struct ParamData {
private:
	int value;
	ParamMethod func;
public:
	ParamData(int var=0, ParamMethod method=NULL) :value((method) ? method(var) : var), func(method){}

	ParamData operator=(int v){
		return value = (func) ? func(v) : (v);
	}
	ParamData operator+=(int v){
		return value = (func) ? func(value + v) : (value + v);
	}
	operator int() {
		return value;
	}
};

class ComObserverMaster
{
	ComObserverMaster();
	~ComObserverMaster();
public:
	static ComObserverMaster* getInstance();

	void set(void* obj, int key, int value);
	void add(void* obj, int key, int value);
	int get(void* obj, int key);

	void regist(void* obj, int key, SubjectTarget subject);
	void unregist(void* obj, void* responser);
	void unregist(void* obj, void* responser, int key);

	void remove(void* obj);

protected:
//	void update();
	// 更新を反映する
	void update(void* obj, int key, SubjectTarget subject);

private:
	// 対応クラス、キー、サブジェクトデータ(ComSubject、管理者ポインタ)
	map<void*, map<int, vector<SubjectTarget> > > subjects;
	// 対応クラス、キー、パラメータ（数値、文字列、変更時に実行するメソッド）
	map<void*, map<int, ParamData> > params;

};

