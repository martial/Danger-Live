/*
 *  ofxUtils.h
 *  openFrameworks
 *
 *  Created by Chuck Chase on 30/04/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef OFXUTILS
#define OFXUTILS

#include "ofMain.h"
#include "ofxVec2f.h"
//#include "ofAddons.h"

class ofxUtils {
public:
	static ofPoint getSizeRatio ( int maxw, int maxh, float currw, float currh, bool keepInto = false );
	
};

#endif

