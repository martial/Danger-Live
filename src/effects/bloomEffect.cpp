/*
 *  bloomEffect.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 24/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "bloomEffect.h"



void bloomEffect::setup(string name) {
	
	this->name = name;
	
	filteredFbo = new ofxFBOTexture();
	filteredFbo->allocate(1920, 1080, GL_RGBA);
	filteredFbo->clear(0, 0, 0, 0);
	
	intensityPct = 0.0;
	intensityPctTween.setParameters( 0,easeQuint, ofxTween::easeInOut, intensityPct, 0, 0, 0);
	intensityPctTween.start();
	
}

void bloomEffect::init(blurEffect * blur, colorEffect * color) {
	this->blur = blur;
	this->color = color;
}

void bloomEffect::update() {
	
	intensityPct = intensityPctTween.update();
}

void bloomEffect::setIntensity(float val, float duration ) {
	intensityPctTween.setParameters( 0,easeQuint, ofxTween::easeInOut, intensityPct, val, duration, 0);
	intensityPctTween.start();
	
}



ofxFBOTexture * bloomEffect::getFbo(ofxFBOTexture * originalFbo,  int x, int y) {
	
	
	
	ofxFBOTexture * blurredFbo = blur->getFbo(*originalFbo,x,y);	
	ofxFBOTexture * coloredFbo =  color->getFbo(*blurredFbo, x, y,intensityPct);
	
	filteredFbo->clear(0, 0, 0, 0);
	filteredFbo->begin();
	

	originalFbo->draw(0, 0);
	
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE);
	
	coloredFbo->draw(0, 0);
	//ofDisableAlphaBlending();
	
	glDisable(GL_BLEND);
	
	filteredFbo->end();
	//filteredFbo->clear(0, 0, 0, 0);
	ofSetColor(255, 255, 255, 255);
	
	return filteredFbo;
	 
	
			
	
	
}