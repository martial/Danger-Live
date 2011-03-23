/*
 *  screenManager.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 23/03/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _SCREEN_MNG
#define _SCREEN_MNG

#include "ofMain.h"


class screenManager {
	

	public : 
	void setup();
	
	bool uniqueScreenMode;
	ofPoint mainScreen;
	ofPoint secondScreen;
	ofPoint toggleCurrentScreen();
	int		currentScreen;
	
	
	
};


#endif