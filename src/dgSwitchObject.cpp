/*
 *  dgSwitchObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 09/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgSwitchObject.h"

#include "imgAssetsManager.h"

dgSwitchObject::dgSwitchObject() {
	
}

dgSwitchObject::~dgSwitchObject() {
	
	//~dgSceneObject();
	//images.clear();
	
	
	for (int i=0; i<imageSet.size(); i++) {
		imageSet[i]->clear();
		//delete imageSet[i];
	}
	imageSet.clear();
	
}


void dgSwitchObject::setup (string imgURL, string name, string type) {
	
	dgSceneObject::setup(name, type);
	
	// first image is default state
	addExtraImage(imgURL);
	
	this->width = imageSet[0]->width;
	this->height = imageSet[0]->height;
	
	active = true;
	
	easePct = pct;
	blurRate = 0.0;
	setPct(0);
}

void dgSwitchObject::addExtraImage(string url) {
	
	ofImage * img = imgAssets->addImage(url);
	//img->setUseTexture(true);
	
	//ofImage * img = new ofImage();
	//img->loadImage(url);
	imageSet.push_back(img);
	imagesSize = imageSet.size();
	
}

void dgSwitchObject::update () {
	
	dgSceneObject::update();
	
	easePct = blurRate * easePct + (1 - blurRate) * pct;
	currentIndex = floor((pct * (imagesSize)));
	if ( currentIndex > imagesSize-1 ) currentIndex = imagesSize-1;
		
}

void dgSwitchObject::draw () {
	
	dgSceneObject::draw();
	
	if (!active ) return;
	
	ofPushMatrix();
	ofTranslate(pos.x, pos.y, 0);
	
	
	ofRotate(rotation, 0, 0, 1);
	ofEnableAlphaBlending();
	imageSet[currentIndex]->draw((-width * .5), (-height * .5));
	
	ofDisableAlphaBlending();
	ofPopMatrix();
	
	ofSetColor(255, 255, 255, 255);
}


void dgSwitchObject::setPct(float pct) {
	
	// lets make some eaaasing..
	// TODO -> quit easing if no more than 3 picts
	
	
	// round
	
	dgSceneObject::setPct(pct);
	
}