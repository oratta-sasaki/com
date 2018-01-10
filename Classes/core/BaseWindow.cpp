#include "BaseWindow.h"
#include "SimpleAudioEngine.h"
#include "frame/settings.h"

USING_NS_CC;

BaseWindow::BaseWindow()
{

}

BaseWindow::~BaseWindow()
{

}

// ����������
bool BaseWindow::init() 
{
	if (!Node::init()) return false;

	makeView();

	return true;
}

// ����View�̐����iDesign���g���ăQ�[���̊�b��ʂ��쐬����j
void BaseWindow::makeView() 
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = Label::createWithTTF("start core", "fonts/Marker Felt.ttf", 24);

	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create(IMG_HELLO);

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);
}

// �E�B���h�E�̊J�n����
// ���̏������I�������Ƃ���ŁAmakeView
void BaseWindow::start() 
{

}

// �J�n���̒ʐM����
// �ʐM���ʂ̓V�X�e���}�l�[�W���[�̃f�[�^�֕ۑ������
// ���̃E�B���h�E�Ŏ��s�����f�[�^�͂��̃E�B���h�E�̃|�C���^�{�f�[�^���Ŏ擾�o����
void BaseWindow::startConnection() 
{

}

// �J�n���̃A�j���[�V��������
void BaseWindow::startAnimation() 
{

}

// �\������Ă���View�̕\���̍X�V��Connection�Ŏ擾�������ʂȂǂ𔽉f����
void BaseWindow::active() 
{

}

// �E�B���h�E�̃N���[�Y����
// ���̏������I���������ŁAcloseView�Ǝ��̃E�B���h�E��start�����s�����
void BaseWindow::close() 
{

}

// �I���A�j���[�V����
void BaseWindow::closeAnimation()
{

}

void BaseWindow::closeConnection()
{

}

void BaseWindow::closeView()
{

}

