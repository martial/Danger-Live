/*
 *  colorShader.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 16/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _CLR_SHADER
#define _CLR_SHADER

#include "ofMain.h"
#include "ofxShader.h"
#include "ofxFBOTexture.h"

class colorShader {
	
public:
	
	void setup(int fboW, int fboH);
	
	void beginRender();
	void endRender();
	
	void setColorSettings(float brightness, float saturation, float contrast);
	ofxFBOTexture * getTexture(bool useShader);
	
	ofxShader clrShader;
	
	ofxFBOTexture fbo1, fbo2;
	
	float brightness, saturation, contrast;
	
	
	
};


#endif