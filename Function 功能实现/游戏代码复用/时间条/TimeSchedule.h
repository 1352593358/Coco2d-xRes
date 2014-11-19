/**
*@file 
*@brief ʱ�������
*
*��ϸ����
*
*@author ���书��email: 906391500@qq.com
*@version 1.0
*@data 2014-7-8 11:54
*/


#ifndef __TIME_SCHEDULE_H__
#define __TIME_SCHEDULE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

class TimeSchedule : public cocos2d::CCNode
{
public:
	TimeSchedule();
	~TimeSchedule();

	static TimeSchedule* create(const unsigned int& totalTime);
	virtual bool init(const unsigned int& totalTime);
	virtual void update(float delta);

public:
///@brief ��ʼ��ʱ
///@param[void] void
///@pre ǰ������
///@return ˵��
	void startTimeProgrss();

///@brief ֹͣʱ���ʱ
///@param[void] void
///@return ˵��
	void stopTimeProgress();

///@brief ����ʱ��
///@param[in] time---���ӵ�ʱ�� timeGap---�������һ��ʱ��
///@pre ���Ӻ��ʱ�䲻�ܸ������ʱ��
///@return ˵��
	void addTime(const unsigned int& time, const float& timeGap);

///@brief ����ʱ��
///@param[in] time---���ٵ�ʱ��
///@return ˵��
	void reduceTime(const unsigned int& time, const float& timeGap);

///@brief ʱ�����ٵ���
///@param[in] times---����  timeLast
///@pre times����0---ʱ�������ʧ�� С��0---��ʱ�䣬 -1--ʱ�侲ֹ
///@return ˵��
	void adjustTime(const float& times, unsigned int& timeLast);

private:
///@brief ���������ʼ��
///@param[]void
///@return ˵��
	void initData(const unsigned int& totalTime);

///@brief ��������ʱ���ٶ�
///@param[in/out] 
///@return 
	void addTimeSpeed(float delta);

///@brief ���Ƽ���ʱ���ٶ�
///@param[in/out] 
///@return 
	void reduceTimeSpeed(float delta);

private:
	cocos2d::CCSprite* m_pLight;		///< �߹�
	cocos2d::CCSprite* m_pTimeUp;		///< ʱ��������
	cocos2d::CCSprite* m_pProgress;		///< ������
	cocos2d::CCTexture2D* m_pText2d;	///< ������
	cocos2d::CCSprite* m_pButtom;

	float m_fTotalTime;					///< ��ʱ��
	float m_fCurrentTime;				///< ��ǰʱ��
	float m_fTimeLength;				///< ������
	float m_fAddTime;					///< ��ǰ����ʱ��
	float m_fReduceTime;				///< ��ǰ����ʱ��
/*	float m_fAddTimeTotal;				///< �����ܵ�ʱ��*/
};
#endif	///< (__TIME_SCHEDULE_H__)