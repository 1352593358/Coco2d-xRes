/**
*@file ParticalNodeNode.h
*@brief ��д����Ч����---ʵ���Զ�ɾ������
*
*��ϸ����
*
*@author ���书��email: 906391500@qq.com
*@version 1.0
*@data 2014-7-1 12:00
*/

#ifndef __PARTICAL_NODE_H__
#define __PARTICAL_NODE_H__

#include "cocos2d.h"

class ParticalNode : public cocos2d::CCNode
{
public:
	ParticalNode();
	~ParticalNode();

	static ParticalNode* create(const char *plistFile);
	virtual bool init(const char *plistFile);

private:
	void initData(const char *plistFile);
	void deletePartical(float delta);

	cocos2d::CCParticleSystemQuad* m_pPartical;
};
#endif