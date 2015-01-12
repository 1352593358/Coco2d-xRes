/**Copyright (c) 2014, �㶫С��ſƼ����޹�˾
*All rights reserved.
*@file BBLStar.h
*@brief ���ǽڵ�
*@author ���书��email: 906391500@qq.com
*@version 1.0
*@data 2014-8-28 16:47
*/

#ifndef __BBL_STAR_H__
#define __BBL_STAR_H__

#include "cocos2d.h"

class Star : public cocos2d::CCNode
{
public:
	Star();
	~Star();

	static Star* create(const unsigned int& starNum);
	virtual bool init(const unsigned int& starNum);

public:
///@brief ����һ��Ŀ����
///@return 
	void addTask();
///@brief ����һ��Ŀ����
///@return 
	void reduceTask();
private:
	void initData(const unsigned int& starNum);
private:
	cocos2d::CCArray* m_starArray;
	unsigned int m_uiTask;					///< ��ɵ�Ŀ������

	cocos2d::CCTexture2D* m_texttureL;		///< ���ǵ�������
	cocos2d::CCTexture2D* m_texttureA;		///< ���ǰ�����
};

#endif