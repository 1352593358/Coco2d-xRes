/**
*@file RoleSprite.cpp
*@brief ��Ϸ��ɫ����
*@author DionysosLai��906391500@qq.com
*@version 1.0(2014-04-16)
*@data 2014-04-16
*/

#include "RoleSprite.h"

RoleSprite::RoleSprite()
{

}

RoleSprite::~RoleSprite()
{

}

RoleSprite* RoleSprite::create()
{
	RoleSprite *pSprite = new RoleSprite();  
	if (pSprite && pSprite->init())  
	{  
		pSprite->autorelease();  
		return pSprite;  
	}  
	CC_SAFE_DELETE(pSprite);  
	return NULL;  
}

bool RoleSprite::init()
{
	if (!CCSprite::init())  
	{  
		return false;  
	}  
	initData();  
	return true; 
}

void RoleSprite::initData()
{

}

///@brief ��һ��png��ͼ�д�������
///@param[in] unitFrameTime--ÿһ֡ʱ�䳤�ȣ� plistName---plist�ļ�����png---pngͼƬ���� pngName---pngͼƬ�����С���� frames---֡����
///@pre ÿһ֡��Сһ��
///@return 
///@retval 
///@post 
///@author DionysosLai��906391500@qq.com
///@version 1.0(2014-04-16)
///@data 2014-04-16
CCAnimate* RoleSprite::createActionWithPng( float unitFrameTime, const char* pngName, CCSize frameSize, int frames )
{
	CCTexture2D *playerRunTexture = CCTextureCache::sharedTextureCache()->addImage(pngName);      
	CCAnimation* animation = CCAnimation::create();  
	for( int i = 0;i < frames; i++)
	{  
		animation->addSpriteFrame(CCSpriteFrame::createWithTexture(playerRunTexture, cocos2d::CCRectMake(frameSize.width*i, 0, frameSize.width, frameSize.height)));  
	}  
	// should last 2.8 seconds. And there are 14 frames.  
	animation->setDelayPerUnit(unitFrameTime);  
//	return animation;
	CCAnimate* action = CCAnimate::create(animation); 
	return action;
/*	return CCRepeatForever::create(action);  */
}

///@brief ��plist�д���������
///@param[in] unitFrameTime--ÿһ֡ʱ�䳤�ȣ� pngName---pngͼƬ�� frameSize---ͼƬ��ÿһ֡��С�� frames---֡����
///@pre ע�������pngName���Ƚ����⣬����ԭ��Ϊ��hatch_open_0.png����������봫����Ϊhatch_open_0
///@return 
///@retval 
///@post 
///@author DionysosLai��906391500@qq.com
///@version 1.0(2014-04-16)
///@data 2014-04-16
CCAnimate* RoleSprite::createActionWithPlist(float unitFrameTime, const char* plistName, const char* png, const char* pngName, int frames)
{
    //�����ڳ��������ʱ��Ԥ������Щ������Դ��Ȼ����cache�ж�ȡ 
    CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache(); 
    cache->addSpriteFramesWithFile(plistName, png);  

    CCArray* animFrames = CCArray::createWithCapacity(frames);
      
    char ch[64] = {0};  
    for(int i = 0; i < frames; i++)   
    {  
        sprintf(ch, "%d.png", i);  
		char str[64] = {0};	
		strcat(str, pngName);
		strcat(str, ch);
        CCSpriteFrame* frame = cache->spriteFrameByName( str );  
        animFrames->addObject(frame);  
    }  
      
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames,unitFrameTime);  
//	return animation;
	CCAnimate* action = CCAnimate::create(animation); 	
/*	return CCRepeatForever::create(CCAnimate::create(animation)); */
	return action;
}

