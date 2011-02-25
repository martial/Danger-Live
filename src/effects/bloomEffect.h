/*
 *  bloomSceneEffect.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _BOOMFX
#define _BOOMFX

#include "ofMain.h"
#include "ofxFBOTexture.h"
#include "dgAbstractEffect.h"
#include "ofxTween.h"
#include "blurEffect.h"
#include "colorEffect.h"


class bloomEffect : public dgAbstractEffect {
	
public:
	
	void setup(string name);
	void init(blurEffect * blur, colorEffect * color);
	void update();
	ofxFBOTexture * getFbo(ofxFBOTexture * originalFbo,  int x, int y);	
		
	void setIntensity(float val, float duration );
	void onIntensityComplete(int & e);
	
	ofEvent<int>			intensityEnd;
	
private:
	
	
	colorEffect				transformedColor;
	blurEffect		*		blur;
	colorEffect		*		color;
	ofxFBOTexture	*		filteredFbo;
	
	float					intensityPct;
	ofxEasingQuint			easeQuint;
	ofxTween				intensityPctTween;
	
};

#endif