/**
*@file 
*@brief 
*
*��ϸ����
*
*@author DionysosLai��email: 906391500@qq.com
*@version 1.0
*@data 2014-7-28 16:26
*/
#include "Geometry.h"

USING_NS_CC;

double vectorProduct( const double& x1, const double& y1, const double& x2, const double& y2 )
{
	return (x1*y2-x2*y1);	///< ��� ������ѧ�����һ����
}

///@brief �ж����ߵĹ���
///���߶�P1Ϊ�ο�����
///@param[in] p1--�߶�1��p2--�߶�2
///@pre P1��P1�����й����˵�
///@return 1--��� 0 -- ���� -1---�ұ�
///@retval 
///@post
///@author DionysosLai,906391500@qq.com��
///@version 1.0
///@data 2014-04-10
int polyLineDerection( const cocos2d::CCPoint& p1, const cocos2d::CCPoint& p0, const cocos2d::CCPoint& p2 )
{
	float vectorProductResult = 0.0f;

	vectorProductResult = (float)vectorProduct(p1.x-p0.x, p1.y-p0.y, p2.x-p0.x, p2.y-p0.y);

	if (vectorProductResult < 1 && vectorProductResult > -1)
	{
		/*		CCLOG("p1p0 and p2p0 is at the same dereciton.");*/
		return 0;
	}

	if (vectorProductResult >= 1)
	{
		/*		CCLOG("p2p0 is at p1p0's left dereciotn.");*/
		return -1;
	}

	if (vectorProductResult <= -1)
	{
		/*		CCLOG("p2p0 is at p1p0's right dereciotn.");*/
		return 1;
	}
}

bool straightLineIsIntersect( const cocos2d::CCPoint& p0, const cocos2d::CCPoint& p1, const cocos2d::CCPoint& q0, const cocos2d::CCPoint& q1 )
{
	/// ���ж�q0��q1�ܷ����һ��ֱ��
	if (!q0.equals(q1))
	{
		/// ��q0 == p0 q1 == p1ʱ�����Ϊ0�� ֻ��Ҫ�ж��߶��Ƿ����ֱ�߼��ɡ�
		if (0 <= vectorProduct(p0.x-q0.x, p0.y-q0.y, q1.x-q0.x, q1.y-q0.y) * 
			vectorProduct(q1.x-q0.x, q1.y-q0.y, p1.x-q0.x, p1.y-q0.y))
		{
/*			CCLOG("straight line and segment line is intesect!");*/
			return false;
		}

/*		CCLOG("straight line and segment line isn't intesect!");*/
		return false;
	}

/*	CCLOG("straigth line cannnot be make up of q0 and q1!");*/
	return false;
}

///@brief �жϵ��Ƿ��ھ�����s
///@param[in|out] p0--�� r1--�������� width--���ο� heigth---���θ�
///@pre 
///@return true--�ھ����ڣ� false---�ھ�����
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-7-28 16:48
bool pointIsInRect( const cocos2d::CCPoint& p0, const cocos2d::CCPoint& r1, const float& width, const float& heigth )
{
	float xLeft = r1.x - width/2.f;
	float xRigth = r1.x + width/2.f;
	float yUp = r1.y + heigth/2.f;
	float yBottom = r1.y - heigth/2.f;

	if (p0.x >= xLeft && p0.x<= xRigth && p0.y >= yBottom && p0.y <= yUp)
	{
		return true;
	}

	return false;
}

///@brief �жϵ��Ƿ��ھ�����
///@param[in] p0--�㣬p1,p2--���ε�һ���Խ��߶˵�
///@pre 
///@return true---���߶��ϣ� false---�����߶���
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-7-28 16:54
bool pointIsInRect( const cocos2d::CCPoint& p0, const cocos2d::CCPoint& p1, const cocos2d::CCPoint& p2 )
{
	float xMax = 0, xMin, yMax = 0, yMin = 0;
	xMax = p1.x > p2.x ? p1.x : p2.x;
	xMin = p1.x > p2.x ? p2.x : p1.x;
	yMax = p1.y > p2.y ? p1.y : p2.y;
	yMin = p1.y > p2.y ? p2.y : p1.y;

	if ( p0.x >= xMin && p0.x <= xMax && p0.y >= yMin && p0.y <= yMax)
	{
/*		CCLOG("Point is at recangle.");*/
		return true;
	}
/*	CCLOG("Point isn't at recangle.");*/
	return false;
}

