/*
 *  dgImageObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgImageObject.h"

void dgImageObject::setup (string imgURL, string name) {
	
	dgSceneObject::setup(name);
	
	img.loadImage(imgURL);
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