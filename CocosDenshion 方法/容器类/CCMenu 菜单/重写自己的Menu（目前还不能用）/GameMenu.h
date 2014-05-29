#ifndef __GAME_MENU_H__
#define __GAME_MENU_H__

#include "cocos2d.h"


USING_NS_CC;

class GameMenu : public CCMenu
{
public:
	/// ����
	GameMenu(void);
	~GameMenu(void);
	/// ����
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	/// 
	GameMenu* menuWithItems(CCMenuItem* item, ...);
	/// �˵��Ƿ�ɼ�
	bool getIsVisible(void);
	/// ���ò˵��Ƿ�ɼ�
	void setIsVisible(bool isVisible);

private:
	CCMenuItem* m_pSelectedItem;
	bool	m_bIsVisible;		///< �˵��Ƿ�ɼ�;
};
#endif