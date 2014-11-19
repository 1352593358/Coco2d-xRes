/**
*@file HelpPrompt.h
*@brief ������ʾ
*
*@author ���书��email: 906391500@qq.com
*@version 1.0
*@data 2014-11-4 15:17
*/

#ifndef __HELP_PROMPT_H__
#define __HELP_PROMPT_H__

#include "cocos2d.h"

enum 
{
	HELP_PROMPT_E_RECTANGLE,
	HELP_PROMPT_E_CIRCLE,
};

class HelpPrompt : public cocos2d::CCLayer 
{
public:
	HelpPrompt();
	virtual ~HelpPrompt();
///@brief ����һ����������ʾ��Ĭ�������ɰ�Ϊȫ������ʾ��Ϊ������Ϊ100*100
///@return 
	static HelpPrompt* Create(const cocos2d::CCPoint& pos);
	virtual bool init(const cocos2d::CCPoint& pos);

	virtual void onEnter();
	virtual void onExit();

//	virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
public:
///@brief ��ʾ������
///@param[in]  HELP_PROMPT_RECTANGLE--�����Σ�HELP_PROMPT_CIRCLE--Բ��
///@return 
	CC_PROPERTY(unsigned short, m_sPromptType, PromptType);
///@brief ����������ȡ
///@param[in] m_fWidth---���
///@pre ��ʾ��ʽ�ǳ�����
///@return 
	CC_PROPERTY(float, m_fWidth, Width);
///@brief �߶��������ȡ
///@param[out] m_fHeight---�߶�
///@pre ��ʾ��ʽ�ǳ�����
///@return 
	CC_PROPERTY(float, m_fHeight, Height);
///@brief �뾶�������ȡ
///@param[in] m_fRadius---�뾶
///@pre ��ʾ��ʽ��Բ��
///@return 
	CC_PROPERTY(float, m_fRadius, Radius);
///@brief λ���������ȡ
///@param[in] m_ptLocation---λ�� 
///@return 
	CC_PROPERTY(cocos2d::CCPoint, m_ptLocation, Location);
///@brief �Ƿ񴫵ݴ�����Ϣ
///@param[in] m_bSwallow--�Ƿ񴫵ݴ�����Ϣ
///@return true--���ݣ� false--������
	CC_PROPERTY(bool, m_bSwallow, Swallow);
private:
	void initData(const cocos2d::CCPoint& pos);
///@brief �Ƿ�Ҫ�ַ�������Ϣ
///@param[in] pos --- ����λ�� 
///@return true---�ַ� false--���ַ�
	bool bSwallowTouch(const cocos2d::CCPoint& pos);
};
#endif	///< (__HELP_PROMPT_H__)