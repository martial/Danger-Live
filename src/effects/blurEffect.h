/*
 *  bloomSceneEffect.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _BLURFX
#define _BLURFX

#include "ofMain.h"
#include "ofxFBOTexture.h"
#include "dgAbstractEffect.h"
#include "flickrEffect.h"

#include "ofxTween.h"

#include "shaderBlur.h"
//#include "bloomShader.h"

class blurEffect : public dgAbstractEffect {
	
	public:
	
	void setup(string name);
	void init();
	void update();
	ofxFBOTexture * getFbo(ofxFBOTexture & fbo, int x, int y);	
	float		blurPct;
	
	
	void setBlurPct (float pct, float duration);
	
	void fadeIn(float duration = 500.0);
	void fadeOut(int & e);
	void onFadeInOutComplete(int & e);
	
	private:
	
	float		counter;
	float		blackCounter;
	float		vel;
	
	
	ofxTween				blurPctTween;
	ofxEasingQuint			easeQuint;
	float					fadeDuration;
	shaderBlur				blur;
	//bloomShader			bloom;
	
	
};

#endif