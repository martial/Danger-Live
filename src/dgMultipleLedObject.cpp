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
	
	int yPos = switchObjects.size()* (switchObj->height + 3);
	this->height = yPos;
	this->width = switchObj->width;
	
	switchObj->setPosition( pos.x, (int)(pos.y - yPos));
	switchObj->blurRate = this->configValues[2];
	switchObjects.push_back(switchObj);
	
	//printf(switchObj->name.c_str());
}

void dgMultipleLedObject::init() {
	
	// get width and height for FBO
	
	int numOfCols = (int)this->configValues[0];
	int numOfRows = (int)this->configValues[1];
	
	int fboW = (width + 3) * numOfCols;
	int fboH = this->height;
	
	texture.allocate( fboW, fboH , GL_RGB);
	fbo.setup(fboW, fboH, true);
	fbo.attach(texture);
	
	
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
	int numOfCols = (int)this->configValues[0];
	for ( int i=0; i<switchObjects.size(); i++ ) {
		
		//fbo.begin();
		for ( int j=0; j<numOfCols; j++ ) {
		glPushMatrix();
		ofTranslate(j*35, 0, 0);
		switchObjects[i]->draw();
		glPopMatrix();
		//fbo.end();
		}
	}
	
	for ( int j=0; j<numOfCols; j++ ) {
		//fbo.draw(pos.x + ( j*10), pos.y );
	}

	ofDisableAlphaBlending();
	
}

void dgMultipleLedObject::setPct(float pct) {
	//printf ("Number of pct : %f\n", pct);
	dgSceneObject::setPct(pct);
	//mainVideo->setPosition(pct);
	
}