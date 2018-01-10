#pragma once

#include "lib/com_include.h"

/// �p�����[�^�X�V�����������Ƃ��ɁA�ύX�ʒm���󂯎��
typedef std::function<void(int)> ComSubject;
/// �p�����[�^�X�V���̃��[���i���l�̉�������Ȃǁj
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
	// �X�V�𔽉f����
	void update(void* obj, int key, SubjectTarget subject);

private:
	// �Ή��N���X�A�L�[�A�T�u�W�F�N�g�f�[�^(ComSubject�A�Ǘ��҃|�C���^)
	map<void*, map<int, vector<SubjectTarget> > > subjects;
	// �Ή��N���X�A�L�[�A�p�����[�^�i���l�A������A�ύX���Ɏ��s���郁�\�b�h�j
	map<void*, map<int, ParamData> > params;

};

