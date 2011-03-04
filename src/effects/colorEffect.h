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
#include "ofxTween.h"

class colorEffect : public dgAbstractEffect {
	
public:
	void setup(string name);
	void init();
	void update();
	ofxFBOTexture * getFbo(ofxFBOTexture & fbo, int x, int y, float alphaPct = 1.0);
	
	void fadeInAll (float duration, float brightVal = 0.0, float contrastVal = 1.5, float saturationVal = 0.0 );
	void fadeOutAll(int & e);
	void onFadeInOuAlltComplete(int & e);
	
	void setBrightness(float brightness, int duration);
	void setSaturation( float saturation, int duration);
	void setContrast(float contrast, int duration);
	
	
	float				brightnessPct;
	float				saturationPct;
	float				contrastPct;
	
	float				brightnessPctVariation;
	float				saturationPctVariation;
	float				contrastPctVariation;
	
	ofEvent<int>		completeBrightnessEvent;
	
	
	
private:
	
	
	
	
	ofxTween			saturationPctTween;
	ofxTween			contrastPctTween;
	ofxTween			brightnessPctTween;
	//ofxEasingQuint		easeQuint;
	ofxEasingSine		easeQuint;
	
	float				fadeDuration;
	
	colorShader			clrShader;
	
	

	
};

#endif