/**
*@file CircleClipNode.cpp
*@brief ʵ��Բ������Ч�� ����ʵ�ַ�ʽ
*
*��ϸ����
*
*@author DionysosLai��email: 906391500@qq.com
*@version 1.0
*@data 2014-5-30 10:40
*/
#include "CircleClipNode.h"

USING_NS_CC;


CircleClipNode::CircleClipNode()
{

}

CircleClipNode::~CircleClipNode()
{
/*	pClip->release();*/
}

///@brief ������̬Բ������
///@param[in]  cen--Բ�� radius--�뾶 radiusDelta--- ÿ�ΰ뾶�����С�� radiusEnd--���뾶���ڻ�С��ĳһֵʱ�������˶����� bInverted--true--��ʾ���װ�-ģ������ ��
///@return 
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-5-30 11:14
CircleClipNode* CircleClipNode::create( cocos2d::CCPoint cen, float radius, float radiusDelta, float radiusEnd, bool bInverted )
{
	CircleClipNode *pRet = new CircleClipNode();
	if (pRet && pRet->init(cen, radius, radiusDelta, radiusEnd, bInverted))
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
}

bool CircleClipNode::init( cocos2d::CCPoint cen, float radius, float radiusDelta, float radiusEnd, bool bInverted )
{
	if (!CCNode::init())  
	{  
		return false;  
	}  

	initData(cen, radius, radiusDelta, radiusEnd, bInverted);  
	return true; 
}

void CircleClipNode::initData( cocos2d::CCPoint cen, float radius, float radiusDelta, float radiusEnd, bool bInverted )
{
	m_fRadius		= radius;
	m_pointCen		= cen;
	m_fRadiusDelta	= radiusDelta;
	m_fRadiusEnd	= radiusEnd;
	m_bStartClip	= false;
	m_bRunClip		= false;
	m_uiRunclip		= 0.f;
	//����cliper
	CCClippingNode* pClip=CCClippingNode::create();
	pClip->setInverted(bInverted);
	addChild(pClip, 0, TAGCLIPNODE);
	//��ӵװ�
	CCLayerColor* pColor=CCLayerColor::create(ccc4(0,0,0,200));
	pClip->addChild(pColor);

	//����Բ������
	static ccColor4F green	= {0, 1, 0, 1};					///< ������ɫ,��������û��ʵ����û�л���,���Կ�������ɫ
	const int nCount		= 100;							///< Բ����ʵ���Կ����������,������������100������ģ��԰
	const float coef		= 2.0f * (float)M_PI/nCount;	///< ����ÿ�������ڶ��������ĵļн�
	static CCPoint circle[nCount];							///< ��������
	for(unsigned int i = 0;i < nCount; ++i) 
	{
		float rads	= i*coef;//����
		circle[i].x = m_pointCen.x + m_fRadius * cosf(rads);//��Ӧ�����x
		circle[i].y = m_pointCen.y + m_fRadius * sinf(rads);//��Ӧ�����y
	}

	CCDrawNode *pStencil=CCDrawNode::create();
	pStencil->drawPolygon(circle, nCount, green, 0, green);//������������!

	this->schedule(schedule_selector(CircleClipNode::onRunClip), 0.05f);
	//����ģ��
	pClip->setStencil(pStencil);

	this->setEnd(false);
}

void CircleClipNode::update( float delta )
{
	do 
	{		
		if(!m_bStartClip)
		{
			break;			
		}	


		m_fRadius = m_fRadius + m_fRadiusDelta;


		/// �ж��Ƿ�̬�ı�Բ������ ������
		if ( (m_fRadiusDelta > 0 && m_fRadius > m_fRadiusEnd) || 
			(m_fRadiusDelta < 0 && m_fRadius < m_fRadiusEnd))
		{
			setEnd(true);
			this->unscheduleUpdate();
			return;
		}

		//����Բ������
		static ccColor4F green	= {0, 1, 0, 1};					///< ������ɫ,��������û��ʵ����û�л���,���Կ�������ɫ
		const int nCount		= 100;							///< Բ����ʵ���Կ����������,������������100������ģ��԰
		const float coef		= 2.0f * (float)M_PI/nCount;	///< ����ÿ�������ڶ��������ĵļн�
		static CCPoint circle[nCount];							///< ��������
		for(unsigned int i = 0;i < nCount; ++i) 
		{
			float rads	= i*coef;//����
			circle[i].x = m_pointCen.x + m_fRadius * cosf(rads);//��Ӧ�����x
			circle[i].y = m_pointCen.y + m_fRadius * sinf(rads);//��Ӧ�����y
		}

		CCDrawNode *pStencil=CCDrawNode::create();
		pStencil->drawPolygon(circle, nCount, green, 0, green);//������������!

		//����ģ��
		CCClippingNode* pClip = (CCClippingNode*)this->getChildByTag(TAGCLIPNODE);
		pClip->setStencil(pStencil);
	} while (0);

}

void CircleClipNode::setEnd(bool var)
{
	this->m_bEnd = var;
}

bool CircleClipNode::getEnd()
{
	return this->m_bEnd;
}

///@brief ��ʼ�˶�
///@param[in/out] 
///@return 
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-7-8 10:15
void CircleClipNode::startClip()
{
	m_bStartClip = true;
	this->unschedule(schedule_selector(CircleClipNode::onRunClip));
}

void CircleClipNode::onEnter()
{
	CCNode::onEnter();
	this->scheduleUpdate();
}

void CircleClipNode::onExit()
{
	CCNode::onExit();
}

void CircleClipNode::onRunClip( float delta )
{
	if (m_bRunClip)
	{
		m_fRadius += 2;
		m_uiRunclip++;
		if (m_uiRunclip > 10)
		{
			m_bRunClip = false;
			m_uiRunclip = 0;
		}

	}
	else
	{
		m_fRadius -= 2;
		m_uiRunclip++;
		if (m_uiRunclip > 10)
		{
			m_bRunClip = true;
			m_uiRunclip = 0;
		}
	}

	//����Բ������
	static ccColor4F green	= {0, 1, 0, 1};					///< ������ɫ,��������û��ʵ����û�л���,���Կ�������ɫ
	const int nCount		= 100;							///< Բ����ʵ���Կ����������,������������100������ģ��԰
	const float coef		= 2.0f * (float)M_PI/nCount;	///< ����ÿ�������ڶ��������ĵļн�
	static CCPoint circle[nCount];							///< ��������
	for(unsigned int i = 0;i < nCount; ++i) 
	{
		float rads	= i*coef;//����
		circle[i].x = m_pointCen.x + m_fRadius * cosf(rads);//��Ӧ�����x
		circle[i].y = m_pointCen.y + m_fRadius * sinf(rads);//��Ӧ�����y
	}

	CCDrawNode *pStencil=CCDrawNode::create();
	pStencil->drawPolygon(circle, nCount, green, 0, green);//������������!

	//����ģ��
	CCClippingNode* pClip = (CCClippingNode*)this->getChildByTag(TAGCLIPNODE);
	pClip->setStencil(pStencil);
}
