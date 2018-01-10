#include "ActionObserver.h"
#include "extend_action.h"

ActionObserver::ActionObserver():
	event_flg_(),
	method_(NULL)
{
}

ActionObserver::~ActionObserver()
{
}

ActionObserver* ActionObserver::create()
{
	return create(NULL);
}

ActionObserver* ActionObserver::create(std::function<void()> callfunc_method)
{
	auto ret = new ActionObserver();
	if (ret && ret->init(callfunc_method)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}

bool ActionObserver::init(std::function<void()> callfunc_method)
{
	if (Node::init() == false) return false;
	setEndCallFunc(callfunc_method);
	return true;
}

/// イベントを登録する
void ActionObserver::registObject(Ref* _node)
{
	event_flg_.push_back(_node);
}

/// イベントを終了とする
void ActionObserver::unregist(Ref* _node)
{
	auto ite = std::find(event_flg_.begin(), event_flg_.end(), _node);
	if (ite != event_flg_.end()) {
		event_flg_.erase(ite);
		// 完全終了処理判定
		if (event_flg_.size() == 0 && method_) {
			// 実行タイミングは完全終了の次のフレーム
			this->runAction(CCCallFunc::create(method_));
		}
	}
}

/// イベントを全てキャンセルする
void ActionObserver::cancelObserver()
{
	event_flg_.clear();
}

/// 終了イベントのコールファンクを登録
void ActionObserver::setEndCallFunc(std::function<void()> callfunc_method)
{
	method_ = callfunc_method;
}

/// 終了イベントを呼び出す為のファンクションを呼び出す
ActionInstant* ActionObserver::getUnregistAction()
{
	return CallFuncParent::create(this, callfuncO_selector(ActionObserver::unregist));
}


