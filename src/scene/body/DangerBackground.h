/*
 *  DangerBackground.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include "ofMain.h"
#include "ofxUtils.h"
#include "ofxVec2f.h"
#include "ofxDirList.h"
#include "dgSceneEffects.h"

class DangerBackground {

	
	public :
	DangerBackground();
	void setup();
	void update();
	void draw(int viewID);
	
	private:
	
	ofTrueTypeFont		digitalFont;
	ofImage				background;
	ofImage				digitalPlaceholder;
	vector<ofImage*>	digitalLeds;
	
	ofxDirList			DIR;
	
	
};