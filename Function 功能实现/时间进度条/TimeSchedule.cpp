/**
*@file TimeSchedule.cpp
*@brief 
*
*��ϸ����
*
*@author DionysosLai��email: 906391500@qq.com
*@version 1.0
*@data 2014-6-17 15:57
*/
#include "TimeSchedule.h"
#include "FBGameScene.h"

#include "FBGamePigConst.h"

USING_NS_CC;


TimeSchedule::TimeSchedule()
{

}

TimeSchedule::~TimeSchedule()
{
	m_pText2d->release();
}

TimeSchedule* TimeSchedule::create(const unsigned int& totalTime)
{
	TimeSchedule* pRet = new TimeSchedule();
	if (pRet && pRet->init(totalTime))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
	return pRet;
}

bool TimeSchedule::init(const unsigned int& totalTime)
{
	if(!CCNode::init())
	{
		return false;
	}
	initData(totalTime);

	return true;
}

///@brief ���������ʼ��
///@param[]void
///@return 
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-6-17 15:58
void TimeSchedule::initData(const unsigned int& totalTime)
{
	/// �װ�
	m_pButtom = CCSprite::create(FB_PIG_TIME_BUTTON);
	m_pButtom->setPosition(FB_POINT_TIME_BUTTON);
	this->addChild(m_pButtom);

	m_pText2d = CCTextureCache::sharedTextureCache()->addImage(FB_PIG_TIME_UP);
	m_pText2d->retain();

	m_pProgress = CCSprite::createWithTexture(m_pText2d);
	m_pProgress->setPosition(FB_POINT_TIME_UP);
	m_pProgress->setAnchorPoint(ccp(0, 0.5f));
	this->addChild(m_pProgress);
	m_fTimeLength = m_pProgress->getContentSize().width;

	m_fCurrentTime = 0.f;
	m_fTotalTime = totalTime;
	m_fAddTime		= 0.f;
	m_fReduceTime	= 0.f;
}

///@brief ��ʼ��ʱ
///@param[void] void
///@return 
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-6-17 18:01
void TimeSchedule::startTimeProgrss()
{
	this->scheduleUpdate();
}

///@brief ֹͣʱ���ʱ
///@param[void] void 
///@return 
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-6-17 18:02
void TimeSchedule::stopTimeProgress()
{
	this->unscheduleUpdate();
}

///@brief ����ʱ��
///@param[in] time---���ӵ�ʱ��
///@pre ���Ӻ��ʱ�䲻�ܸ������ʱ��
///@return 
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-6-17 18:02
void TimeSchedule::addTime( const unsigned int& time, const float& timeGap )
{
	this->unschedule(schedule_selector(TimeSchedule::addTimeSpeed));
	m_fAddTime += time;
	this->schedule(schedule_selector(TimeSchedule::addTimeSpeed), timeGap);
}

///@brief ��������ʱ���ٶ�
///@param[in/out] 
///@return 
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-7-9 10:18
void TimeSchedule::addTimeSpeed( float delta )
{
	if (m_fAddTime < 0)
	{
		this->unschedule(schedule_selector(TimeSchedule::addTimeSpeed));
	}
	else
	{
		m_fCurrentTime -= 1.f;
		if (m_fCurrentTime < 0)
		{
			m_fCurrentTime = 0;
		}
		m_fAddTime -= 1.f;
	}
}

///@brief ���Ƽ���ʱ���ٶ�
///@param[in/out] 
///@return 
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-7-9 10:18
void TimeSchedule::reduceTimeSpeed( float delta )
{
	if (m_fReduceTime < 0)
	{
		this->unschedule(schedule_selector(TimeSchedule::addTimeSpeed));
	}
	else
	{
		m_fCurrentTime += 1.f;
		m_fReduceTime -= 1.f;
	}
}



///@brief ����ʱ��
///@param[in] time---���ٵ�ʱ�� 
///@return 
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-6-17 18:03
void TimeSchedule::reduceTime( const unsigned int& time, const float& timeGap )
{
	this->unschedule(schedule_selector(TimeSchedule::reduceTimeSpeed));
	m_fReduceTime += time;
	this->schedule(schedule_selector(TimeSchedule::reduceTimeSpeed), timeGap);
}

///@brief ʱ�����ٵ���
///@param[in] times---����  timeLast
///@pre times����0---ʱ�������ʧ�� С��0---��ʱ�䣬 -1--ʱ�侲ֹ
///@return 
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-6-17 18:03
void TimeSchedule::adjustTime( const float& times, unsigned int& timeLast )
{

}

void TimeSchedule::update( float delta )
{
	m_fCurrentTime = m_fCurrentTime + delta;
	if (m_fTotalTime  < m_fCurrentTime)
	{
		/// ��Ϸ����
		this->unscheduleUpdate();
/*		CCLOG("Game Over!");*/
		GameScene* gameScene = (GameScene*)this->getParent();
		gameScene->gameFail();
	}
	{
		m_pProgress->setTextureRect(CCRectMake(0, 0, m_fTimeLength * (m_fTotalTime-m_fCurrentTime)/m_fTotalTime, m_pText2d->getContentSize().height));
	}
}
