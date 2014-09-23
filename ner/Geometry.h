/**
*@file Geometry.h
*@brief һЩ���ü����㷨
*
*��ϸ����
*
*@author DionysosLai��email: 906391500@qq.com
*@version 1.0
*@data 2014-7-28 16:24
*/

#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include "cocos2d.h"

///@brief ���
///@param[in/out] 
///@pre ǰ������ 
///@return 
double vectorProduct(const double& x1, const double& y1, const double& x2, const double& y2);  // ����ʽ  

///@brief �ж����ߵĹ���
///���߶�P1Ϊ�ο�����
///@param[in] p1--�߶�1��p2--�߶�2
///@pre P1��P1�����й����˵�
///@return 1--��� 0 -- ���� -1---�ұ�
int polyLineDerection(const cocos2d::CCPoint& p1, const cocos2d::CCPoint& p0, const cocos2d::CCPoint& p2);

///@brief �ж��߶���ֱ���Ƿ��ཻ
///@param[in] p0,p1--�߶������˵㣬 q0,q1--ֱ��������ֵ
///@pre 
///@return true---���߶��ϣ� false---�����߶���
bool straightLineIsIntersect(const cocos2d::CCPoint& p0, const cocos2d::CCPoint& p1, const cocos2d::CCPoint& q0, const cocos2d::CCPoint& q1);

///@brief �жϵ��Ƿ��ھ�����s
///@param[in|out] p0--�� r1--�������� width--���ο� heigth---���θ�
///@pre 
///@return true--�ھ����ڣ� false---�ھ�����
bool pointIsInRect( const cocos2d::CCPoint& p0, const cocos2d::CCPoint& r1, const float& width, const float& heigth );

///@brief �жϵ��Ƿ��ھ�����
///@param[in] p0--�㣬p1,p2--���ε�һ���Խ��߶˵�
///@pre 
///@return true---���߶��ϣ� false---�����߶���
bool pointIsInRect( const cocos2d::CCPoint& p0, const cocos2d::CCPoint& p1, const cocos2d::CCPoint& p2 );

///@brief �㵽�߶����һ����
///@param[in] p0--Ҫ�жϵ㣬 s0��s1--�߶������˵�
///@return crosspoint---����ĵ�
cocos2d::CCPoint nearestPointToSegmentLine( const cocos2d::CCPoint& p0, const cocos2d::CCPoint& s0, const cocos2d::CCPoint& s1 );

///@brief �ж����������Ƿ��ཻ
///@param[in] aa,bb--����1һ���Խ��߶˵㣬 cc,dd--����2һ���Խ��߶˵�
///@pre 
///@return true---�ཻ�� false---���ཻ
bool isRectsInterSect(const cocos2d::CCPoint& aa, const cocos2d::CCPoint& bb, const cocos2d::CCPoint& cc, const cocos2d::CCPoint& dd);

///@brief �жϵ��Ƿ����߶���
///@param[in] p0--�㣬p1,p2--�߶������˵�
///�жϵ��Ƿ����߶��ϣ�
///���ΪQ���߶�ΪP1P2 ���жϵ�Q�ڸ��߶��ϵ������ǣ�( Q - P1 ) �� ( P2 - P1 ) = 0 
///�� Q ���� P1��P2Ϊ�ԽǶ���ľ����ڡ�ǰ�߱�֤Q����ֱ��P1P2�ϣ������Ǳ�֤Q�㲻��
///�߶�P1P2���ӳ��߻����ӳ�����
///@return true---���߶��ϣ� false---�����߶���
bool pointIsAtLine(const cocos2d::CCPoint& p0, const cocos2d::CCPoint& p1, const cocos2d::CCPoint& p2);

///@brief �жϵ��Ƿ��ڶ���Σ��������ڱ��ϣ�///@param[in] p0--Ҫ�жϵ㣬 poly--����ε㼯�ϣ� numberOfPoints--����ε�����///@return true---���ڶ�����ڣ� false---�㲻�ڶ������
bool pointIsInPolygon(const cocos2d::CCPoint& p0, cocos2d::CCPoint* poly, const unsigned int& numberOfPoints);

///@brief �жϵ��Ƿ���԰��
///@param[in/out] 
///@pre ǰ������ 
///@return true---����԰�ڣ� false--���ڶ������
bool pointInInCircle(const cocos2d::CCPoint& p0, const cocos2d::CCPoint& r0, const float& radius);

///@brief �ж��߶����߶��Ƿ��ཻ
///@param[in] aa,bb--�߶�1�����˵㣬 cc,dd--�߶�1�����˵�
///@pre 
///@return true---���߶��ϣ� false---�����߶���
bool segmentLineIsIntersect(const cocos2d::CCPoint& aa, const cocos2d::CCPoint& bb, const cocos2d::CCPoint& cc, const cocos2d::CCPoint& dd);

#endif	///<(__GEOMETRY_H__)