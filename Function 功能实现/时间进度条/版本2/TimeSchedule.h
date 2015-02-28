/**
*@file 
*@brief ʱ�������
*
*��ϸ����
*
*@author DionysosLai��email: 906391500@qq.com
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
///@return ˵��
	void startTimeProgrss();

///@brief ֹͣʱ���ʱ
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

///@brief ��λ
///@param[in]  timeGap---������ʱ�临λ 
///@return 
	void resetTime(const float& timeGap);
///@brief ��λ
///@return 
	void resetTime();

	CC_SYNTHESIZE(float, m_fTotalTime, TotalTime);		///< ��ʱ��
private:
///@brief ���������ʼ��
///@return ˵��
	void initData(const unsigned int& totalTime);

///@brief ��������ʱ���ٶ�
///@param[in/out] 
///@pre ǰ������ 
///@return 
	void addTimeSpeed(float delta);

///@brief ���Ƽ���ʱ���ٶ�
///@return 
	void reduceTimeSpeed(float delta);

private:
	cocos2d::CCSprite* m_pButtom;		///< �װ�
	cocos2d::CCSprite* m_pProgress;		///< ������
	cocos2d::CCSprite* m_pProgressRight;///< �������Ҳ�
	cocos2d::CCTexture2D* m_pText2d;	///< ������

	float m_fCurrentTime;				///< ��ǰʱ��
	float m_fTimeLength;				///< ������
	float m_fAddTime;					///< ��ǰ����ʱ��
	float m_fReduceTime;				///< ��ǰ����ʱ��
/*	float m_fAddTimeTotal;				///< �����ܵ�ʱ��*/
};
#endif	///< (__TIME_SCHEDULE_H__)