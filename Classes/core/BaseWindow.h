#ifndef __BASE_WINDOW_H__
#define __BASE_WINDOW_H__

#include "frame/settings.h"

class BaseWindow : public Node
{
public:
	BaseWindow();
	~BaseWindow();
	CREATE_FUNC(BaseWindow);

public:

	virtual bool init();

	// ����View�̐����iDesign���g���ăQ�[���̊�b��ʂ��쐬����j
	virtual void makeView();

	// �E�B���h�E�̊J�n����
	// ���̏������I�������Ƃ���ŁAmakeView
	virtual void start();

	// �J�n���̒ʐM����
	// �ʐM���ʂ̓V�X�e���}�l�[�W���[�̃f�[�^�֕ۑ������
	// ���̃E�B���h�E�Ŏ��s�����f�[�^�͂��̃E�B���h�E�̃|�C���^�{�f�[�^���Ŏ擾�o����
	virtual void startConnection();

	// �J�n���̃A�j���[�V��������
	virtual void startAnimation();

	// �\������Ă���View�̕\���̍X�V��Connection�Ŏ擾�������ʂȂǂ𔽉f����
	virtual void active();

	// �E�B���h�E�̃N���[�Y����
	// ���̏������I���������ŁAcloseView�Ǝ��̃E�B���h�E��start�����s�����
	virtual void close();

	// �I���A�j���[�V����
	virtual void closeAnimation();

	virtual void closeConnection();

	virtual void closeView();

	// �f�U�C���֌W��UI�ł���Ȃ�΁A�����I�ɃA�j���[�V��������̑Ώۂɂ���
	// ���̋@�\�𗘗p���鎖�ɂ����
	// startAnimation, closeAnimation�͂قڋC�ɂ��Ȃ��Ă������悤�ɂȂ�
	// add��remove�̎��_�ŃA�j���[�V�������邩�ǂ����͖�����
//	virtual void addChild();




};

#endif // __BASE_WINDOW_H__
