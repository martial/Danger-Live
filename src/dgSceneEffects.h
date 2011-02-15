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

class dgSceneEffects {

	public :
	void setup();
	void addEffect();
	void update();
	void draw(ofxFBOTexture & fbo);
	
	void setEffectByName(string name);
	void reset();
	
	dgAbstractEffect * getEffectByName(string name);
	
	vector<dgAbstractEffect*>	effects;
	
	private:
	
	int					currentEffectID;
	dgAbstractEffect *	currentEffect;
	
	
};

#endif