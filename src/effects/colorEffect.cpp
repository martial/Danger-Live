/*
 *  colorEffect.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 16/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "colorEffect.h"

void colorEffect::setup(string name) {
	this->name = name;
	
	clrShader.setup(1920, 1080);
	
	saturationPct = 1.0;
	contrastPct = 1.0;
	brightnessPct = 1.0;
	
	brightnessPctVariation = 0.0;
	contrastPctVariation = 0.0;
	saturationPctVariation = 0.0;
	
	saturationPctTween.setParameters( 0,easeQuint, ofxTween::easeIn, clrShader.saturationPct, 1.0, 0, 0);
	contrastPctTween.setParameters( 0,easeQuint, ofxTween::easeIn, clrShader.contrastPct, 1.0, 0, 0);
	brightnessPctTween.setParameters( 0,easeQuint, ofxTween::easeIn, clrShader.brightnessPct, 1.0, 0, 0);
	
	

}

void colorEffect::init() {
	}

void colorEffect::update() {
	
	saturationPct = clrShader.saturationPct = saturationPctTween.update() + saturationPctVariation;
	contrastPct = clrShader.contrastPct = contrastPctTween.update() + contrastPctVariation;
	brightnessPct = clrShader.brightnessPct = brightnessPctTween.update() +brightnessPctVariation;
	
}

void colorEffect::fadeInAll (float duration, float brightVal, float contrastVal, float saturationVal) {
	
	fadeDuration = duration;
	saturationPctTween.setParameters( 0,easeQuint, ofxTween::easeIn, clrShader.saturationPct, saturationVal, fadeDuration*.25, 0);
	contrastPctTween.setParameters( 0,easeQuint, ofxTween::easeIn, clrShader.contrastPct, contrastVal, fadeDuration*.3, 0);
	brightnessPctTween.setParameters( 0,easeQuint, ofxTween::easeIn, clrShader.brightnessPct, brightVal, fadeDuration*.5, 0);

	ofAddListener(brightnessPctTween.end_E,this,&colorEffect::fadeOutAll);
		
	saturationPctTween.start();
	contrastPctTween.start();
	brightnessPctTween.start();
	
}

void colorEffect::fadeOutAll (int & e) {
	
	ofRemoveListener(brightnessPctTween.end_E,this,&colorEffect::fadeOutAll);
	
	/*
	saturationPctTween.setParameters( 0,easeQuint, ofxTween::easeOut, clrShader.saturationPct, 1.0, fadeDuration*.8, 0);
	contrastPctTween.setParameters( 0,easeQuint, ofxTween::easeOut, clrShader.contrastPct, 1.0, fadeDuration*.3, 0);
	brightnessPctTween.setParameters( 0,easeQuint, ofxTween::easeOut, clrShader.brightnessPct, 1.0, fadeDuration*.5, 0);
		
	saturationPctTween.start();
	contrastPctTween.start();
	brightnessPctTween.start();
	
	 */
	 
	int temp = 0;
	ofNotifyEvent(completeBrightnessEvent, temp);

	
}

void colorEffect::onFadeInOuAlltComplete (int & e) {
	
}



ofxFBOTexture * colorEffect::getFbo(ofxFBOTexture & fbo, int x, int y, float alphaPct) {
	
	
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255, alphaPct*255);
	clrShader.beginRender();
	ofEnableAlphaBlending();
	
	ofSetColor(255, 255, 255, alphaPct*255);
	fbo.draw(0, 0);
	
	ofDisableAlphaBlending();
	clrShader.endRender();
	ofDisableAlphaBlending();
	return clrShader.getTexture(true);
	
	
}


/* */

void colorEffect::setBrightness(float brightness, int duration) {
	//clrShader.setColorSettings(brightness, clrShader.saturation, clrShader.contrast);
	brightnessPctTween.setParameters( 0,easeQuint, ofxTween::easeInOut, clrShader.brightnessPct, brightness, duration, 0);
	brightnessPctTween.start();
}

void colorEffect::setContrast(float contrast, int duration) {
	//clrShader.setColorSettings(clrShader.brightness, clrShader.saturation, contrast);
	contrastPctTween.setParameters( 0,easeQuint, ofxTween::easeInOut, clrShader.contrastPct, contrast, duration, 0);
	contrastPctTween.start();
}

void colorEffect::setSaturation(float saturation, int duration) {
	saturationPctTween.setParameters( 0,easeQuint, ofxTween::easeInOut, clrShader.saturationPct, saturation, duration, 0);
	saturationPctTween.start();
}