///@brief �㵽�߶����һ����
///@param[in] p0--Ҫ�жϵ㣬 s0��s1--�߶������˵�
///@return crosspoint---����ĵ�
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-7-28 16:58
cocos2d::CCPoint nearestPointToSegmentLine( const cocos2d::CCPoint& p0, const cocos2d::CCPoint& s0, const cocos2d::CCPoint& s1 )
{
	/// �ж��߶��Ƿ���һ����
	if (s0.equals(s1))
	{
		return s0;
	}

	/// ��ʼ����Ϊ0��
	CCPoint crossPoint = CCPointZero;
	do 
	{
		/// �ж��߶��Ƿ�ƽ����x��
		if (s0.y == s1.y)
		{
			crossPoint = ccp(p0.x, s0.y);
			break;
		}
		/// �ж��߶��Ƿ�ƽ����y��
		if (s0.x == s1.x)
		{
			crossPoint = ccp(s0.x, p0.y);
			break;
		}
		/// ����߶β��������������ֻ�ܲ���ֱ�߷��̷�ʽ�������
		float k = (s1.y - s0.y)/(s1.x - s0.x);		///< ���б��
		/// �߶�ֱ�߷��̣�	y = k* ( x - s0.x) + s0.y
		/// ���߷���Ϊ��	y = (-1/k) * (x - p0.x) + p0.y ��
		/// ������ֱ�߷��̽��
		float x = ( k*k * s0.x + k * (p0.y - s0.y ) + p0.x ) / ( k*k + 1);
		float y = k * ( x - s0.x) + s0.y;
		crossPoint = ccp(x, y);
		break;
	} while (0);

	/// �жϴ�ֱ�Ƿ����߶���
	if (pointIsAtLine(crossPoint, s0, s1))
	{
		return crossPoint;
	}
	else
	{
		/// ���������������˵㵽����ľ��룬ѡ����봹��Ͻ��Ķ˵㷵�ء�
		float distance1 = ccpDistance(crossPoint, s0);
		float distance2 = ccpDistance(crossPoint, s1);
		if (distance1 < distance2)
		{
			return s0;
		}
		else
		{
			return s1;
		}
	}
}

///@brief �ж����������Ƿ��ཻ
///@param[in] aa,bb--����1һ���Խ��߶˵㣬 cc,dd--����2һ���Խ��߶˵�
///@pre 
///@return true---�ཻ�� false---���ཻ
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-7-28 17:03
bool isRectsInterSect( const cocos2d::CCPoint& aa, const cocos2d::CCPoint& bb, const cocos2d::CCPoint& cc, const cocos2d::CCPoint& dd )
{
	CCPoint	centre1 = ccp((aa.x + bb.x)/2.0f, (aa.y + bb.y)/2.0f);	///< ����е�ֵ
	CCPoint	centre2 = ccp((cc.x + dd.x)/2.0f, (cc.y + dd.y)/2.0f);
	float	lengthX	= abs(centre1.x - centre2.x);	///< ��������������ĵľ��� 
	float	lengthY	= abs(centre1.y - centre2.y); 
	float	lengthRect1X	= abs(aa.x - bb.x);		///< ����������γ��Ϳ�
	float	lengthRect1Y	= abs(aa.y - bb.y);
	float	lengthRect2X	= abs(cc.x - dd.x);
	float	lengthRect2Y	= abs(cc.y - dd.y);

	/// �����ȥ1�ǵ�������õġ�
	return  (lengthX < (lengthRect1X + lengthRect2X)/2.0f-1 && lengthY < (lengthRect1Y + lengthRect2Y)/2.0f-1) ? true : false;
}

///@brief �жϵ��Ƿ����߶���
///@param[in] p0--�㣬p1,p2--�߶������˵�
///@pre 
///@return true---���߶��ϣ� false---�����߶���
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-7-28 17:14
bool pointIsAtLine( const cocos2d::CCPoint& p0, const cocos2d::CCPoint& p1, const cocos2d::CCPoint& p2 )
{
	/// ���ж��Ƿ������p1 p2Ϊ�Խ��ߵľ�����
	if (pointIsInRect(p0, p1, p2))
	{
		/// �ж�p1p0, p2p0�Ƿ���
		if (0 == polyLineDerection(p0, p1, p2))
		{
			/*			CCLOG("Point in at the line.");*/
			return true;
		}

		/*		CCLOG("Point isn't at the line.");*/
		return false;
	}

	// 	CCLOG("Point isn't at the line.");
	return false;
}

