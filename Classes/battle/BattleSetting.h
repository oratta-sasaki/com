#pragma once

/// ���
// �Q�[���J�n���o�i�L�����o��`�o��I���܂Łj 
#define STATE_BATTLE_START		0x0001
// �L�����̍s���I�������肷��
#define STATE_SELECT_COMMAND		0x0002
// �o�g�������i�s�����ɃL�����s�������s����j
#define STATE_BATTLE_ACTIVE		0x0003
// �o�g���I���i�S��or�������o���s���j
#define STATE_BATTLE_END			0x0004
// �K�E���[�h�i�R�}���h���͂ƃL�����s���𑦍��Ɏ��s����j
#define STATE_SPECIAL_ACTIVE		0x0005
// �K�E���[�h�̏I���錾�i�_���[�W���ʉ��o�Ȃǂ��s���A�o�g���I������ցj
#define STATE_SPECIAL_END		0x0006
// ���ݎ����Ă���R�}���h����������
#define STATE_COMMAND_ACTION		0x0007


// �U���R�}���h
#define COMMAND_ATTACK			0x1001
// �h��R�}���h
#define COMMAND_DEFENCE			0x1002
// ���̃t�F�[�Y�Ɉڍs����
//#define COMMAND_NEXT_PHASE		0x1003


