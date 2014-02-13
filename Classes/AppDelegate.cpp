#include "Config.h"
#include "AppDelegate.h"
#include "SoushenScene.h"
#include "Game/GameManager.h"
#include "TcpNetwork/TcpNet.h"
#include "Worker/Tcp.h"
#include "SsCfg.h"
#include "../Packet/Builder.h"
#include "System/Sleep.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = HelloWorld::scene();

    // run
    //pDirector->runWithScene(pScene);

	View::_gamemanager::instance()->DisplayNowScene(View::SCENE_INIT);

	//connect 
	//TcpNetWork::_TcpNet.connect("127.0.0.1", 7770, 50);

	sSCfg.load();

	Worker::_tcp.initTcpInfo(sSCfg.tcpHost.c_str(), sSCfg.tcpPort);
	Worker::_tcp.start();
	
	System::Sleep(5000);
	Packet::LogIn ul;
	ul.SetUsername("test1@pope");
	ul.send();

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
