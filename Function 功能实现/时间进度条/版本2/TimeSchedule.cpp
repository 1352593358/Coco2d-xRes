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
#include "ENVGameScene.h"

USING_NS_CC;

static const char* TIME_PIG_BUTTOM					= "Time/PIC_UI_SJJDT3.png";			///< ʱ����ȵ��ײ�
static const cocos2d::CCPoint TIME_POINT_BUTTOM		= ccp(0, 0);
static const char* TIME_PIG_UP						= "Time/PIC_UI_SJJDT2.png";			///< ʱ����ȵ�����
static const cocos2d::CCPoint TIME_POINT_UP			= ccp(-13, 1);
static const char* TIME_PIG_UP_RIGHT				= "Time/PIC_UI_SJJDT21.png";			///< ʱ����ȵ�����
static const cocos2d::CCPoint TIME_POINT_UP_RIGHT	= ccp(142, 1);
static const char* TIME_PIG_ALARM					= "Time/PIC_UI_SJJDT1.png";			///<װ��Ʒ---С����
static const cocos2d::CCPoint TIME_POINT_ALARM		= ccp(-142, 0);

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
	m_pButtom = CCSprite::create(TIME_PIG_BUTTOM);
	m_pButtom->setPosition(TIME_POINT_BUTTOM);
	this->addChild(m_pButtom);

	m_pText2d = CCTextureCache::sharedTextureCache()->addImage(TIME_PIG_UP);
	m_pText2d->retain();

	m_pProgress = CCSprite::createWithTexture(m_pText2d);
	CCPoint pos = TIME_POINT_UP;
	pos.x -= m_pProgress->getContentSize().width/2.f;
	m_pProgress->setPosition(pos);
	m_pProgress->setAnchorPoint(ccp(0, 0.5f));
//	m_pProgress->setScaleX(-1.f);
	m_fTimeLength = m_pProgress->getContentSize().width;
	this->addChild(m_pProgress);

	/// �������Ҳ�
	m_pProgressRight = CCSprite::create(TIME_PIG_UP_RIGHT);
	m_pProgressRight->setPosition(TIME_POINT_UP_RIGHT);
	this->addChild(m_pProgressRight);
	

	/// С����װ��
	CCSprite* m_spAlarm = CCSprite::create(TIME_PIG_ALARM);
	m_spAlarm->setPosition(TIME_POINT_ALARM);
//	m_spAlarm->setVisible(false);
	this->addChild(m_spAlarm);

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
		gameScene->gameEnd();
	}
	{
		m_pProgress->setTextureRect(CCRectMake(0, 0, m_fTimeLength * (m_fTotalTime-m_fCurrentTime)/m_fTotalTime, m_pText2d->getContentSize().height));
		CCPoint pos = m_pProgressRight->getPosition();
		pos.x -= m_fTimeLength*delta/m_fTotalTime;
		m_pProgressRight->setPosition(pos);
	}
}

void TimeSchedule::resetTime( const float& timeGap )
{
	CCAssert(timeGap >= 0, "timeGap must be greater than 0!");
	this->unschedule(schedule_selector(TimeSchedule::addTimeSpeed));
	m_fAddTime += m_fTotalTime-m_fCurrentTime + timeGap;			///< ����Ҫ����timeGapʱ��ȥ��λ��������ʱ��Ҫ�ӻ���
	this->schedule(schedule_selector(TimeSchedule::addTimeSpeed), timeGap);
}

void TimeSchedule::resetTime()
{
	resetTime(0);
}
