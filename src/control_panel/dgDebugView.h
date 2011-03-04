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
#include "fpsViewer.h"

class dgDebugView {

	
	public:
	
	void setup();
	void draw();
	void drawSceneFbo (ofxFBOTexture * texture, float width, float height, float scale);
	void drawCurrentVideo (ofTexture * videoTexture, float width, float height, float scale);
	void onBeatEvent();
	
	bool	visible;
	
	private:
	
	ofImage			logo;
	
	ofTrueTypeFont	digitalFont;
	ofTrueTypeFont	digitalFont_tiny;
	
	fpsViewer		fps;
	
	float			beatLatency;
	float			currentTime;
	
	
	
	
};

#endif