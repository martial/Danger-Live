/*
 *  dgRotationBtnObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 11/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgRotationBtnObject.h"

dgRotationBtnObject::dgRotationBtnObject() {
	
}

dgRotationBtnObject::~dgRotationBtnObject() {
	
}

void dgRotationBtnObject::setup (string imgURL, string name, string type) {
	
	dgSceneObject::setup(name, type);
	
	img.loadImage(imgURL);
	this->width = img.width;
	this->height = img.height;
}

void dgRotationBtnObject::addExtraImage(string url) {
	
	ofImage * img = new ofImage();
	img->loadImage(url);
	frontImages.push_back(img);
	
	
}

void dgRotationBtnObject::update () {
	
	dgSceneObject::update();
	
	// find good rotation
	float startingRot = this->configValues[0];
	float endingRot = this->configValues[1];
	btnRotation = startingRot + (endingRot*pct);
	
	
}

void dgRotationBtnObject::draw () {
	
	dgSceneObject::draw();
	
	ofEnableAlphaBlending();
	
	ofPushMatrix();
	ofTranslate(pos.x+img.width*.5,pos.y+img.height*.5, 0);
	ofRotate(btnRotation, 0, 0, 1);
	img.draw(-img.width*.5, -img.height*.5);
	ofPopMatrix();
	
	for (int i=0; i<frontImages.size(); i++) {
		

		frontImages[i]->draw(pos.x, pos.y );
	}
	
	
	ofDisableAlphaBlending();
}