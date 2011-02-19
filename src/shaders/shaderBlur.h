/*
 *  shaderBlur.h
 *  openFrameworks
 *
 *  Created by theo on 17/10/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _BLR_SHADER
#define _BLR_SHADER

#include "ofMain.h"
#include "ofxShader.h" 
#include "ofxFBOTexture.h"

class shaderBlur{

	public:
		void setup(int fboW, int fboH);
		
		void beginRender();
		void endRender();
		
		void setBlurParams(int numPasses, float blurDist);
		ofxFBOTexture * draw(float x, float y, float w, float h, bool useShader);
				
		ofxShader shaderH;
		ofxShader shaderV;

		ofxFBOTexture fbo1, fbo2;
		
		float blurDistance;
		float blurPct;
	
		int noPasses;
};

#endif