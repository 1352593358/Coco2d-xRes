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
#include "Joystick.h" 

USING_NS_CC;

void Joystick::updatePos(float ft)
{  
// 	jsSprite->setPosition(ccpAdd(jsSprite->getPosition(),ccpMult(ccpSub(currentPoint, jsSprite->getPosition()),0.5)));  
	jsSprite->setPosition(currentPoint);
}  

void Joystick::Active()  
{  

	if (!active) 
	{  
		active = true;  
		schedule(schedule_selector(Joystick::updatePos));//���ˢ�º���  
		CCDirector* pDirector = CCDirector::sharedDirector();
//		pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);//��Ӵ���ί��  
	}
	else 
	{  

	}  
}  
//����ҡ��  
void Joystick::Inactive()  
{  
	if (active) 
	{  
		active=false;  
		this->unschedule(schedule_selector(Joystick::updatePos));	///< ɾ��ˢ��  
//		CCDirector* pDirector = CCDirector::sharedDirector();
//		pDirector->getTouchDispatcher()->removeDelegate(this);		///< ɾ��ί��  
	}
	else 
	{  

	}  
}  

bool Joystick::isPointInJoystick(const CCPoint touchPoint)
{
	CCSize size = jsSprite->getContentSize();
	float joyRadius = size.width > size.height ? size.height/2 : size.width/2;

	if (ccpDistance(centerPoint, touchPoint) <= joyRadius)
	{
		return true;
	}

	return false;
}

bool Joystick::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)  
{  
	if (!active)  
	{
		return false;  
	}

	CCPoint touchPoint = pTouch->getLocationInView();
	touchPoint = CCDirector:: sharedDirector()->convertToGL(touchPoint);  	

	if (!isPointInJoystick(touchPoint))
	{
		return false;
	}

	if (ccpDistance(touchPoint, centerPoint) > radius) 
	{
		return false;  
	}
	currentPoint = touchPoint;  
 
	return true;

}  

void Joystick::ccTouchMoved(CCTouch *pTouch, CCEvent *pEven)  
{  
	CCPoint touchPoint = pTouch->getLocationInView();  
	touchPoint = CCDirector:: sharedDirector()->convertToGL(touchPoint);  

	if (ccpDistance(touchPoint, centerPoint) > radius)  
	{  
		/// ��ǰλ��+�뾶*��������
 		currentPoint = ccpAdd(centerPoint,ccpMult(ccpNormalize(ccpSub(touchPoint, centerPoint)), radius));  
	}
	else 
	{  
		currentPoint = touchPoint;  
	}  
}  

void Joystick::ccTouchEnded(CCTouch *pTouch, CCEvent *pEven)  
{  
	currentPoint = centerPoint;  
}  

//��ȡҡ�˷�λ,ע���ǵ�λ����  
CCPoint Joystick::getDirection()  
{  
	return ccpNormalize(ccpSub(centerPoint, currentPoint));  
}  

//��ȡҡ������  
float Joystick::getVelocity()  
{  
	return ccpDistance(centerPoint, currentPoint);  
}  

Joystick* Joystick:: JoystickWithCenter(CCPoint aPoint ,float aRadius ,CCSprite* aJsSprite,CCSprite* aJsBg)
{  
	Joystick * jstick=Joystick::create();  
	jstick->initWithCenter(aPoint,aRadius,aJsSprite,aJsBg);  
	return jstick;  
}  

Joystick* Joystick:: JoystickWithCenter(CCPoint aPoint, CCSprite* aJsSprite, CCSprite* aJsBg)
{  
	Joystick * jstick	= Joystick::create();  
	CCSize sizeBg		= aJsBg->getContentSize();
	CCSize size			= aJsSprite->getContentSize();
	float aRadiusBg		= sizeBg.width > sizeBg.height ? sizeBg.height/2.0f : sizeBg.width/2.0f;
	float aRadius		= size.width > size.height ? size.height /2.0f : size.width/2.0f;
	aRadiusBg -= aRadius;
	jstick->initWithCenter(aPoint,aRadiusBg ,aJsSprite,aJsBg);  
	return jstick;  
}  

Joystick* Joystick::initWithCenter(CCPoint aPoint ,float aRadius ,CCSprite* aJsSprite,CCSprite* aJsBg)
{  
	active = false;  
	radius = aRadius;  
	centerPoint = aPoint;  
	currentPoint = centerPoint;  
	jsSprite = aJsSprite;  

	jsSprite->setPosition(centerPoint);  
	aJsBg->setPosition(centerPoint);  
	this->addChild(aJsBg);  
	this->addChild(jsSprite);  
	return this;  
}  

 

void Joystick::touchDelegateRetain()
{
	this->retain();
}

void Joystick::touchDelegateRelease()
{
	this->release();
}

void Joystick::onEnter()
{
	CCNode::onEnter();
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

void Joystick::onExit()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->removeDelegate(this);
}