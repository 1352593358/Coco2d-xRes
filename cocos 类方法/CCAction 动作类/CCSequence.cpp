    CCFiniteTimeAction*  action = CCSequence::create(
        CCPlace::create(ccp(200,200)),
        CCShow::create(),
        CCMoveBy::create(1, ccp(100,0)),
		/// �ص������Ķ���  ����2��ͨ����Ӧѡ������ú������ƣ�
        CCCallFunc::create(this, callfunc_selector(ActionSequence2::callback1)),
        CCCallFuncN::create(this, callfuncN_selector(ActionSequence2::callback2)),
		/// ���һ�����������ݶ���
        CCCallFuncND::create(this, callfuncND_selector(ActionSequence2::callback3), (void*)0xbebabeba),
        NULL);