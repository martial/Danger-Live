/*
 *  bloomSceneEffect.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "bloomSceneEffect.h"

void bloomSceneEffect::setup(string name) {
	this->name = name;
	
	counter = 0;
	vel = 15.5;
	
	blur.setup(1920, 1080);
	bloom.setup(1920, 1080);
	
	blurPct = 0.0;
	
}

void bloomSceneEffect::init() {
	counter = 0;
	vel = 0.5;
}

void bloomSceneEffect::update() {
	
	blur.blurPct = blurPct;
	
}

void bloomSceneEffect::draw(ofxFBOTexture & fbo) {
	
	counter += vel;
	
	bloom.beginRender();
	fbo.draw(0, 0);
	bloom.endRender();
	
	blur.beginRender();
	bloom.draw(0, 0, 1920, 1080, true);
	blur.endRender();
	
	blur.draw(0, 0, 1920, 1080, true);
	
	
	
}

ofxFBOTexture * bloomSceneEffect::draw(ofxFBOTexture & fbo, int x, int y) {
	
	counter += vel;
	
	/*
	bloom.beginRender();
	fbo.draw(0, 0);
	bloom.endRender();
	*/
	 
	blur.beginRender();
	fbo.draw(0, 0, 1920, 1080);
	blur.endRender();
	
	return blur.draw(0, 0, 0, 0, true);
	//blur.draw(0, 0, 1440, 900, true);
	
	
	
}