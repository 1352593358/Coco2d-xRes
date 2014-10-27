/**
*@file CircleActionBy.h
*@brief Բ���˶�
*
*��ϸ����
*
*@author DionysosLai��email: 906391500@qq.com
*@version 1.0
*@data 2014-10-9 17:34
*/

#ifndef __CIRCLE_ACTION_H__
#define __CIRCLE_ACTION_H__

#include "cocos2d.h"

class CircleActionBy : public cocos2d::CCActionInterval
{
public:
	CircleActionBy();
	~CircleActionBy();

	/// ����������ʱ�� Բ�� �뾶
	static CircleActionBy* create(float t, cocos2d::CCPoint circleCenter, float radius);

	bool init(float t, cocos2d::CCPoint circleCenter, float radius);

    virtual void startWithTarget(cocos2d::CCNode *pTarget);

    virtual void update(float time);
private:

protected:
	cocos2d::CCPoint m_ptCircleCenter;	///< Բ��
	float m_fRadius;					///< �뾶
	float m_fRadian;					///< ����
	float m_fMoveTimes;					///< ˢ�´���
};
#endif		///< (__CIRCLE_ACTION_H__)