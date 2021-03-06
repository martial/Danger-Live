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
	
	//img->clear();
	//delete img;
	
}

void dgImageObject::setup (string imgURL, string name, string type) {
	
	dgSceneObject::setup(name, type);
	
	img = imgAssets->addImage(imgURL);
	this->width = img->getWidth();
	this->height = img->getHeight();
}

void dgImageObject::update () {
	
	dgSceneObject::update();
		
}

void dgImageObject::draw () {
	
	dgSceneObject::draw();
	
	ofEnableAlphaBlending();
	ofPushMatrix();
	ofTranslate(pos.x - width *.5, pos.y - height * .5, 0);
	img->draw(0, 0);
	ofPopMatrix();
	ofDisableAlphaBlending();
}