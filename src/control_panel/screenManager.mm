/*
 *  screenManager.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 23/03/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "screenManager.h"
#include "ofxCocoa.h"

void screenManager::setup () {
	
	
	uniqueScreenMode = true;
	mainScreen  = MSA::ofxCocoa::getSizeForScreen(0);
	if ( MSA::ofxCocoa::getNumberOfScreen() > 1 ) {
		currentScreen = 1;
		mainScreen  = MSA::ofxCocoa::getSizeForScreen(currentScreen);
		secondScreen = MSA::ofxCocoa::getSizeForScreen(currentScreen-1);
		uniqueScreenMode = false;
		
	} else {
		mainScreen  = MSA::ofxCocoa::getSizeForScreen(0);
		uniqueScreenMode = true;
	}


}

ofPoint screenManager::toggleCurrentScreen () {
	
		if ( uniqueScreenMode ) {
		
		return mainScreen;
		
		} else {
	
		if ( currentScreen == 0 ) {
			currentScreen = 1;
			mainScreen  = MSA::ofxCocoa::getSizeForScreen(currentScreen);
			secondScreen = MSA::ofxCocoa::getSizeForScreen(currentScreen-1);
			return mainScreen; 
		}
		
		
			if ( currentScreen == 1 ) {
				currentScreen = 0;
				mainScreen  = MSA::ofxCocoa::getSizeForScreen(currentScreen);
				secondScreen = MSA::ofxCocoa::getSizeForScreen(currentScreen+1);
				return mainScreen;
			}
		
	}
		
			
}