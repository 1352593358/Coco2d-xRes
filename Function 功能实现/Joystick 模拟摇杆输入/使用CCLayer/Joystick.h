#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__	

#include "cocos2d.h"  

using namespace cocos2d;  

class Joystick :public CCLayer 
{  
public :  
	void Active();  
	void Inactive();  
	CCPoint getDirection();  
	float getVelocity();  
	void  updatePos(float ft);  

	//��ʼ�� aPoint��ҡ������ aRadius��ҡ�˰뾶 aJsSprite��ҡ�˿��Ƶ� aJsBg��ҡ�˱���  
	static Joystick*  JoystickWithCenter(CCPoint aPoint ,float aRadius ,CCSprite* aJsSprite,CCSprite* aJsBg);  
	Joystick * initWithCenter(CCPoint aPoint ,float aRadius ,CCSprite* aJsSprite,CCSprite* aJsBg);  

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);  
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);  
private:
	CCPoint centerPoint;//ҡ������  
	CCPoint currentPoint;//ҡ�˵�ǰλ��  
	bool active;//�Ƿ񼤻�ҡ��  
	float radius;//ҡ�˰뾶  
	CCSprite *jsSprite;  
	CREATE_FUNC(Joystick);  
};  
#endif