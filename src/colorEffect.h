/*
 *  colorEffect.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 16/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _CLR_FX_DEG
#define _CLR_FX_DEG


#include "ofMain.h"
#include "colorShader.h"
#include "dgAbstractEffect.h"

class colorEffect : public dgAbstractEffect {
	
public:
	void setup(string name);
	void init();
	void update();
	void draw(ofxFBOTexture & fbo);
	ofxFBOTexture * draw(ofxFBOTexture & fbo, int x, int y);
	
	void setBrightness(float brightness);
	void setSaturation( float saturation);
	void setContrast(float contrast);
	
	
private:
	
	
		
	colorShader			clrShader;
	
	

	
};

#endif