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
	
	for (int i= 0; i<switchObjects.size(); i++ ) {
		//delete switchObjects[i];
		switchObjects[i] = NULL;
	}
	switchObjects.clear();
}

void dgMultipleLedObject::setup (string name, string type) {
	
	dgSceneObject::setup(name, type);
	

	
}

void dgMultipleLedObject::addSwitchObject(dgSceneObject * switchObj) {
	
	int yPos = (int)(switchObjects.size()* (switchObj->height -2));
	
	
	switchObj->setPosition( 0, 0);
	switchObj->rotation = -rotation;
	switchObj->blurRate = .1;
	switchObjects.push_back(switchObj);
	
	this->height = yPos;
	this->width = switchObj->width * switchObjects.size();
	
	total = switchObjects.size();
	
	//printf(switchObj->name.c_str());
}

void dgMultipleLedObject::init() {
	
	// get width and height for FBO
	
	 numOfCols = (int)this->configValues[0];
	 numOfRows = (int)this->configValues[1];
	 xPadding = this->configValues[3];
	 yPadding = this->configValues[4];
	
	if ( numOfCols < 2 )  xPadding = 0;
	
	this->height = (int)(numOfRows* (switchObjects[0]->height + yPadding));;
	this->width = (int)((switchObjects[0]->width + xPadding) * numOfCols);
	
	 xCentroid = - (int)(width*.5);
	 yCentroid = (int)(height*.5);
	
	//xCentroid = 0;
	//yCentroid = 0;
}

void dgMultipleLedObject::update () {
	
	dgSceneObject::update();
	
	// find current value
	
	
	
	int enabledLeds = round(total*pct);
	
		
	for ( int i=(total-1); i>=0; i-- ) {
		if ( i > (total - enabledLeds) ) {
			switchObjects[i]->setPct(1 * statePct);
		} else {
			switchObjects[i]->setPct(0);
		}
		
		switchObjects[i]->update();
	}
	
}

void dgMultipleLedObject::draw () {
	
	dgSceneObject::draw();
	
	
	ofSetColor(255, 255, 255, 255);
	
	//return;
	


	ofEnableAlphaBlending();
	ofPushMatrix();
	ofTranslate(pos.x, pos.y + yCentroid, 0);
	
	
	//ofRotate(ro, <#float vecX#>, <#float vecY#>, <#float vecZ#>)
	ofRotate(rotation, 0, 0, 1);
	
	
	
	
	//printf("ypadding %f\n", yPadding);
	
	//for ( int i=0; i<total; i++ ) {
		
		//fbo.begin();
		for ( int j=0; j<numOfCols; j++ ) {
		ofPushMatrix();
		ofTranslate((int)(j*(switchObjects[j]->width + xPadding)), 0, 0);
			
			for ( int k=0; k<numOfRows; k++ ) {
				ofPushMatrix();
				ofTranslate(0, (int)(k*(switchObjects[k]->height + yPadding)) - yCentroid, 0);
				switchObjects[k]->draw();
				
				//switchObjects[k]->setPosition((int)(j*(switchObjects[i]->width + xPadding)+xCentroid),(int)(k*(switchObjects[k]->height + yPadding) +yCentroid));
				
				ofPopMatrix();
			}
		glPopMatrix();
		}
	//}
	
	
	ofSetColor(255, 255, 0);
	ofRect( -5, -5 + height*.5, 10, 10);
	ofSetColor(255, 0, 0);
	ofRect(-5 + width, -5 + height*.5, 10, 10);
	ofRect(-5 + width*.5, -5 + height*.5, 10, 10);
	ofSetColor(255, 255, 255);
	
	ofPopMatrix();
	ofDisableAlphaBlending();
	
	
	
	

	
	
}

void dgMultipleLedObject::setPct(float pct) {
	//printf ("Number of pct : %f\n", pct);
	dgSceneObject::setPct(pct);
	//mainVideo->setPosition(pct);
	
}