/**Copyright (c) 2014, �㶫С��ſƼ����޹�˾
*All rights reserved.
*@file ShaderNode.h
*@brief ���Shader�ļ�
*@author ���书��email: 906391500@qq.com
*@version 1.0
*@data 2014-9-5 16:32
*/
#include "cocos2d.h"

class ShaderNode : public cocos2d::CCNode
{
public:
	ShaderNode();
	~ShaderNode();

	bool initWithVertex(const char *vert, const char *frag);
	void loadShaderVertex(const char *vert, const char *frag);
	void listenBackToForeground(cocos2d::CCObject *obj);

	virtual void update(float dt);
	virtual void setPosition(const cocos2d::CCPoint &newPosition);
	virtual void draw();

	static ShaderNode* shaderNodeWithVertex(const char *vert, const char *frag);

private:

	cocos2d::ccVertex2F m_center;
	cocos2d::ccVertex2F m_resolution;
	float      m_time;
	GLuint     m_uniformCenter, m_uniformResolution, m_uniformTime;
	std::string m_vertFileName;
	std::string m_fragFileName;
};
