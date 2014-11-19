/**
*@file TimeSchedule.cpp
*@brief 
*
*��ϸ����
*
*@author ���书��email: 906391500@qq.com
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
///@author ���书,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-6-17 15:58
void TimeSchedule::initData(const unsigned int& totalTime)
{
	/// �߹�
	m_pLight = CCSprite::create(FB_PIG_TIME_LIGHT);
	m_pLight->setPosition(ccp(-4, 2));
	this->addChild(m_pLight, 3);

	m_pTimeUp = CCSprite::create(FB_PIG_TIME_UP);
	m_pTimeUp->setPosition(ccp(-1, 113));
	this->addChild(m_pTimeUp, 2);

	m_pText2d = CCTextureCache::sharedTextureCache()->addImage(FB_PIG_TIME);
	m_pText2d->retain();

	CCPoint posProgress = ccp(-1, -13);
	m_pProgress = CCSprite::createWithTexture(m_pText2d);
	m_pProgress->setAnchorPoint(ccp(0.5f, 1.f));
	m_pProgress->setScaleY(-1.f);
	this->addChild(m_pProgress, 1);

	m_pButtom = CCSprite::create(FB_PIG_TIME_BUTTOM);
	m_pButtom->setPosition(ccp(0, 0));
	this->addChild(m_pButtom);

	m_fTimeLength = m_pProgress->getContentSize().height;			///< �����ֵ������ͼƬ�����
	posProgress.y -= m_fTimeLength/2.f;
	m_pProgress->setPosition(posProgress);

	m_fCurrentTime = 0.f;
	m_fTotalTime = totalTime;
	m_fAddTime		= 0.f;
	m_fReduceTime	= 0.f;
}

///@brief ��ʼ��ʱ
///@param[void] void
///@return 
///@author ���书,906391500@qq.com 
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
///@author ���书,906391500@qq.com 
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
///@author ���书,906391500@qq.com 
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
///@author ���书,906391500@qq.com 
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
///@author ���书,906391500@qq.com 
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
///@author ���书,906391500@qq.com 
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
///@author ���书,906391500@qq.com 
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

		m_pProgress->setTextureRect(CCRectMake(0, 0,
			m_pText2d->getContentSize().width, m_fTimeLength * (m_fTotalTime-m_fCurrentTime)/m_fTotalTime));
		
	float upY = 113;
	float deltaY = m_fTimeLength*m_fCurrentTime/m_fTotalTime;

	if (242.f  < deltaY)		///< �����ֵ����ͼƬ������������ͼƬ��С258---����ʵ��Ҫ������
	{
		/// ��Ϸ����
		this->unscheduleUpdate();
		/*		CCLOG("Game Over!");*/
		GameScene* gameScene = (GameScene*)this->getParent();
		gameScene->gameFail();
	}
	else
	{
		upY -= m_fTimeLength*m_fCurrentTime/m_fTotalTime;
		if (deltaY < 112.f)
		{
			m_pTimeUp->setScale(91.f/152.f*(112.f-deltaY)/112.f + 61.f/152.f);
		}
		else
		{
			m_pTimeUp->setScale(89.f/150.f*(deltaY - 112.f)/128.f + 61.f/150.f);
		}
		m_pTimeUp->setPositionY(upY);
	}
}