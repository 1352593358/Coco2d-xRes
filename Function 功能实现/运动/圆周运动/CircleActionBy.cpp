/**
*@file CircleActionBy.cpp
*@brief Բ���˶�
*
*��ϸ����
*
*@author DionysosLai��email: 906391500@qq.com
*@version 1.0
*@data 2014-10-9 17:50
*/
#include "CircleActionBy.h"

USING_NS_CC;

CircleActionBy::CircleActionBy()
{

}

CircleActionBy::~CircleActionBy()
{

}

CircleActionBy* CircleActionBy::create( float t, cocos2d::CCPoint circleCenter, float radius )
{
	CircleActionBy* pRet = new CircleActionBy();
	pRet->init(t, circleCenter, radius);
	pRet->autorelease();

	return pRet;
}

bool CircleActionBy::init( float t, cocos2d::CCPoint circleCenter, float radius )
{
	if (CCActionInterval::initWithDuration(t))
	{
		m_ptCircleCenter = circleCenter;
		m_fRadius = radius;

		m_fRadian = 2.0*M_PI/(t/(CCDirector::sharedDirector()->getAnimationInterval()));		///< ÿ�ε�λʱ��ת���ĵ�λ���ȣ�
		m_fMoveTimes = 1;
		return true;
	}
	return false;
}

void CircleActionBy::update( float time )
{
	if (m_pTarget)
	{
		float radian = m_fRadian * m_fMoveTimes;	///< ÿ��ת�Ļ��� = ��λ����*�˶�������

		float x = m_fRadius * sin(radian);			///< ���ݰ뾶�ͻ��ȣ������԰�ϵ�����
		float y = m_fRadius * cos(radian);
		CCPoint newPoint = ccp(x + m_ptCircleCenter.x, y + m_ptCircleCenter.y);

		m_pTarget->setPosition(newPoint);			///< ����Ŀ������ꣻ

		m_fMoveTimes += 1;							///< ÿ֡�����˶�����+1
	}
}

void CircleActionBy::startWithTarget( CCNode *pTarget )
{
	CCActionInterval::startWithTarget(pTarget);
}
