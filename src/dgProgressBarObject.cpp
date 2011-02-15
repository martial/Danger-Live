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
	
	ofSetColor(255, 0, 0);
	ofEnableAlphaBlending();
	
	ofPushMatrix();
	ofTranslate(pos.x, pos.y, 0);
	ofRect(0, 0, barWidth*pct, barHeight);
	ofPopMatrix();
	ofSetColor(255, 255, 255);
	
	ofDisableAlphaBlending();
	 
	 
}