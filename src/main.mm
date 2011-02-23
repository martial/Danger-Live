//
//  main.mm
//  ofxCocoaMSALibTest
//
//  Created by jason van cleave on 1/9/11.
//  Copyright jasonvancleave.com 2011. All rights reserved.
//

#include "ofMain.h"
#include "dangerApp.h"
#include "ofxCocoa.h"

//========================================================================
int main() {

    MSA::ofxCocoa::InitSettings			initSettings;
	initSettings.isOpaque				= true;
	initSettings.windowLevel			= NSMainMenuWindowLevel + 1;
	initSettings.hasWindowShadow		= false;
	initSettings.numFSAASamples			= 1;
	initSettings.initRect.size.width	= 3360;
	initSettings.initRect.size.height	= 1080;
	initSettings.windowMode				= OF_WINDOW;
	
	// to go fullscreen across all windows:
	//initSettings.windowStyle			= NSBorderlessWindowMask;
	//initSettings.initRect				= MSA::ofxCocoa::rectForMainScreen();
	  //initSettings.initRect				= MSA::ofxCocoa::rectForAllScreens();
	
	MSA::ofxCocoa::AppWindow window(initSettings);
	ofSetupOpenGL(&window, 0, 0, 0);

	ofRunApp(new dangerApp());

}
