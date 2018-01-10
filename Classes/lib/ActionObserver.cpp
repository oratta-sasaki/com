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

/// �C�x���g��o�^����
void ActionObserver::registObject(Ref* _node)
{
	event_flg_.push_back(_node);
}

/// �C�x���g���I���Ƃ���
void ActionObserver::unregist(Ref* _node)
{
	auto ite = std::find(event_flg_.begin(), event_flg_.end(), _node);
	if (ite != event_flg_.end()) {
		event_flg_.erase(ite);
		// ���S�I����������
		if (event_flg_.size() == 0 && method_) {
			// ���s�^�C�~���O�͊��S�I���̎��̃t���[��
			this->runAction(CCCallFunc::create(method_));
		}
	}
}

/// �C�x���g��S�ăL�����Z������
void ActionObserver::cancelObserver()
{
	event_flg_.clear();
}

/// �I���C�x���g�̃R�[���t�@���N��o�^
void ActionObserver::setEndCallFunc(std::function<void()> callfunc_method)
{
	method_ = callfunc_method;
}

/// �I���C�x���g���Ăяo���ׂ̃t�@���N�V�������Ăяo��
ActionInstant* ActionObserver::getUnregistAction()
{
	return CallFuncParent::create(this, callfuncO_selector(ActionObserver::unregist));
}


