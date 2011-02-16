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
	
	color.setup("color");
	
	addEffect();
	
}

void dgSceneEffects::addEffect() {
	
	flickrEffect * flickr = new flickrEffect();
	flickr->setup("flickr");
	effects.push_back(flickr);
	
	bloomSceneEffect * bloom = new bloomSceneEffect();
	bloom->setup("bloom");
	effects.push_back(bloom);
	
	/*
	colorEffect * color = new colorEffect();
	color->setup("color");
	effects.push_back(color);
	 */
	
}

void dgSceneEffects::update() {
	if ( currentEffect ) currentEffect->update();
}

void dgSceneEffects::draw(ofxFBOTexture & fbo) {
	
	
	// in all cases apply color effect
	
	dgAbstractEffect * clrEffect = getEffectByName("color");
	clrEffect->draw(fbo);
	
	if ( currentEffect ) {
		//currentEffect->draw(fbo);
	} else {
		//fbo.draw(0,0);
	}	
	
}

void dgSceneEffects::draw(ofxFBOTexture & fbo, int x, int y) {
	
	
	// in all cases apply color effect
	
	ofxFBOTexture * filteredFbo =  color.draw(fbo, x, y);
	
	ofxFBOTexture * finalFbo;
	if ( currentEffect ) {
		finalFbo = currentEffect->draw(*filteredFbo,x,y);
		finalFbo->draw(x, y);
	} else {
		filteredFbo->draw(x,y);
	}	
	
}


void dgSceneEffects::setColorSettintgs(float brightness, float saturation, float contrast) {
	
}

void dgSceneEffects::setBrightness(float brightness) {
		color.setBrightness(brightness);
}

void dgSceneEffects::setContrast(float contrast) {
	color.setContrast(contrast);
}

void dgSceneEffects::setSaturation(float saturation) {
	color.setSaturation(saturation);
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