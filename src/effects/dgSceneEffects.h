/*
 *  dgSceneEffects.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _DG_SCENE_EFFECTS
#define _DG_SCENE_EFFECTS

#include "ofMain.h"
#include "ofxFBOTexture.h"
#include "dgAbstractEffect.h"
#include "flickrEffect.h"
#include "blurEffect.h"
#include "colorEffect.h"
#include "bloomEffect.h"

class dgSceneEffects {

	public :
	void setup();
	void addEffect();
	void update();
	ofxFBOTexture * draw(ofxFBOTexture * fbo, int x, int y);
	
	void blurFadeInOut(float duration = 500.0);
	void colorFadeInOut(float duration, float brightVal = 0.0, float contrastVal = 1.5, float saturationVal = 0.0 );
	void onBrigthnessBlackEvent(int & e);
	
	void setEffectByName(string name);
	void reset();
	
	void setColorSettintgs(float brightness, float saturation, float contrast);
	void setBrightness(float brightness, int duration = 0);
	void setSaturation( float saturation, int duration = 0);
	void setContrast(float contrast, int duration = 0);

	
	void initBloom();
	
	dgAbstractEffect * getEffectByName(string name);
	
	vector<dgAbstractEffect*>	effects;
	
	float				brightnessPct;
	float				saturationPct;
	float				contrastPct;
	float				blurPct;
	
	ofEvent<int>		onFadeChangeEvent;
	
	private:
	
	int					currentEffectID;
	
	dgAbstractEffect *	currentEffect;
	colorEffect			color;
	blurEffect			blur;
	bloomEffect			bloom;
	
	
	
	
};

#endif