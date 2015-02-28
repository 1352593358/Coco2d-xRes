/**
*@file HitNum.h
*@brief ��������Ч��
*
*��ϸ����
*
*@author ���书��email: 906391500@qq.com
*@version 1.0
*@data 2014-10-23 11:32
*/
#ifndef __HIT_NUM_H__
#define __HIT_NUM_H__

#include "cocos2d.h"

class HitNum : public cocos2d::CCNode
{
public:
	HitNum();
	virtual ~HitNum();

///@brief ����
///@param[in] num---��������
///@pre ǰ������ 
///@return 
	static HitNum* create(const int& num);
	virtual bool init(const int& num);
private:
	void initData(const int& num);
};

#endif	///< (__HIT_NUM_H__)