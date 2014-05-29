#include "GameMenu.h"

USING_NS_CC;

bool GameMenu::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	/// �Ѵ��������������ǿת�£���ñ�����������δʹ�õľ��档
	CC_UNUSED_PARAM(pEvent);  
	if (m_eState != kCCMenuStateWaiting || ! m_bIsVisible)  
	{  
		return false;  
	}  

	for (CCNode *c = this->m_pParent; c != NULL; c = c->getParent())  
	{  
		if (c->getIsVisible() == false)  
		{  
			return false;  
		}  
	}  

	m_pSelectedItem = this->itemForTouch(pTouch);  
	if (m_pSelectedItem)  
	{  
		m_eState = kCCMenuStateTrackingTouch;  
		m_pSelectedItem->selected();  
		///��������Լ���Ҫ��Ч����������������������������������  
		return true;  
	}  
	return false;  
}

GameMenu* GameMenu::menuWithItems(CCMenuItem* item, ...)
{
	va_list args;  
	va_start(args,item);  
	GameMenu *pRet = new GameMenu();	///< ����ǵ�Ҫע��  
	if (pRet && pRet->initWithItems(item, args))  
	{  
		pRet->autorelease();  
		va_end(args);  
		return pRet;  
	}  
	va_end(args);  
	CC_SAFE_DELETE(pRet);
	return NULL; 
}