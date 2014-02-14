#include "Config.h"
#include "main.h"
#include "AppDelegate.h"
#include "CCEGLView.h"

USING_NS_CC;

#define USE_WIN32_CONSOLE

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
//#ifdef USE_WIN32_CONSOLE  
//	AllocConsole();  
//#endif  

    // create the application instance
    AppDelegate app;
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setViewName("HelloCpp");
    eglView->setFrameSize(960, 640);
    return CCApplication::sharedApplication()->run();

	 
//#ifdef USE_WIN32_CONSOLE
//	FreeConsole();
//#endif
}
