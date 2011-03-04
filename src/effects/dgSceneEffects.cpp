/*
 *  dgSceneEffects.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgSceneEffects.h"

void dgSceneEffects::setup(dangerPrefs & settings) {
	
	
	this->settings = &settings;
	
	
	
	
	printf("set broght %f\n", this->settings->getBrightness());
	printf(" setContrast %f\n", this->settings->getContrast());
	printf(" setContrast %f\n", this->settings->getSaturation());
	
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
	
	setBrightness(this->settings->getBrightness(), 3000);
	setContrast(this->settings->getContrast(), 3000);
	setSaturation(this->settings->getSaturation(), 3000);
	
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
		
	} else {
		//ofDisableAlphaBlending();
		
		finalFbo = (blur.blurPct > 0 ) ? filteredFbo : blur.getFbo(*filteredFbo,x,y);
		return finalFbo;
	}	
	 
	 
	
}

/*  ----- -----  -----  -----  -----  -----  -----  -----  -----  -----  -----  */

/*  Bloom */

void dgSceneEffects::initBloom () {
	
	setEffectByName("bloom");
	
	setBrightness(settings->getBrightness() - .1, 500, false);
	setContrast(settings->getContrast() + .1, 500, false);
	setSaturation(settings->getSaturation() - .4, 600, false);
	
	blur.setBlurPct(2.0, 500);
	bloom.setIntensity(1.0, 500);
	
	ofRemoveListener(bloom.intensityEnd, this, &dgSceneEffects::removeBloom);
}

void dgSceneEffects::quitBloom () {
	
	setEffectByName("bloom");
	
	setBrightness(settings->getBrightness(), 500);
	setContrast(settings->getContrast(), 500);
	setSaturation(settings->getSaturation(), 500);
	
	blur.setBlurPct(0.0, 500);
	bloom.setIntensity(0.0, 500);
	ofAddListener(bloom.intensityEnd, this, &dgSceneEffects::removeBloom);
}

void dgSceneEffects::removeBloom (int & e) {
	ofRemoveListener(bloom.intensityEnd, this, &dgSceneEffects::removeBloom);
	reset();
}



/*  ----- -----  -----  -----  -----  -----  -----  -----  -----  -----  -----  */




void dgSceneEffects::blurFadeInOut (float duration) {
	blur.fadeIn(duration);
}

void dgSceneEffects::colorFadeInOut (float duration, float brightVal, float contrastVal, float saturationVal ) {
	
	color.fadeInAll(duration, brightVal, contrastVal, saturationVal);
	ofAddListener(color.completeBrightnessEvent, this, &dgSceneEffects::onBrigthnessBlackEvent);
}

void dgSceneEffects:: onBrigthnessBlackEvent(int & e) {
	setBrightness(settings->getBrightness(), 100);
	setContrast(settings->getContrast(), 100);
	setSaturation(settings->getSaturation(), 100);
	ofRemoveListener(color.completeBrightnessEvent, this, &dgSceneEffects::onBrigthnessBlackEvent);
	int ahou = 0;
	ofNotifyEvent(onFadeChangeEvent, ahou);
}




/*  ----- -----  -----  -----  -----  -----  -----  -----  -----  -----  -----  */

/* color settings */

void dgSceneEffects::setColorSettintgs(float brightness, float saturation, float contrast) {
	
}

void dgSceneEffects::setBrightness(float brightness, int duration, bool save) {
		color.setBrightness(brightness,duration);
		if ( save ) this->settings->saveBrightness(brightness);
}

void dgSceneEffects::setContrast(float contrast, int duration, bool save) {
		color.setContrast(contrast,duration);
		if ( save ) this->settings->saveContrast(contrast);
}

void dgSceneEffects::setSaturation(float saturation, int duration, bool save) {
		color.setSaturation(saturation,duration);
		if ( save ) this->settings->saveSaturation(saturation);
}

void dgSceneEffects::saveToSettings () {
	//this->settings.saveColorSettings();
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

void dgSceneEffects::onMasterSignalEvent(float val) {
	
	//printf("val : %f\n", val);
	color.brightnessPctVariation = val * .5;
	color.contrastPctVariation = val * .25;
}



void dgSceneEffects::reset() {
	currentEffect = NULL;
}