/*
 *  dgFaderObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 10/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgFaderObject.h"

dgFaderObject::dgFaderObject() {
	
}

dgFaderObject::~dgFaderObject() {
	
}

void dgFaderObject::setup (string imgURL, string name, string type) {
	
	dgSceneObject::setup(name, type);
	
	img.loadImage(imgURL);
	this->width = img.width;
	this->height = img.height;
	
}

void dgFaderObject::update () {
	
	dgSceneObject::update();
	
}

void dgFaderObject::draw () {
	
	dgSceneObject::draw();
	
	
	
	float total = this->configValues[0];
	float xPos = -( total * .5)  +  (total*pct );

	
	
		
	
	ofEnableAlphaBlending();
	img.draw(pos.x + xPos, pos.y );
	ofDisableAlphaBlending();
}

void dgFaderObject::setPct(float pct) {
	//printf ("Number of pct : %f\n", pct);
	dgSceneObject::setPct(pct);
	
}