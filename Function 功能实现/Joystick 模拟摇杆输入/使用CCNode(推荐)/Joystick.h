/**
*@file Joystick.h
*@brief Joystick �ඨ��
*
*
*
*@author ԭ����Cocos2der http://blog.csdn.net/cocos2der/article/details/6912519
*	     ���ģ����书 Dionysos
*@version 1.0(maj.min�����汾.�ְ汾��ʽ)
*@data 2014-03-21
*/
#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__	

#include "cocos2d.h"  

//@brief 
///
///
using namespace cocos2d;  

///@brief ��Ҫ����
///
///ע����OnEnter�д���ί�л��ƺ�OnExit���Ƴ�ί�л���
///
///
///
///
///
///@invariant
///
class Joystick :public CCNode, public CCTargetedTouchDelegate
{  
public :  
	void Active();  
	void Inactive();  
	CCPoint getDirection();  
	float getVelocity();  
	void  updatePos(float ft);  

	//��ʼ�� aPoint��ҡ������ aRadius��ҡ�˰뾶 aJsSprite��ҡ�˿��Ƶ� aJsBg��ҡ�˱���  
	static Joystick* JoystickWithCenter(CCPoint aPoint,float aRadius ,CCSprite* aJsSprite,CCSprite* aJsBg);  
	static Joystick* JoystickWithCenter(CCPoint aPoint, CCSprite* aJsSprite, CCSprite* aJsBg);
	Joystick* initWithCenter(CCPoint aPoint ,float aRadius ,CCSprite* aJsSprite,CCSprite* aJsBg);  

	/// �жϵ��Ƿ�������ҡ����
	bool isPointInJoystick(const CCPoint touchPoint);

	/// ��������
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);  
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);  

	/// ����Э��
	virtual void touchDelegateRetain();
	virtual void touchDelegateRelease();

	virtual void onEnter(void);
	virtual void onExit(void);
private:
	CCPoint centerPoint;//ҡ������  
	CCPoint currentPoint;//ҡ�˵�ǰλ��  
	bool active;//�Ƿ񼤻�ҡ��  
	float radius;//ҡ�˰뾶  
	CCSprite *jsSprite;  
	CREATE_FUNC(Joystick);  
};  
#endif