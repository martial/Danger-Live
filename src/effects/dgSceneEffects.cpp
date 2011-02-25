/*
 *  dgSceneEffects.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgSceneEffects.h"

void dgSceneEffects::setup() {
	
	currentEffectID = -1;
	currentEffect = NULL;
	
	color.setup("color");
	blur.setup("blur");
	bloom.setup("bloom");
	
	bloom.init(&blur, &color);
	effects.push_back(&bloom);
	
	
	saturationPct = 1.0;
	contrastPct = 1.0;
	brightnessPct = 1.0;
	blurPct = 0.0;
	
	addEffect();
	
}

void dgSceneEffects::addEffect() {
	
	flickrEffect * flickr = new flickrEffect();
	flickr->setup("flickr");
	effects.push_back(flickr);
	
		
}

void dgSceneEffects::update() {
		
		color.brightnessPct = brightnessPct;
		color.contrastPct = contrastPct;
		color.update();
		
	
		
		blur.blurPct = blurPct;
		blur.update();
		
	//}
	
	if ( currentEffect ) currentEffect->update();
}



ofxFBOTexture * dgSceneEffects::draw(ofxFBOTexture * fbo, int x, int y) {
	
	// apply color filter
	ofxFBOTexture * filteredFbo =  color.getFbo(*fbo, x, y);	
	ofxFBOTexture * finalFbo;
	if ( currentEffect ) {
		
		
		if ( currentEffect->name == "bloom" ) {
			return bloom.getFbo(fbo, x, y);
		}
		
		finalFbo = currentEffect->getFbo(*filteredFbo,x,y);
		return finalFbo;
		
		//ofSetupScreen();
	} else {
		//ofDisableAlphaBlending();
		ofEnableAlphaBlending();
		finalFbo = blur.getFbo(*filteredFbo,x,y);
		return finalFbo;
	}	
	 
	 
	
}

void dgSceneEffects::initBloom () {
	setEffectByName("bloom");
	setBrightness(.8, 1200);
	setContrast(1.2, 1500);
	blur.setBlurPct(2.0, 1000);
	bloom.setIntensity(1.0, 1800);
	//blur.setup(<#string name#>)
}

void dgSceneEffects::blurFadeInOut (float duration) {
	blur.fadeIn(duration);
}

void dgSceneEffects::colorFadeInOut (float duration, float brightVal, float contrastVal, float saturationVal ) {
	
	color.fadeInAll(duration, brightVal, contrastVal, saturationVal);
	ofAddListener(color.completeBrightnessEvent, this, &dgSceneEffects::onBrigthnessBlackEvent);
}

void dgSceneEffects:: onBrigthnessBlackEvent(int & e) {
	ofRemoveListener(color.completeBrightnessEvent, this, &dgSceneEffects::onBrigthnessBlackEvent);
	int ahou = 0;
	ofNotifyEvent(onFadeChangeEvent, ahou);
}


/* transitions */




void dgSceneEffects::setColorSettintgs(float brightness, float saturation, float contrast) {
	
}

void dgSceneEffects::setBrightness(float brightness, int duration) {
		color.setBrightness(brightness,duration);
}

void dgSceneEffects::setContrast(float contrast, int duration) {
		color.setContrast(contrast,duration);
}

void dgSceneEffects::setSaturation(float saturation, int duration) {
		color.setSaturation(saturation,duration);
}

void dgSceneEffects::setEffectByName(string name) {
	currentEffect = getEffectByName(name);
}

/* */ 

dgAbstractEffect * dgSceneEffects::getEffectByName(string name) {
	for ( int i=0; i<effects.size(); i++) {
	
		if ( name == effects[i]->name) return effects[i];
	}
	return NULL;
}



void dgSceneEffects::reset() {
	currentEffect = NULL;
}