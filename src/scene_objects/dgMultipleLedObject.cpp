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
		delete switchObjects[i];
		switchObjects[i] = NULL;
	}
	switchObjects.clear();
}

void dgMultipleLedObject::setup (string name, string type) {
	
	dgSceneObject::setup(name, type);
	

	
}

void dgMultipleLedObject::addSwitchObject(dgSceneObject * switchObj) {
	
	//int yPos = (int)(switchObjects.size()* (switchObj->height -2));
	
	
	switchObj->setPosition( 0, 0);
	
	switchObj->blurRate = 0.0;
	switchObjects.push_back(switchObj);
	
	//this->height = yPos;
	//this->width = switchObj->width * switchObjects.size();
	
	total = switchObjects.size();
	
	//printf(switchObj->name.c_str());
}

void dgMultipleLedObject::init() {
	
	// get width and height for FBO
	
	 numOfCols = (int)this->configValues[0];
	 numOfRows = (int)this->configValues[1];
	 xPadding = this->configValues[3];
	 yPadding = this->configValues[4];
	
	//if ( numOfCols < 2 )  xPadding = 0;
	//if ( numOfRows < 2 )  yPadding = 0;
	
	if ( this->configValues[5] ) {
		for ( int k=0; k<total; k++ ) {
		switchObjects[k]->rotation = -rotation;
		switchObjects[k]->blurRate = 0.0;
		}
	}
	
	
	this->width		= (int) ((numOfCols-1) * (switchObjects[0]->width + xPadding));
	this->height	= (int) ((numOfRows-1) * (switchObjects[0]->height + yPadding));
	
	//width  -= xPadding;
	//height -= yPadding;
	xCentroid = width * .5;
	yCentroid = height *.5;
	


}

void dgMultipleLedObject::update () {
	
	dgSceneObject::update();
	
	// find current value
	
	//printf("statePCT : %f\n", statePct);
	
	//printf(adressState.c_str());
	
	if ( pctStateRef ) {
			//printf("youpiii");
	}
	
	int enabledLeds = round((total)*pct);
	
		
	for ( int i=(total-1); i>=0; i-- ) {
		if ( i >= (total - enabledLeds) ) {
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
	
	
	

	
	ofPushMatrix();
	ofTranslate((int)(-xCentroid), (int)(-yCentroid), 0);
	
	ofPushMatrix();
	ofTranslate((int)(pos.x + xCentroid), (int)(pos.y +yCentroid), 0);
	
	
	
	//rotation += 0.1;
	ofRotate(rotation, 0, 0, 1);
	
		for ( int j=0; j<numOfCols; j++ ) {
			for ( int k=0; k<total; k++ ) {
				
				ofPushMatrix();
				ofTranslate( (int) (j * (switchObjects[j]->width +xPadding ) - xCentroid), int(k * (switchObjects[k]->height + yPadding ) -yCentroid) , 0);
				//ofEnableAlphaBlending();
				switchObjects[k]->draw();
				//ofDisableAlphaBlending();
				ofPopMatrix();
			}
			
		}
	
	ofPopMatrix();
	ofPopMatrix();
	
	
	
	

	
	
}

void dgMultipleLedObject::setPct(float pct) {
	
	dgSceneObject::setPct(pct);
	//mainVideo->setPosition(pct);
	
}