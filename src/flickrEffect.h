/*
 *  flickrEffect.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _DGFLICKREFFECT
#define _DGFLICKREFFECT

#include "ofMain.h"
#include "dgAbstractEffect.h"
#include "ofxFBOTexture.h"

class flickrEffect : public dgAbstractEffect {
	public:
	void setup(string name);
	void init();
	void update();
	void draw(ofxFBOTexture & fbo);
	
private:
	
	float		counter;
	float		blackCounter;
	float		vel;
	
};

#endif
