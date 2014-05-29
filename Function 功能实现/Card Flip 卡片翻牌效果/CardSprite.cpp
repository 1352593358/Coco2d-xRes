#include "CardSprite.h"  

#define kInAngleZ        270 ///< ���濨�Ƶ���ʼZ��Ƕ�  
#define kInDeltaZ        90  ///< ���濨����ת��Z��ǶȲ�  
#define kOutAngleZ       0   ///< ���濨�Ƶ���ʼZ��Ƕ�  
#define kOutDeltaZ       90  ///< ���濨����ת��Z��ǶȲ�  

#define kDownAngleZ     0	///< ���¿��Ƶ���ʼZ��Ƕ�  
#define kDownDeltaZ     90  ///< ���¿�����ת��Z��ǶȲ�  
#define kUpAngleZ       270 ///< ���Ͽ��Ƶ���ʼZ��Ƕ�  
#define kUpDeltaZ       90  ///< ���Ͽ�����ת��Z��ǶȲ�  

#define kSlideAngleX	90 ///< ���Ͽ��Ƶ���ʼZ��Ƕ�  
#define kSlipeDeltaX	0  ///< ���Ͽ�����ת��Z��ǶȲ�  

enum {  
	tag_inCard = 1,  
	tag_outCard  
};  

CardSprite::CardSprite()  
{  

}  

CardSprite::~CardSprite()  
{  
	m_openAnimIn->release();  
	m_openAnimOut->release();  
}  

CardSprite* CardSprite::create(const char* inCardImageName, const char* outCardImageName, float duration)  
{  
	CardSprite *pSprite = new CardSprite();  
	if (pSprite && pSprite->init(inCardImageName, outCardImageName, duration))  
	{  
		pSprite->autorelease();  
		return pSprite;  
	}  
	CC_SAFE_DELETE(pSprite);  
	return NULL;  
}  

bool CardSprite::init(const char* inCardImageName, const char* outCardImageName, float duration)  
{  
	if (!CCSprite::init())  
	{  
		return false;  
	}  
	initData(inCardImageName, outCardImageName, duration);  
	return true;  
}  
 
void CardSprite::initData(const char* inCardImageName, const char* outCardImageName, float duration)  
{  
	m_isOpened = false;  

	CCSprite* inCard = CCSprite::create(inCardImageName);  
	inCard->setPosition(CCPointZero);  
	inCard->setVisible(false);  
	inCard->setTag(tag_inCard);  
	addChild(inCard);  

	CCSprite* outCard = CCSprite::create(outCardImageName);  
	outCard->setPosition(CCPointZero);  
	outCard->setTag(tag_outCard);  
	addChild(outCard);  

	m_openAnimIn = (CCActionInterval*)CCSequence::create(CCDelayTime::create(duration * .5),  
		CCShow::create(),  
		CCOrbitCamera::create(duration * .5, 1, 0, kInAngleZ, kInDeltaZ, 0, 0),  
		NULL);  
	m_openAnimIn->retain();  

	m_openAnimOut = (CCActionInterval *)CCSequence::create(CCOrbitCamera::create(duration * .5, 1, 0, kOutAngleZ, kOutDeltaZ, 0, 0),  
		CCHide::create(),  
		CCDelayTime::create(duration * .5),  
		NULL);  
	m_openAnimOut->retain();

	m_slideUp = (CCActionInterval*)CCSequence::create(CCDelayTime::create(duration * .5),  
		CCShow::create(),  
		CCOrbitCamera::create(duration * .5, 1, 0, kUpAngleZ, kUpDeltaZ, kSlideAngleX, kSlipeDeltaX),  
		NULL);  
	m_slideUp->retain();
	
	m_slideDown = (CCActionInterval *)CCSequence::create(CCOrbitCamera::create(duration * .5, 1, 0, kDownAngleZ, kDownDeltaZ, kSlideAngleX, kSlipeDeltaX),  
		CCHide::create(),  
		CCDelayTime::create(duration * .5),  
		NULL);  
	m_slideDown->retain();


  
}  
 
void CardSprite::openCard()  
{    
	CCSprite* inCard = (CCSprite*)getChildByTag(tag_inCard); 
	CCSprite* outCard = (CCSprite*)getChildByTag(tag_outCard); 
	/// û��stop�Ļ����ٴ�openCard�����
	inCard->stopAllActions() ;
	outCard->stopAllActions() ; 

	inCard->runAction(m_openAnimIn); 
	outCard->runAction(m_openAnimOut); 
}

CCSize CardSprite:: getContentSize() 
{ 
	CCSprite* inCard = (CCSprite*)getChildByTag(tag_inCard); 
	return inCard->getContentSize();
}

void CardSprite::closeCard( void )
{
	CCSprite* inCard = (CCSprite*)getChildByTag(tag_inCard); 
	CCSprite* outCard = (CCSprite*)getChildByTag(tag_outCard); 
	/// û��stop�Ļ����ٴ�openCard�����
	inCard->stopAllActions() ;
	outCard->stopAllActions() ; 

	inCard->runAction(m_openAnimOut); 
	outCard->runAction(m_openAnimIn); 
}

void CardSprite::slideDown( void )
{
	CCSprite* inCard = (CCSprite*)getChildByTag(tag_inCard); 
	CCSprite* outCard = (CCSprite*)getChildByTag(tag_outCard); 
	/// û��stop�Ļ����ٴ�openCard�����
	inCard->stopAllActions() ;
	outCard->stopAllActions() ; 

	inCard->runAction(m_slideUp); 
	outCard->runAction(m_slideDown); 
}

void CardSprite::slideUp( void )
{
	CCSprite* inCard = (CCSprite*)getChildByTag(tag_inCard); 
	CCSprite* outCard = (CCSprite*)getChildByTag(tag_outCard); 
	/// û��stop�Ļ����ٴ�openCard�����
	inCard->stopAllActions() ;
	outCard->stopAllActions() ; 

	inCard->runAction(m_slideDown); 
	outCard->runAction(m_slideUp); 
}
