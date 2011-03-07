#include "ofMain.h"
#include "dangerApp.h"

#define _USE_COCOA_WINDOW

//#define _USE_FENSTER

#ifdef _USE_COCOA_WINDOW
#include "ofxCocoa.h"
#else
#include "ofAppGlutWindow.h"
#endif


//========================================================================
int main() {
	
	
	int w = 1920;
	int h = 1080;
	
	#ifdef _USE_COCOA_WINDOW
    MSA::ofxCocoa::InitSettings			initSettings;
	initSettings.isOpaque				= true;
	//initSettings.windowLevel			= NSNormalWindowLevel;
	initSettings.windowLevel			= NSMainMenuWindowLevel + 1;

	initSettings.hasWindowShadow		= false;
	initSettings.numFSAASamples			= 4;
	initSettings.initRect.size.width	= w;
	initSettings.initRect.size.height	= h;
	initSettings.windowMode				= OF_FULLSCREEN;
	
	// to go fullscreen across all windows:
	//initSettings.windowStyle			= NSBorderlessWindowMask;
	//initSettings.initRect				= MSA::ofxCocoa::rectForMainScreen();
	//initSettings.initRect				= MSA::ofxCocoa::rectForAllScreens();
	
	MSA::ofxCocoa::AppWindow window(initSettings);
	w = h = 0;
	#else
	
	//int wind
	ofAppGlutWindow window;
	 
	#endif
	
	ofSetupOpenGL(&window, w, h, OF_FULLSCREEN);
	
	dangerApp* app = new dangerApp;
	
#ifdef _USE_FENSTER
	ofxFenster fenster;
	fenster.init(app);
#endif

	ofRunApp(app);

}
