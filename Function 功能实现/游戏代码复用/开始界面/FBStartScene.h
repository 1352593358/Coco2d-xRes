/**
*@file FBStartScene.h
*@brief ���ľ��Ϸ��ʼ����
*
* ���ڱ���Ϸ�����٣����û�м��ؽ���
*
*@author ���书��email: 906391500@qq.com
*@version 1.0
*@data 2014-10-1 15:08
*/

#ifndef __FB_START_SCENE_H__
#define __FB_START_SCENE_H__


#include "cocos2d.h"
#include "cocos-ext.h"

class StartScene : public cocos2d::CCLayer
{
public:
	virtual bool init();  
	static cocos2d::CCScene* scene();
	CREATE_FUNC(StartScene);

	static bool s_isResourceLoaded;
public:

	virtual void onEnter();
	virtual void onExit();

	virtual void update(float delta);
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	virtual void keyBackClicked();

	void gameInto(float delta);

///@brief ������---���������ʾ
///@param[] 
///@pre ǰ������ 
///@return
	void setFunBK();

///@brief ��Ϸ��ʼ��ť�����ص�����
///@param[in/out] 
///@pre ǰ������ 
///@return 
	void onGameStartBtnSelected();

///@brief �ҳ�վ�㰴ť�����ص�����
///@param[in/out] 
///@pre ǰ������ 
///@return 
	void onAimStartBtnSelected();

///@brief ����tp�����plist�ļ�----�����ϲ���ͬʱ�����ļ���֮�����ټ��1֡
///@param[in] delta---���ʱ�� 
///@return 
	void loadPlistFile(float delta);

	void onExitCancel(cocos2d::CCObject* pSender);

	void onExitConfirm(cocos2d::CCObject* pSender);

private:
	bool m_bTouch;
	cocos2d::CCSprite* m_spGameStartBtn;			///< ��Ϸ��ʼ��ť
	cocos2d::CCSprite* m_spAimStartBtn;				///< �ҳ�վ��
	cocos2d::CCActionInterval* m_actionAimBtn;		///< �ҳ�վ�㰴ť�������
	cocos2d::CCActionInterval* m_actionGameBtn;		///< ��Ϸ��ť�������

	bool m_isExitState;								///< �˳�״̬
	cocos2d::CCLayerColor* m_colorlayer;

	unsigned short m_sPlistFileth;					///< ���صڼ���plist�ļ�
};
#endif ///< (__FB_START_SCENE_H__)