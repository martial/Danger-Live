/*
 *  bloomSceneEffect.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "blurEffect.h"

void blurEffect::setup(string name) {
	
	this->name = name;
	
	
	blur.setup(1920, 1080);
	
	blurPct = 2.0;
	
	//printf("setuyp blur \n");
	
}

void blurEffect::init() {
	counter = 0;
	vel = 0.5;
}

void blurEffect::update() {
	
	blur.blurPct = blurPctTween.update();
	
	
	//blur.blurPct  = 2.0;
}

void blurEffect::fadeIn (float duration) {
	
	fadeDuration = duration;
	blurPctTween.setParameters( 0,easeQuint, ofxTween::easeIn, blur.blurPct, 2, fadeDuration*.5, 0);
	ofAddListener(blurPctTween.end_E,this,&blurEffect::fadeOut);
	blurPctTween.start();
	
}

void blurEffect::fadeOut (int & e) {
	
	ofRemoveListener(blurPctTween.end_E,this,&blurEffect::fadeOut);
	blurPctTween.setParameters( 1, easeQuint, ofxTween::easeOut, blur.blurPct, 0, fadeDuration*.5, 0);
	ofAddListener(blurPctTween.end_E,this,&blurEffect::onFadeInOutComplete);
	blurPctTween.start();
}

void blurEffect::onFadeInOutComplete (int & e) {
	
}


void blurEffect::setBlurPct (float pct, float duration) {
	blurPctTween.setParameters( 1, easeQuint, ofxTween::easeInOut, blur.blurPct, pct, duration, 0);
	blurPctTween.start();
	
}


ofxFBOTexture * blurEffect::getFbo(ofxFBOTexture & fbo, int x, int y) {
	
	blur.beginRender();
	fbo.draw(0, 0, 1920, 1080);
	blur.endRender();
	
	return blur.getFbo(0, 0, 0, 0, true);
	//blur.draw(0, 0, 1440, 900, true);
	
	
	
}

ofxFBOTexture * blurEffect::getFboReference() {
	

	
	return blur.getFboReference();
	//blur.draw(0, 0, 1440, 900, true);
	
	
	
}




