/*
 *  dgImageObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgImageObject.h"

dgImageObject::dgImageObject() {
	
}

dgImageObject::~dgImageObject() {
	
}

void dgImageObject::setup (string imgURL, string name, string type) {
	
	dgSceneObject::setup(name, type);
	
	img.loadImage(imgURL);
	this->width = img.width;
	this->height = img.height;
}

void dgImageObject::update () {
	
	dgSceneObject::update();
		
}

void dgImageObject::draw () {
	
	dgSceneObject::draw();
	
	ofEnableAlphaBlending();
	img.draw(pos.x, pos.y);
	ofDisableAlphaBlending();
}