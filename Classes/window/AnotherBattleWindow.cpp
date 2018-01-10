#include "AnotherBattleWindow.h"
#include "battle/PhaseInit.h"
#include "battle/BattleController.h"
#include "core\BattleUnit.h"

AnotherBattleWindow::AnotherBattleWindow()
{
	// �o�g���p�̃R���e�L�X�g�̍쐬
	/*
	 -- �t�F�[�Y���X�g --
	// �o�g���J�n
	auto battlePhase = BattlePhase::create();
	battlePhase->start() -> command ->commandEndCheck ->end()
	// �L�����o��
	auto battleUnitPhase = BattleUnitPhase::create();
	// �R�}���h����
	auto commandPhase = CommandPhase::create();
	// �K�E�t�F�[�Y�i�I���Ƃ��U���Ƃ�������Ɋ܂܂��j
	auto specialPhase = SpecialPhase::create();
	// �R���{���o
	auto commboPhase = CommboPhase::create();
	// �o�g���t�F�[�Y
	auto battlePhase
	// �o�g���I������
	// �o�g���I��
	*/

	/*
	switch(nextPhase){
	 case nextSetup:
	  next(SetupPhase::create()); break;
	 case nextBattleStart:
 	  next(BattleStartPhase::create()); break;
	 case nextCommandView:
	  next(CommandViewPhase::create()); break;
	 case nextActionCommand:
	  next(ActionCommandPhase::create()); break;
	 case nextSpecialCommand:
	  next(SpecialCommandPhase::create()); break;
	}

	void next(Phase *phase){
	    phase->setContext(getContext());
		phase->setEndMethod(switchNextPhase);
		phase->start();
	}
	
	StatePhase {
	 void start();
	 void end();
	 void setContext(Context);
	 void setEndMethod(function<void(int)>);
	 void action();
	}
	
	*/









}

AnotherBattleWindow::~AnotherBattleWindow()
{

}

AnotherBattleWindow* AnotherBattleWindow::create()
{
	auto ret = new AnotherBattleWindow();
	if (ret && ret->init()) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}

// ����View�̐����iDesign���g���ăQ�[���̊�b��ʂ��쐬����j
void AnotherBattleWindow::makeView()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create(IMG_HELLO);
	sprite->setRotation(50);

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	vector<BattleUnit*> fealty = {
		BattleUnit::createAlly(),
		BattleUnit::createAlly(),
		BattleUnit::createAlly(),
		BattleUnit::createAlly(),
	};

	vector<BattleUnit*> enemy = {
		BattleUnit::createEnemy(),
		BattleUnit::createEnemy(),
		BattleUnit::createEnemy(),
		BattleUnit::createEnemy(),
	};

	for (auto unit : fealty) {
		this->addChild(unit);
	}
	for (auto unit : enemy) {
		this->addChild(unit);
	}

	// �o�g���R���e�L�X�g
	context = BattleContext::create([this]() { commandWaiting(); });
	this->addChild(context);
//	context->setLayer(this);
	context->addFealty(fealty);
	context->addEnemy(enemy);

	// 
	auto controller = BattleController::create();
	this->addChild(controller);
	controller->execute(context);

	CCLOG("battle phase setting end.");
}

// �R�}���h�҂��ɂȂ���
void AnotherBattleWindow::commandWaiting()
{
	CCLOG("command waiting...");

}