///@brief �ж��߶����߶��Ƿ��ཻ
///@param[in] aa,bb--�߶�1�����˵㣬 cc,dd--�߶�1�����˵�
///@pre 
///@return true---���߶��ϣ� false---�����߶���
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-7-28 17:35
bool segmentLineIsIntersect( const cocos2d::CCPoint& aa, const cocos2d::CCPoint& bb, const cocos2d::CCPoint& cc, const cocos2d::CCPoint& dd )
{
	/// �������߶��γɵľ��β��غϣ�˵�������߶α�Ȼ���ཻ
	if (!isRectsInterSect(aa, bb, cc, dd))
	{
		return false;
	}

	/// ������߻������ ע��"="�������
	if (0 < vectorProduct(aa.x-cc.x, aa.y-cc.y, dd.x-cc.x, dd.y-cc.y) * 
		vectorProduct(dd.x-cc.x, dd.y-cc.y, bb.x-cc.x, bb.y-cc.y) &&
		0 < vectorProduct(cc.x-aa.x, cc.y-aa.y, bb.x-aa.x, bb.y-aa.y) * 
		vectorProduct(bb.x-aa.x, bb.y-aa.y, dd.x-aa.x, dd.y-aa.y))
	{
		return true;
	}
	return false; 
}

///@brief �жϵ��Ƿ��ڶ���Σ��������ڱ��ϣ�
///@param[in] p0--Ҫ�жϵ㣬 poly--����ε㼯�ϣ� numberOfPoints--����ε�����
///@return true---���ڶ�����ڣ� false---�㲻�ڶ������
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-7-28 17:07
bool pointIsInPolygon( const cocos2d::CCPoint& p0, cocos2d::CCPoint* poly, const unsigned int& numberOfPoints )
{
	unsigned int count  = 0;		///< �����������L�����εĽ�������
	cocos2d::CCSize	winsize = CCDirector::sharedDirector()->getWinSize();
	/// �ѵ�p0����������һ������L��
 	CCPoint leftPoint = ccp(-100.f, p0.y);
 	CCPoint rightPoint = p0;


	/// �ж�ÿ����
	for (unsigned int i = 0; i < numberOfPoints-1; i++)
	{
		/// ���жϵ�p0�Ƿ��ڱ�s�ϣ�
		if (pointIsAtLine(p0, poly[i], poly[(i+1)%(numberOfPoints)]))
		{
/*			CCLOG("Point is at the %dth line", i);*/

			return true;
		}

		/// �жϱ�s�Ƿ���ƽ���ߣ�
		if (poly[i].y != poly[(i+1)%(numberOfPoints)].y)
		{		
			do 
			{
				/// �жϱ�s���Ƿ��ж˵���L�� ͬʱ ���жϸõ��Ƿ��Ǳ�s������ϴ��һ����
				if (pointIsAtLine(poly[i], leftPoint, rightPoint))
				{
					if (poly[i].y > poly[(i+1)%(numberOfPoints)].y)
					{
						count += 1;
					}
					break;
				}	
				if (pointIsAtLine(poly[(i+1)%(numberOfPoints)], leftPoint, rightPoint))
				{
					if (poly[i].y < poly[(i+1)%(numberOfPoints)].y)
					{
						count += 1;
					}

					break;
				}	

				/// �����sû�ж˵���L�ϣ����ж�s��L�Ƿ��ཻ
				if (segmentLineIsIntersect(leftPoint, rightPoint, poly[i], poly[(i+1)%(numberOfPoints)]))
				{
					count += 1;
				}	
			} while (0);
		}
	}
	if (count%2 == 1)
	{
//		CCLOG("true");
		return true;
	}
	else
	{
//		CCLOG("false");
		return false;
	}

// 	if (1 == count%2)
// 	{
// /*		CCLOG("Point is in polygon!");*/
// 		return true;
// 	}
// 	else
// 	{
// /*		CCLOG("Point is in polygon!");*/
// 		return false;
// 	}
}

///@brief �жϵ��Ƿ���԰��
///@param[in/out] 
///@pre ǰ������ 
///@return true---����԰�ڣ� false--���ڶ������
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-7-28 17:29
bool pointInInCircle( const cocos2d::CCPoint& p0, const cocos2d::CCPoint& r0, const float& radius )
{
	if (ccpDistance(p0, r0) < radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void onWordVisible( cocos2d::CCSprite* node )
{
	CCActionInterval*  action = CCFadeOut::create(1.f);
	node->stopAllActions();
	node->setVisible(true);
	node->setOpacity(255);
	node->runAction( CCSequence::create( CCDelayTime::create(1.0f), action,  NULL));
}
