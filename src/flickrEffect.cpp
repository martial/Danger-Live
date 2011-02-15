/*
 *  flickrEffect.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "flickrEffect.h"

void flickrEffect::setup(string name) {
	this->name = name;
	
	counter = 0;
	vel = 15.5;
}

void flickrEffect::init() {
	counter = 0;
	vel = 0.5;
}

void flickrEffect::update() {
	
}

void flickrEffect::draw(ofxFBOTexture & fbo) {
	
	counter += vel;
	
	int rdm = ofRandom(0, 1000);
	if ( rdm > counter ) {
		ofSetColor(255, 255, 255);
		fbo.draw(0, 0);
	} else {
		
		blackCounter += vel*3;
		
		rdm = ofRandom(0, 1000);
		
		if ( rdm > blackCounter ) {
			ofEnableAlphaBlending();
			ofSetColor(255, 255, 255, (int)ofRandom(40, 100));
			fbo.draw((int)ofRandom(-30, 30), (int)ofRandom(-35, 35));
			ofDisableAlphaBlending();
			} else {
				// black
			}
		
		
	}
	ofSetColor(255, 255, 255);
	
}