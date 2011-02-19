/*
 *  bloomSceneEffect.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _BLOOMFX
#define _BLOOMFX

#include "ofMain.h"
#include "ofxFBOTexture.h"
#include "dgAbstractEffect.h"
#include "flickrEffect.h"

#include "shaderBlur.h"
#include "bloomShader.h"

class bloomSceneEffect : public dgAbstractEffect {
	
public:
	void setup(string name);
	void init();
	void update();
	void draw(ofxFBOTexture & fbo);
	ofxFBOTexture * draw(ofxFBOTexture & fbo, int x, int y);
	
	
	float		blurPct;
	
private:
	
	float		counter;
	float		blackCounter;
	float		vel;
	
	
		
	shaderBlur			blur;
	bloomShader			bloom;
	
	
};

#endif