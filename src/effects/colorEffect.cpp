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
	
	
}

void colorEffect::init() {
	}

void colorEffect::update() {
	
	
	
	//clrShader.saturation *= saturationPct;
	//clrShader.contrast *= contrastPct;
	//clrShader.brightness *= brightnessPct;
	
}

void colorEffect::draw(ofxFBOTexture & fbo) {
	
	//printf("brightnessPct %f\n", brightnessPct );
	
	
	
	clrShader.beginRender();
	fbo.draw(0, 0);
	clrShader.endRender();
	
	
	//clrShader.draw(0, 0, 1920, 1080, true);
	
}

ofxFBOTexture * colorEffect::draw(ofxFBOTexture & fbo, int x, int y) {
	
	//printf("brightnessPct %f\n", brightnessPct );
	
	clrShader.saturationPct = saturationPct;
	clrShader.contrastPct = contrastPct;
	clrShader.brightnessPct = brightnessPct;
	
	clrShader.beginRender();
	fbo.draw(0, 0);
	clrShader.endRender();
	
	return clrShader.getTexture(true);
	
	
}


/* */

void colorEffect::setBrightness(float brightness) {
	clrShader.setColorSettings(brightness, clrShader.saturation, clrShader.contrast);
}

void colorEffect::setContrast(float contrast) {
	clrShader.setColorSettings(clrShader.brightness, clrShader.saturation, contrast);
}

void colorEffect::setSaturation(float saturation) {
	clrShader.setColorSettings(clrShader.brightness, saturation, clrShader.contrast);
}