/*
 *  dgProgressBarObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgProgressBarObject.h"

dgProgressBarObject::dgProgressBarObject() {
	
}

dgProgressBarObject::~dgProgressBarObject() {
	
}

void dgProgressBarObject::setup (string name, string type) {
		
	//img.loadImage(imgURL);
	
	

}

void dgProgressBarObject::update () {
	
	//dgSceneObject::update();
	
}

void dgProgressBarObject::draw () {
	
	
	
	//dgSceneObject::draw();
	
	float barWidth = this->configValues[0];
	float barHeight = this->configValues[1];
	
	this->width = this->configValues[0];
	this->height = this->configValues[1];
	
	
	ofEnableAlphaBlending();
	
	// back
	
	ofSetColor(0, 0, 0);
	ofRect(pos.x- width *.5 -2, pos.y- height * .5-2, barWidth+4, barHeight+2);
	
	int current = (int) barWidth*pct;
	for ( int i=0; i< current; i++ ) {
		
		ofSetColor(55 + ((i*100/barWidth)), 0, 0);
		ofPushMatrix();
		ofTranslate(pos.x - width *.5, pos.y - height * .5, 0);
		ofRect(i, 0, 1, barHeight);
		ofPopMatrix();
		
		
	}
	
	
	ofSetColor(255, 255, 255);
	
	ofDisableAlphaBlending();
	 
	 
}