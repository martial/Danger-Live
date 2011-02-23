/*
 *  dgAbstractEffect.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _DG_ABSTRACT_EFFECT
#define _DG_ABSTRACT_EFFECT

#include "ofMain.h"
#include "ofxFBOTexture.h"


class dgAbstractEffect {

public:
	
	virtual void setup(string name);
	virtual void init();
	virtual void update();
	virtual void draw(ofxFBOTexture & fbo);
	
	virtual ofxFBOTexture * draw(ofxFBOTexture & fbo, int x, int y);
	
	string name;
	
};

#endif