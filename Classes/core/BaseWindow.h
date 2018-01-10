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

	// 初期Viewの生成（Designを使ってゲームの基礎画面を作成する）
	virtual void makeView();

	// ウィンドウの開始処理
	// この処理が終了したところで、makeView
	virtual void start();

	// 開始時の通信処理
	// 通信結果はシステムマネージャーのデータへ保存される
	// このウィンドウで実行したデータはこのウィンドウのポインタ＋データ名で取得出来る
	virtual void startConnection();

	// 開始時のアニメーション処理
	virtual void startAnimation();

	// 表示されているViewの表示の更新やConnectionで取得した結果などを反映する
	virtual void active();

	// ウィンドウのクローズ処理
	// この処理が終了した所で、closeViewと次のウィンドウのstartが実行される
	virtual void close();

	// 終了アニメーション
	virtual void closeAnimation();

	virtual void closeConnection();

	virtual void closeView();

	// デザイン関係のUIであるならば、自動的にアニメーション制御の対象にする
	// この機能を利用する事によって
	// startAnimation, closeAnimationはほぼ気にしなくてもいいようになる
	// addやremoveの時点でアニメーションするかどうかは未決定
//	virtual void addChild();




};

#endif // __BASE_WINDOW_H__
