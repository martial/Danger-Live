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
	
	transformedColor.setup("transformed");
	
		
	
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
	
	transformedColor.setContrast(color->contrastPct , 1);
	transformedColor.setBrightness(color->brightnessPct, 1);
	transformedColor.setSaturation(color->contrastPct, 1);
	
	
		
}

void bloomEffect::update() {
	
	
	transformedColor.setContrast(color->contrastPct-.01, .1);
	transformedColor.setBrightness(color->brightnessPct+1, .1);
	transformedColor.setSaturation(color->saturationPct, .1);
	
	
	
	transformedColor.update();
	intensityPct = intensityPctTween.update();
}

void bloomEffect::setIntensity(float val, float duration ) {
	intensityPctTween.setParameters( 0,easeQuint, ofxTween::easeInOut, intensityPct, val, duration, 0);
	ofAddListener(intensityPctTween.end_E, this, &bloomEffect::onIntensityComplete);
	intensityPctTween.start();
	
}

void bloomEffect::onIntensityComplete(int & e) {
	ofRemoveListener(intensityPctTween.end_E, this, &bloomEffect::onIntensityComplete);
	ofNotifyEvent(intensityEnd, e);
}



ofxFBOTexture * bloomEffect::getFbo(ofxFBOTexture * originalFbo,  int x, int y) {
	
	
	
	ofxFBOTexture * coloredFbo =  color->getFbo(*originalFbo, x, y);
	
	ofxFBOTexture * blurredFbo = blur->getFbo(*coloredFbo,x,y);	
	
	//printf("intensityPct test : %f\n", blur->blurPct);
	
	ofxFBOTexture * finalFbo =  transformedColor.getFbo(*blurredFbo, x, y,intensityPct);
	
	
	filteredFbo->clear(0, 0, 0, 0);
	filteredFbo->begin();
	
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA); 

	coloredFbo->draw(0, 0);
	
	//glDisable(GL_BLEND);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE);
	
	finalFbo->draw(0, 0);
	//ofDisableAlphaBlending();
	
	glDisable(GL_BLEND);
	 
	
	filteredFbo->end();
	//filteredFbo->clear(0, 0, 0, 0);
	ofSetColor(255, 255, 255, 255);
	
	return filteredFbo;
	 
	
			
	
	
}