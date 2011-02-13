/*
 *  dgDebugView.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 13/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _DG_DEBUG_VIEW
#define _DG_DEBUG_VIEW

#include "ofMain.h"
#include "ofxFBOTexture.h"
#include "ofxUtils.h"


class dgDebugView {

	
	public:
	
	void setup();
	void draw();
	void drawSceneFbo (ofxFBOTexture & texture);
	void onBeatEvent();
	
	bool	visible;
	
	private:
	
	ofTrueTypeFont	digitalFont;
	ofTrueTypeFont	digitalFont_tiny;
	float	beatLatency;
	float	currentTime;
	
	
};

#endif