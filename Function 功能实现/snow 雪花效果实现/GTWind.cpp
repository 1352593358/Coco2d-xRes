#include "GTWind.h"

USING_NS_CC;

GTWind::GTWind(void)
{

}

GTWind::~GTWind(void)
{

}

void GTWind::showWind(void)
{
	//��ʼ��Ʈ������
	m_windDir = tag_wind_none;
	//������ֵ����������
	g = -4;
	//ÿһ֡�����ѩ����
	maxV = 2;
	//��ǰ��Ļ���ѩ����
	maxCount = 150;
	//����
	windVelocity = 0;
	winSize = CCDirector::sharedDirector()->getWinSize();
	//ʹ��SpriteBatchNode��ʼ����������ѩ������һ���ڴ棬
	//����ֻ��Ҫ����һ��OPENGL�滭���Ϳ��Թ�������ѩ�������Ч��
	CCSpriteBatchNode *spriteBatchNode = CCSpriteBatchNode::create("snow.png",300);
	addChild(spriteBatchNode,0,tag_batch_node);
	schedule(schedule_selector(GTWind::changeWind),5.0f);
	schedule(schedule_selector(GTWind::updataWind));
}


void GTWind::changeWind(float dt)
{
	int dir = (int)(CCRANDOM_0_1() * 3) +1;
	if(m_windDir==dir)
	{
		return;
	}
	m_windDir=dir;

	switch (m_windDir)
	{
	case tag_wind_none:
		//�涨ѩ��������ٶ�
		maxWindVelocity = 0;
		//��̬�ı��ٶ�
		schedule(schedule_selector(GTWind::upDataWindVelocity));
		break;
	case tag_wind_left:
		maxWindVelocity = 20;
		schedule(schedule_selector(GTWind::upDataWindVelocity));
		break;
	case tag_wind_right:
		maxWindVelocity = -20;
		schedule(schedule_selector(GTWind::upDataWindVelocity));
		break;
	default:
		break;
	}
}

void GTWind::upDataWindVelocity(float dt)
{
	int addV = maxWindVelocity - windVelocity;

	if(abs(addV)>10)
	{
		windVelocity += addV/10;
	}
	else if(abs(addV)>2 &&abs(addV)<=10)
	{
		windVelocity += addV/abs(addV);
	}
	else
	{
		windVelocity = maxWindVelocity;
		unschedule(schedule_selector(GTWind::upDataWindVelocity));
	}
}

void GTWind::updataWind(float dt)
{
	CCSpriteBatchNode *temSpriteBatchNode = (CCSpriteBatchNode *)getChildByTag(tag_batch_node);
	if(temSpriteBatchNode->getChildren()->count()<maxCount)
	{
		for(int i=0; i< maxV; i++)
		{
			//��SpriteBatchNode��ȡ��ͼ����sprite�������뵽SpriteBatchNode
			CCSprite* sprite = CCSprite::createWithTexture(temSpriteBatchNode->getTexture());
			temSpriteBatchNode->addChild(sprite);
			sprite->setScale(1.0f - ((int)(CCRANDOM_0_1() * 5)+5) / 10.0);
			//��ʼ��ÿ��ѩ����λ��
			if (windVelocity >0)
				sprite->setPosition(ccp(winSize.width+10, 1.0*((int)(CCRANDOM_0_1() * ((int)winSize.height+200)))));
			else
				sprite->setPosition(ccp(-10,1.0*((int)(CCRANDOM_0_1() * ((int)winSize.height+200)))));

			if (windVelocity <3 && windVelocity > -3)
				sprite->setPosition(ccp(1.0*((int)(CCRANDOM_0_1() * (int)winSize.height+240)), winSize.height+200));
				
		}
	}
	/// �ı�����ѩ������
	CCArray* allSprite=temSpriteBatchNode->getChildren();
	CCObject* pObject = NULL;
	CCARRAY_FOREACH(allSprite, pObject)
	{
		CCSprite* pChild = (CCSprite*) pObject;
		CCPoint pNow = pChild->getPosition();
// 		m_fSnowVelocityX += 0.01*windVelocity/pChild->getScale();
		pNow.x -= 0.08/pChild->getScale()*windVelocity;	///< ���ԽС��ƫ���ٶ�Խ��(���Ч����)
//		pNow.x -= pChild->getScale()*windVelocity;		///< ���ԽС��ƫ���ٶ�Խ��
/*		pNow.x -= m_fSnowVelocityX + 0.1 * windVelocity;*/
		pNow.y += g;
		pChild->setPosition(pNow);
		pChild->setRotation(pChild->getRotation()+0.1f);

// 		if(pChild->getPosition().x < -10 || pChild->getPosition().x > winSize.width+10 ||
// 			pChild->getPosition().y < -10 ||)
		/// ��x���ϸ��ݷ�Χ���ж�ѩ���Ƿ���ʧ����y���ϣ�����ѩ���Ĵ�С���ж���ʧ��λ�ã�ѩ��Խ����ʧ��y��ԽС��
		if (pChild->getPosition().x < -10 || pChild->getPosition().x > winSize.width+10 ||
				pChild->getPosition().y < (200 - pChild->getScale()*400))	///< 200��400 �����Լ�����ĻЧ���������������Ļ��320*480
		{
			if (windVelocity >0)
			{
/*				float randY = 1.0*(int)(CCRANDOM_0_1() * (int)(winSize.height+200) )*/
				/// ��ʼλ�� ���ٴ���0 ����Ļ�ұ�
				pChild->setPosition(ccp(winSize.width+10,	1.0*((int)(CCRANDOM_0_1() * ((int)winSize.height+200) )) ));
			}
			else
			{
				pChild->setPosition(ccp(-10,1.0*((int)(CCRANDOM_0_1() * ((int)winSize.height+200)))));
			}
			if (windVelocity <3 && windVelocity > -3)
			{
				pChild->setPosition(ccp( 1.0*((int)(CCRANDOM_0_1() * ((int)winSize.height+240))),winSize.height+10));
			}
			/// ��ǰx��ѩ���ٶ�Ϊ0;
// 			m_fSnowVelocityX = 0;
		}
	}
}