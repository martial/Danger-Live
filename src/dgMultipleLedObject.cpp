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
	
	int yPos = (int)(switchObjects.size()* (switchObj->height -2));
	
	
	switchObj->setPosition( 0, 0);
	switchObj->blurRate = .1;
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
	
	//printf("enabledLeds %d\n:", enabledLeds);
	
	
	for ( int i=(total-1); i>=0; i-- ) {
		if ( i > (total - enabledLeds) ) {
			switchObjects[i]->setPct(1);
		} else {
			switchObjects[i]->setPct(0);
		}
		switchObjects[i]->rotation = -rotation;
		switchObjects[i]->update();
	}
	
}

void dgMultipleLedObject::draw () {
	
	dgSceneObject::draw();
	
	
	ofSetColor(255, 255, 255, 255);
	
	
	
	int xCentroid = - (int)(width*.5) - (int)(switchObjects[0]->width*.5);
	int yCentroid = - (int)(height*.5);

	
	ofPushMatrix();
	ofTranslate(pos.x + xCentroid, pos.y + yCentroid - switchObjects[0]->height*.5, 0);
	
	ofTranslate(-xCentroid, -yCentroid, 0);
	ofRotate((int)rotation, 0, 0, 1);
	
	
		//ofRotate(ofGetElapsedTimeMillis(), 0, 0, 1);
	
	
	int numOfCols = (int)this->configValues[0];
	int numOfRows = (int)this->configValues[1];
	float xPadding = (float)this->configValues[3];
	float yPadding = (float)this->configValues[4];
	
	//printf("ypadding %f\n", yPadding);
	
	for ( int i=0; i<switchObjects.size(); i++ ) {
		
		//fbo.begin();
		for ( int j=0; j<numOfCols; j++ ) {
		ofPushMatrix();
		ofTranslate((int)(j*(switchObjects[i]->width + xPadding)+xCentroid), 0, 0);
			
			for ( int k=0; k<numOfRows; k++ ) {
				ofPushMatrix();
				ofTranslate(0, (int)(k*(switchObjects[k]->height + yPadding) +yCentroid), 0);
				ofEnableAlphaBlending();
				switchObjects[k]->draw();
				ofDisableAlphaBlending();
				ofPopMatrix();
			}
		glPopMatrix();
		}
	}
	
	ofPopMatrix();


	
	
}

void dgMultipleLedObject::setPct(float pct) {
	//printf ("Number of pct : %f\n", pct);
	dgSceneObject::setPct(pct);
	//mainVideo->setPosition(pct);
	
}