///@brief �Ӷ���ͼƬpngͼƬ�У���������
///@param[in] unitFrameTime--ÿһ֡ʱ�䳤�ȣ�pngName---pngͼƬ���� frames---֡����
///@pre ע�������pngName���Ƚ����⣬����ԭ��Ϊ��hatch_open_0.png����������봫����Ϊhatch_open_0
///@return 
///@retval ���з����Ƚ��ʺ϶�����λ��
///@post 
///@author DionysosLai��906391500@qq.com
///@version 1.0(2014-04-16)
///@data 2014-04-16
CCAnimate* RoleSprite::createActoinWithPngs( float unitFrameTime, const char* pngName, int frames )
{
/*	CCTexture2D *playerRunTexture = CCTextureCache::sharedTextureCache()->addImage(pngName);*/      
	CCAnimation* animation = CCAnimation::create();  
	    
	char ch[64] = {0};
	for( int i = 0;i < frames; i++)
	{  
        sprintf(ch, "%d.png", i);
		char str[64] = {0};	
		strcat(str, pngName);
		strcat(str, ch);
		CCTexture2D *playerRunTexture = CCTextureCache::sharedTextureCache()->addImage(str);
		animation->addSpriteFrame(CCSpriteFrame::createWithTexture(playerRunTexture, 
			CCRectMake(0, 0, playerRunTexture->getContentSize().width, playerRunTexture->getContentSize().height)));  
	}  
 
	animation->setDelayPerUnit(unitFrameTime);  
//	return animation;
	CCAnimate* action = CCAnimate::create(animation);  
	return action;
/*	return CCRepeatForever::create(action);  */
}
///@brief ��cocostudio�����д�������
///@param[in] plistName--plist�ļ�����pngName---pngͼƬ���� josnName---josn�ļ�����armatureName--��������index---�������к�
///@pre 
///@return 
///@retval
///@post 
///@author DionysosLai��906391500@qq.com
///@version 1.0(2014-04-16)
///@data 2014-04-16
CCArmature* RoleSprite::createArmature( const char* plistName, const char* pngName, const char* josnName, const char* armatureName, const unsigned int index )
{
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo(pngName,plistName,josnName);
	CCArmature *armature = CCArmature::create(armatureName);
	armature->getAnimation()->playByIndex(0);
	
	return armature;
}

///@brief ���ص�ǰ�Ķ���֡
///@param[in] animate---��ǰ����
///@pre	  ��������ķ�����ͨ����ȡ��ǰ����ID��ʵ�֣���ˣ�ʹ�÷�Χ�ǵ�ǰ����ID����һ������������һ�Ŵ�ͼ�и���λ�ó�ȡ�������ݣ������á�
///@return currentAnimIndex---��ǰ����֡ -1---��ȡʧ��
///@retval
///@post 
///@author DionysosLai��906391500@qq.com
///@version 1.0(2014-04-16)
///@data 2014-04-16
int RoleSprite::getCurrentFrameWithPngs( const CCAnimate* animate)
{
	int currentAnimIndex = 0; 
	unsigned int frameSum = animate->getAnimation()->getFrames()->capacity();	/// ��ȡ��������֡��
	for(unsigned int i = 0; i < frameSum; i++)  
	{  
		GLint iID = this->getTexture()->getName();		///< ��ȡ���鵱ǰ����ID
		/// ���λ�ȡ����֡�����ݶ���֡��ȡ������ID
		CCAnimationFrame* animFrame =(CCAnimationFrame*)animate->getAnimation()->getFrames()->objectAtIndex(i);		///< ע��������	CCAnimationFrame������CCSpriteFrame
		GLint iID1 = animFrame->getSpriteFrame()->getTexture()->getName();
		if (iID1 == iID)
		{
			currentAnimIndex = i;
			return currentAnimIndex;
		}
	}  
	return -1;
}

int RoleSprite::getCurrentFrameWithPng( const CCAnimate* animate)
{
// 	int currentAnimIndex = 0; //���鵱ǰ���ŵ��ǵڼ�֡  
// 	unsigned int frameSum = animate->getAnimation()->getFrames()->capacity();
// 	for(unsigned int i = 0; i < frameSum; i++)  
// 	{  
// 		CCRect rect = this->getTextureRect();
// // 		CCAnimationFrame* animFrame =(CCAnimationFrame*)animate->getAnimation()->getFrames()->objectAtIndex(i);
// // 		GLint iID1 = animFrame->getSpriteFrame()->getTexture()->getName();
// // 		if (iID1 == iID)
// 		{
// // 			currentAnimIndex = i;
// // 			return currentAnimIndex;
// // 		}		i = i;
// 	}  
 	return -1;
}


