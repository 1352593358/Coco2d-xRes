/**
*@file CCBanPenetrateTouchLayer.cpp
*@brief ��ֹҳ������ľ������
*
*��ϸ����
*
*@author DionysosLai��email: 906391500@qq.com
*@version 1.0
*@data 2014-5-29 15:25
*/
CCBanPenetrateTouchLayer::~CCBanPenetrateTouchLayer()
{

}

bool CCBanPenetrateTouchLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	setTouchEnabled(true);

	return true;
}

bool CCBanPenetrateTouchLayer::ccTouchBegan( CCTouch* pTouch, CCEvent* pEvent )
{
	return true;//����true��ʾ���ɴ�����Ϣ,�������´���
}

void CCBanPenetrateTouchLayer::ccTouchMoved( CCTouch* pTouch, CCEvent* pEvent )
{

}

void CCBanPenetrateTouchLayer::ccTouchEnded( CCTouch* pTouch, CCEvent* pEvent )
{

}

void CCBanPenetrateTouchLayer::registerWithTouchDispatcher()
{
	//ʹ��-128��CCMenu���ȼ���ͬ,�����̵��¼�true//  
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -128, true);  
	 
	CCLayer::registerWithTouchDispatcher();  
}