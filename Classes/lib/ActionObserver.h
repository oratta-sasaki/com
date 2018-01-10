#pragma once

#include "../frame/settings.h"

/**
* cocos�n��Action�𕡐����s����Ƃ��ɁA
* �S�Ă�Action���I���������ǂ������Ď����邱�Ƃ�ړI�Ƃ����N���X
*/
class ActionObserver : public Node {
public:
	ActionObserver();
	virtual ~ActionObserver();
	static ActionObserver* create();
	static ActionObserver* create(std::function<void()> callfunc_method);
	virtual bool init(std::function<void()> callfunc_method);

	/// �C�x���g��o�^����
	void registObject(Ref* _node);
	/// �C�x���g���I���Ƃ���
	void unregist(Ref* _node);
	/// �C�x���g��S�ăL�����Z������
	void cancelObserver();

	/// �I���C�x���g�̃R�[���t�@���N��o�^
	void setEndCallFunc(std::function<void()> callfunc_method);
	/// �I���C�x���g���Ăяo���ׂ̃t�@���N�V�������Ăяo��
	ActionInstant* getUnregistAction();

private:
	/// ���ݎ��s���Ɣ��f�����I�u�W�F�N�g
	std::vector<void*> event_flg_;

	/// �S�I�u�W�F�N�g�I�����̃R�[���o�b�N
	std::function<void(void)> method_;

};



