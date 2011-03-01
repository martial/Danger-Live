#include "ofMain.h"
#include "dangerApp.h"

#ifdef _USE_COCOA_WINDOW
#include "ofxCocoa.h"
#else
#include "ofAppGlutWindow.h"
#endif


//========================================================================
int main() {
	
	
	int w = 3360;
	int h = 1080;
	
	#ifdef _USE_COCOA_WINDOW
    MSA::ofxCocoa::InitSettings			initSettings;
	initSettings.isOpaque				= true;
	initSettings.windowLevel			= NSNormalWindowLevel;
	initSettings.hasWindowShadow		= false;
	initSettings.numFSAASamples			= 4;
	initSettings.initRect.size.width	= w;
	initSettings.initRect.size.height	= h;
	initSettings.windowMode				= OF_WINDOW;
	
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
	
	ofSetupOpenGL(&window, w, h, 0);

	ofRunApp(new dangerApp());

}
