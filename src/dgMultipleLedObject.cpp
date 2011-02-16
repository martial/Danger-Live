/*
 *  dgMultipleLedObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 10/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgMultipleLedObject.h"

dgMultipleLedObject::dgMultipleLedObject() {
	
}

dgMultipleLedObject::~dgMultipleLedObject() {
	
}

void dgMultipleLedObject::setup (string name, string type) {
	
	dgSceneObject::setup(name, type);
	
}

void dgMultipleLedObject::addSwitchObject(dgSceneObject * switchObj) {
	
	int yPos = switchObjects.size()* (switchObj->height -2);
	
	
	switchObj->setPosition( 0, 0);
	switchObj->blurRate = this->configValues[2];
	switchObjects.push_back(switchObj);
	
	this->height = yPos;
	this->width = switchObj->width * switchObjects.size();
	
	//printf(switchObj->name.c_str());
}

void dgMultipleLedObject::init() {
	
	// get width and height for FBO
	

	
}

void dgMultipleLedObject::update () {
	
	dgSceneObject::update();
	
	// find current value
	
	int total = switchObjects.size();
	int enabledLeds = round(total*pct);
	
	
	for ( int i=0; i<total; i++ ) {
		if ( i < enabledLeds ) {
			switchObjects[i]->setPct(1);
		} else {
			switchObjects[i]->setPct(0);
		}
		switchObjects[i]->update();
	}
	
}

void dgMultipleLedObject::draw () {
	
	dgSceneObject::draw();
	
	
	ofSetColor(255, 255, 255);
	
	ofEnableAlphaBlending();
	
	float xCentroid = - width*.5 - switchObjects[0]->width*.5;
	float yCentroid = - height*.5;

	
	ofPushMatrix();
	ofTranslate(pos.x + xCentroid, pos.y + yCentroid - switchObjects[0]->height*.5, 0);
	
	ofTranslate(-xCentroid, -yCentroid, 0);
	ofRotate(rotation, 0, 0, 1);
	
	
		//ofRotate(ofGetElapsedTimeMillis(), 0, 0, 1);
	
	
	int numOfCols = (int)this->configValues[0];
	int numOfRows = (int)this->configValues[1];
	for ( int i=0; i<switchObjects.size(); i++ ) {
		
		//fbo.begin();
		for ( int j=0; j<numOfCols; j++ ) {
		ofPushMatrix();
		ofTranslate(j*switchObjects[i]->width+xCentroid, 0, 0);
			
			for ( int k=0; k<numOfRows; k++ ) {
				ofPushMatrix();
				ofTranslate(0, (k*switchObjects[i]->height-2) +yCentroid, 0);
				switchObjects[i]->draw();
				ofPopMatrix();
			}
		glPopMatrix();
		}
	}
	
	ofPopMatrix();


	ofDisableAlphaBlending();
	
}

void dgMultipleLedObject::setPct(float pct) {
	//printf ("Number of pct : %f\n", pct);
	dgSceneObject::setPct(pct);
	//mainVideo->setPosition(pct);
	
}