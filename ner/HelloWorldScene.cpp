#include "HelloWorldScene.h"

USING_NS_CC;

static const float PTM_RATIO = 32.0f;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

	creatWord();
	addMatter();

	this->scheduleUpdate();

    m_mouseJoint = NULL;

    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

void HelloWorld::creatWord( void )
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	/// ��������
	b2Vec2 gravity(0.0f,-30.0f);   
	m_world = new b2World(gravity);  
	m_world->SetAllowSleeping(true);		///< ���������еĸ�������(����������ײʱ�������롰���ߡ�);
	m_world->SetContinuousPhysics(true);	///< �������������ģ��

	/// �����߽�-�����������
	b2BodyDef groundBodyDef;  
	groundBodyDef.position.SetZero();	///< body�������½�
	b2Body *groundBody = m_world->CreateBody(&groundBodyDef);		///< ʹ��world���󴴽��������壬����ֱ��new����Ϊworld�������һЩ�ڴ���������  
	b2EdgeShape groundBox;				///< Ϊ��Ļ��ÿһ���߽紴��һ�������shape����Щ��shape��������һЩ�߶Ρ�ע�⣬���ǰ�����ת�����ˡ�meter����ͨ������֮ǰ����ı�����ʵ�ֵġ�
	//	b2PolygonShape groundBox;
	b2FixtureDef boxShapeDef;			///< һ��fixture���壬ָ��shapeΪEdge shape
	// 	boxShapeDef.filter.categoryBits	= BOX2D_MASK_BALL | BOX2D_MASK_BASKET;
	// 	boxShapeDef.filter.maskBits		= BOX2D_MASK_BALL | BOX2D_MASK_BASKET;
	boxShapeDef.shape = &groundBox;
	/// body������Ϊÿһ��shape����һ��fixture���� ע�⣺һ��body������԰����������fixture����
	groundBox.Set(b2Vec2(0,0), b2Vec2(visibleSize.width/PTM_RATIO,0));
	groundBody->CreateFixture(&boxShapeDef);
	groundBox.Set(b2Vec2(0,0), b2Vec2(0, visibleSize.height/PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);
	groundBox.Set(b2Vec2(0, visibleSize.height/PTM_RATIO), 
		b2Vec2(visibleSize.width/PTM_RATIO, visibleSize.height/PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);
	groundBox.Set(b2Vec2(visibleSize.width/PTM_RATIO,
		visibleSize.height/PTM_RATIO), b2Vec2(visibleSize.width/PTM_RATIO, 0));
	groundBody->CreateFixture(&boxShapeDef);
}

void HelloWorld::addMatter()
{
	// Create ball body and shape �������body
	CCSprite* ball = CCSprite::create("PIC_YLYZ.png");
	ball->setPosition(ccp(640, 400));
	this->addChild(ball, 1);
// 
// 	b2PolygonShape shape;
// 	shape.SetAsBox(0.6f, 0.125f);
// 
// 	b2FixtureDef fd;
// 	fd.shape = &shape;
// 	fd.density = 20.0f;
// 	fd.friction = 0.2f;
// 
// 	b2RevoluteJointDef jd;
// 	jd.collideConnected = false;
// 
// 	const float32 y = 25.0f;
// 	b2Body* prevBody = ground;
// 	for (int32 i = 0; i < 10; ++i)
// 	{
// 		b2BodyDef bd;
// 		bd.type = b2_dynamicBody;
// 		bd.position.Set(0.5f + i, y);
// 		b2Body* body = m_world->CreateBody(&bd);
// 		body->CreateFixture(&fd);
// 
// 		b2Vec2 anchor(float32(i), y);
// 		jd.Initialize(prevBody, body, anchor);
// 		m_world->CreateJoint(&jd);
// 
// 		prevBody = body; 
// 	}


	b2Body *body;

	b2BodyDef ballBodyDef;
	ballBodyDef.type = b2_dynamicBody;	///< ָ��body������Ϊdynamic body��Ĭ��ֵ��static body������ζ���Ǹ�body���ܱ��ƶ�Ҳ���������档
	ballBodyDef.position.Set(640/PTM_RATIO, 400/PTM_RATIO);
	ballBodyDef.userData = ball;		///< ����body��user data����Ϊ�����顣���������κζ��������ǣ������óɾ����ܷ��㣬�ر��ǵ�����body��ײ��ʱ�������ͨ����������Ѿ������ȡ������Ȼ����һЩ�߼�����
	body = m_world->CreateBody(&ballBodyDef);

	b2CircleShape circle;
	circle.m_radius = ball->getContentSize().width/2.0f/PTM_RATIO;

	b2FixtureDef ballShapeDef;
	ballShapeDef.shape = &circle;
	// 		ballShapeDef.filter.categoryBits	= BOX2D_MASK_BALL;
	// 		ballShapeDef.filter.maskBits		= BOX2D_MASK_BALL;
	ballShapeDef.density = 1.0f;		///< ��λ������������ܶȣ�����ˣ�һ��������ܶ�Խ����ô�����и������������Ȼ�ͻ�Խ�����ƶ�. 
	ballShapeDef.friction = 0.2f;		///< ����Ħ���������ķ�Χ��0-1.0�� 0��ζ��û��Ħ����1�������Ħ���������Ʋ�����Ħ����	
	ballShapeDef.restitution = 0.5f;		///< �ظ��������ķ�ΧҲ��0��1.0. 0��ζ�Ŷ�����ײ֮�󲻻ᷴ����1��ζ������ȫ������ײ������ͬ�����ٶȷ�����
	body->CreateFixture(&ballShapeDef);
}

void HelloWorld::update( float delta )
{
	m_world->Step(delta, 10, 10);

	/// ʹ���ǵľ���ƥ��������档
	for (b2Body *b = m_world->GetBodyList(); b; )
	{

		///����world�������������body��Ȼ��body��user data�����Ƿ�Ϊ�գ������Ϊ�գ��Ϳ���ǿ��ת���ɾ�����󡣽��������Ϳ��Ը���body��λ�������¾����λ���ˡ�
		if (b->GetUserData() != NULL)
		{
			b2Body* b2node = b;
			b = b2node->GetNext();
			CCSprite* ballData = (CCSprite*)b2node->GetUserData();
			ballData->setPosition(ccp(b2node->GetPosition().x*PTM_RATIO, 
				b2node->GetPosition().y*PTM_RATIO));
			ballData->setRotation(-1*CC_RADIANS_TO_DEGREES(b2node->GetAngle()));
		}
		else
		{
			b = b->GetNext();
		}
	}
}

bool HelloWorld::ccTouchBegan( CCTouch *pTouch, CCEvent *pEvent )
{
	CCPoint point = pTouch->getLocation();

	do 
	{
		b2Vec2 vec(point.x/PTM_RATIO,point.y/PTM_RATIO);
		//	b2Vec2 vec = b2Vec2(touchPoint.x,touchPoint.y);

		if(m_mouseJoint != NULL)
		{
			return false;
		}

		// Make a small box.
		b2AABB aabb;
		b2Vec2 d;
		d.Set(0.001f, 0.001f);
		aabb.lowerBound = vec - d;
		aabb.upperBound = vec + d;

		b2BodyDef bodyDef;
		b2Body *m_groundBody = m_world->CreateBody(&bodyDef);

		// Query the world for overlapping shapes.
		QueryCallback callback(vec);
		m_world->QueryAABB(&callback, aabb);

		if (callback.m_fixture)
		{
			b2Body* body = callback.m_fixture->GetBody();
			b2MouseJointDef md;
			md.bodyA = m_groundBody;//һ��Ϊ����߽�    
			md.bodyB = body;//��Ҫ�϶������� 
			md.target = vec;
			md.maxForce = 1000.0f * body->GetMass();
			m_mouseJoint = (b2MouseJoint*)m_world->CreateJoint(&md);
			body->SetAwake(true);

			//		CCLog("touch bengin \n");

			return true;
		}
		return false;
	} while (0);
}

void HelloWorld::ccTouchMoved( CCTouch *pTouch, CCEvent *pEvent )
{
	CCPoint point = pTouch->getLocation();

	do 
	{

		b2Vec2 vecMouse;  
		vecMouse.Set((point.x)/PTM_RATIO, (point.y)/PTM_RATIO);  
		//�ı�ؽ�λ��.  
		m_mouseJoint->SetTarget(vecMouse);
	} while (0);


	if(m_mouseJoint == NULL )  
		return;  
}

void HelloWorld::ccTouchEnded( CCTouch *pTouch, CCEvent *pEvent )
{
	CCPoint point = pTouch->getLocation();

	do 
	{
		//���ٹؽ�.  
		if(m_mouseJoint != NULL)  
		{  
			m_world->DestroyJoint(m_mouseJoint);  
			m_mouseJoint  =NULL;  
		}  
	} while (0);
}

void HelloWorld::onEnter()
{
	CCLayer::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

void HelloWorld::onExit()
{
	CCLayer::onExit();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}