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

// 初期化処理
bool BaseWindow::init() 
{
	if (!Node::init()) return false;

	makeView();

	return true;
}

// 初期Viewの生成（Designを使ってゲームの基礎画面を作成する）
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

// ウィンドウの開始処理
// この処理が終了したところで、makeView
void BaseWindow::start() 
{

}

// 開始時の通信処理
// 通信結果はシステムマネージャーのデータへ保存される
// このウィンドウで実行したデータはこのウィンドウのポインタ＋データ名で取得出来る
void BaseWindow::startConnection() 
{

}

// 開始時のアニメーション処理
void BaseWindow::startAnimation() 
{

}

// 表示されているViewの表示の更新やConnectionで取得した結果などを反映する
void BaseWindow::active() 
{

}

// ウィンドウのクローズ処理
// この処理が終了した所で、closeViewと次のウィンドウのstartが実行される
void BaseWindow::close() 
{

}

// 終了アニメーション
void BaseWindow::closeAnimation()
{

}

void BaseWindow::closeConnection()
{

}

void BaseWindow::closeView()
{

}

