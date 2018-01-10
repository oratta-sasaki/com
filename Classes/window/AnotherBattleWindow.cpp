#include "AnotherBattleWindow.h"
#include "battle/PhaseInit.h"
#include "battle/BattleController.h"
#include "core\BattleUnit.h"

AnotherBattleWindow::AnotherBattleWindow()
{
	// バトル用のコンテキストの作成
	/*
	 -- フェーズリスト --
	// バトル開始
	auto battlePhase = BattlePhase::create();
	battlePhase->start() -> command ->commandEndCheck ->end()
	// キャラ登場
	auto battleUnitPhase = BattleUnitPhase::create();
	// コマンド入力
	auto commandPhase = CommandPhase::create();
	// 必殺フェーズ（選択とか攻撃とかもこれに含まれる）
	auto specialPhase = SpecialPhase::create();
	// コンボ演出
	auto commboPhase = CommboPhase::create();
	// バトルフェーズ
	auto battlePhase
	// バトル終了判定
	// バトル終了
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

// 初期Viewの生成（Designを使ってゲームの基礎画面を作成する）
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

	// バトルコンテキスト
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

// コマンド待ちになった
void AnotherBattleWindow::commandWaiting()
{
	CCLOG("command waiting...");

}



