#pragma once

#include "../frame/settings.h"
#include "ComObserver.h"

/**
* �L�����̃X�e�[�^�X�p�����[�^�݂̂��Ǘ�����N���X
* �I�u�U�[�o�Ǘ��@�\�̍쐬���K�v�ŁA
* ���̃p�����[�^���g�p����ꍇ�ɂ́A��{�I�ɂ̓T�u�W�F�N�g���o�R���邱�Ƃ�z�肷��
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

