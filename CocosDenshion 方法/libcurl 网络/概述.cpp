2014-02-28
	Cocos2D-x��ʹ��libcurl��c�����ӿڡ����Ҫ�ڳ�����ʹ��libcurl������Ҫ����ȫ�ֵ�
��ʼ������Щ��ʼ��һ���ڳ���Ŀ�ʼ���ó�ʼ������������ֻ����һ�Ρ�ʹ��curl_global_init
��������ȫ�ֳ�ʼ�����ú���ͨ�����������������������Ӧ�������£�E:\Cocos2d-x\cocos2d-x-2.2.2\cocos2dx\platform\third_party\win32\curl
#define CURL_GLOBAL_SSL (1<<0)		///< ��libcurl��SSL(Secure Sockets Layer, ��ȫ�׽Ӳ�)��������SSL��
									///< ȷ�����������紫���У����ᱻ�����ͺͽ�ȡ��
#define CURL_GLOBAL_WIN32 (1<<1)	///< ��windows����ϵͳ�ϣ�libcurl��ʼ��win32�׽��ֵ����ݡ�
									///< û����ȷ�ĳ�ʼ������ĳ��򽫲�����ȷ��ʹ���׽���
#define CURL_GLOBAL_ALL (CURL_GLOBAL_SSL|CURL_GLOBAL_WIN32) ///< ʹ��Ĭ�ϲ�����ʼ��������֪���ڲ�ģ��
#define CURL_GLOBAL_NOTHING 0
#define CURL_GLOBAL_DEFAULT CURL_GLOBAL_ALL

�����curl_easy_perform֮ǰ����curl_global_init ��������ȫ�ֳ�ʼ������ô���ֻ��Զ���ʹ��Ĭ�ϵĳ�ʼ��ģʽ��ִ�С