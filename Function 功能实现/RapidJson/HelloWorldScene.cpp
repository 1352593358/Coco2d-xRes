#include "HelloWorldScene.h"
#include "AppMacros.h"

#include "cocos2d.h"
#include "../external/json/document.h"
#include "../external/json/writer.h"
#include "../external/json/stringbuffer.h"
#include "../external/json/rapidjson.h"

using namespace  rapidjson;

USING_NS_CC;


Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
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
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

	//////////////////////////////////////////////////////////////////////////
	/// ���ݶ�ȡ
	SSIZE_T size;
/*	FILE* file1 = fopen("test.json", "wr");*/
	unsigned char* ch = FileUtils::getInstance()->getFileData("test.json","r", &size);
	std::string data = std::string((const char* )ch, size);
	//////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////////////
	/// ���ݽ�����json��ʽ����
	Document doc;		///< ����һ��Document���� rapidJson����ز�������Document����
	doc.Parse<0>(data.c_str());	///< ͨ��Parse������Json���ݽ�������
	if (doc.HasParseError()) 
	{ 
		CCLOG("GetParseError %s\n",doc.GetParseError());
	} 
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	/// Json���ݶ�ȡ�͸���-----��ֵ����
	rapidjson::Value& valString = doc["hello1"];		///< ��ȡ����hello����ֵ���������ǵ�json�ĵ�����һ���ַ���
	if (valString.IsString())	///< �ж��Ƿ����ַ���
	{
		const char* ch = valString.GetString();
		log(ch);
		log(valString.GetString());
		valString.SetString("newString");
		log(valString.GetString());
	}
	rapidjson::Value& valArray = doc["a"];			///< ��ȡ����a��ֵ���������ǵ�json�ĵ�����һ������
	if (valArray.IsArray())							///< �ж�val������ �Ƿ�Ϊ���� ���ǵ�Tollgate����Ӧ��valueʵ��Ϊ����
	{
		for (int i = 0; i < valArray.Capacity(); ++i)
		{
			rapidjson::Value& first	= valArray[i];	///< ��ȡ��val�еĵ�i��Ԫ�� �������������json�ļ� val�й���4��Ԫ��
			CCLOG("%f", first.GetDouble());			///< ��valueת����Double���ʹ�ӡ���� ���Ϊ0.5
			first.SetDouble(10.f);
			CCLOG("%f", first.GetDouble());			///< ��valueת����Double���ʹ�ӡ���� ���Ϊ0.5S
		}
	}
	//////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	/// json���ݲ���---�Լ�����֮��ӳ�Ա����
	/// ���һ��String����	
	rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();	///< ��ȡ������ݵķ�����
	rapidjson::Value strObject(rapidjson::kStringType);					///< ����ַ�������1
	strObject.SetString("love");
	doc.AddMember("hello1", strObject, allocator);
/*	doc.AddMember("hello1", "love you", allocator);						///< ����ַ�������2:�������������һ������*/

	/// ���һ��null����
	rapidjson::Value nullObject(rapidjson::kNullType);
	doc.AddMember("null", nullObject, allocator);						///< �������������һ������

	/// ���һ���������
	rapidjson::Value array(rapidjson::kArrayType);		///< ����һ���������
	rapidjson::Value object(rapidjson::kObjectType);	///< ���������������
	object.AddMember("id", 1, allocator);
	object.AddMember("name", "lai", allocator);
	object.AddMember("age", "12", allocator);
	object.AddMember("low", true, allocator);
	array.PushBack(object, allocator);
	doc.AddMember("player", array, allocator);			///< ������������������ӵ�һ����Ϊ��player����������

	/// �����е����������һ����Ա����
	rapidjson::Value& aArray1 = doc["a"];
	aArray1.PushBack(2.0, allocator);
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	/// json���ݲ���---�Լ�����֮ɾ����Ա����
	/// ɾ�������Ա��������Ԫ��
	rapidjson::Value& aArray2 = doc["a"];	///< ��ȡ����a��ֵ���������ǵ�json�ĵ�����һ������
	aArray2.PopBack();		///< ɾ���������һ����Ա����

	if (doc.RemoveMember("i"))				///< ɾ����Ϊ��i���ĳ�Ա����
	{
		log("delet i member ok!");
	}
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	/// ��json��������д���ļ���---�Ƚ��ļ�ɾ������д������
	rapidjson::StringBuffer  buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	doc.Accept(writer);		

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	system("del E:\cocos2d-x-3.2rc0\tests\cpp-empty-test\Resources\test.josn");		///< �Ƚ��ļ�ɾ����---֮ǰ������ļ���ȡ���ݣ����ȷ������ļ�������
	FILE* file = fopen("test.json", "wb");

	if (file)
	{
		fputs(buffer.GetString(), file);
		fclose(file);
	}
#else if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	/// ԭ���࣬�����Ƚ��ļ���գ���д�롣����Ͳ�д�ˡ�
#endif
	//////////////////////////////////////////////////////////////////////////    
    return true;
}

