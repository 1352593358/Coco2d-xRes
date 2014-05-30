/**
*@file CircleClipNode.h
*@brief ʵ��Բ������Ч��
*
*��ϸ����
*
*@author DionysosLai��email: 906391500@qq.com
*@version 1.0
*@data 2014-5-30 10:27
*/

#ifndef __CIRCLE_CLIPNODE_H__
#define __CIRCLE_CLIPNODE_H__

#include "cocos2d.h"

enum 
{
	TAGCLIPNODE,
};

class CircleClipNode : public cocos2d::CCNode
{
public:
	CircleClipNode();
	~CircleClipNode();
public:
	///@brief ����Բ������
	///@param[in] cen--Բ�� radius--�뾶 radiusDelta--- ÿ�ΰ뾶�����С�� radiusEnd--���뾶���ڻ�С��ĳһֵʱ�������˶����� bInverted--true--��ʾ���װ�-ģ������ ��
	///@pre ǰ������
	///@return ˵��
	static CircleClipNode* create(cocos2d::CCPoint cen, float radius, float radiusDelta, float radiusEnd, bool bInverted);
	virtual bool init(cocos2d::CCPoint cen, float radius, float radiusDelta, float radiusEnd, bool bInverted);

	CC_PROPERTY(bool, m_bEnd, End);
private:
	void initData(cocos2d::CCPoint cen, float radius, float radiusDelta, float radiusEnd, bool bInverted);

	virtual void update(float delta);
private:
	float m_fRadius;				///< �뾶
	cocos2d::CCPoint m_pointCen;	///< Բ��
	float m_fRadiusDelta;			///< �뾶
	float m_fRadiusEnd;				///< �뾶���ڻ�С�ڶ���ʱ���������ý���

protected:

};
#endif // (__CIRCLE_CLIPNODE_H__)
