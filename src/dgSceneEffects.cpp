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
	addEffect();
	
}

void dgSceneEffects::addEffect() {
	
	flickrEffect * flickr = new flickrEffect();
	flickr->setup("flickr");
	effects.push_back(flickr);
	
}

void dgSceneEffects::update() {
	if ( currentEffect ) currentEffect->update();
}

void dgSceneEffects::draw(ofxFBOTexture & fbo) {
	
	
	if ( currentEffect ) {
		currentEffect->draw(fbo);
	} else {
		fbo.draw(0,0);
	}	
	
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