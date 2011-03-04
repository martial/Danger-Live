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
		//imageSet[i]->clear();
		delete imageSet[i];
		imageSet[i] = NULL;
	}
	imageSet.clear();
	
}


void dgSwitchObject::setup (string imgURL, string name, string type) {
	
	dgSceneObject::setup(name, type);
	
	// first image is default state
	addExtraImage(imgURL);
	
	this->width = imageSet[0]->getWidth();
	this->height = imageSet[0]->getHeight();
	
	active = true;
	
	easePct = pct;
	blurRate = 0.0;
	setPct(0);
}

void dgSwitchObject::addExtraImage(string url) {
	
	ofTexture * img = imgAssets->addImage(url);
	//img->setUseTexture(true);
	
	//ofImage * img = new ofImage();
	//img->loadImage(url);
	imageSet.push_back(img);
	imagesSize = imageSet.size();
	
	if ( img->getWidth() > width ) this->width = img->getWidth();
	if ( img->getHeight() > height ) this->height = img->getHeight();
	
	
}

void dgSwitchObject::update () {
	
	dgSceneObject::update();
	
	// check if go up or down
	
	
	
	easePct = blurRate * easePct + (1 - blurRate) * pct;
	
	
	currentIndex = (int)floor((easePct * (imagesSize)));
	if ( currentIndex > imagesSize-1 ) currentIndex = imagesSize-1;
		
}

void dgSwitchObject::draw () {
	
	dgSceneObject::draw();
	
	if (!active ) return;
	
		
	ofPushMatrix();
	ofTranslate((int)pos.x, (int)pos.y, 0);
	
	ofRotate(rotation, 0, 0, 1);
	
	if ( currentIndex < 0 ) currentIndex = 0;
	if ( currentIndex > imagesSize-1 ) currentIndex = imagesSize-1;
	
	ofEnableAlphaBlending();
	imageSet[currentIndex]->draw((int)(-width * .5), (int)( -height * .5));
	ofDisableAlphaBlending();
	ofPopMatrix();
	
	ofSetColor(255, 255, 255, 255);
}


void dgSwitchObject::setPct(float pct) {
	
	// lets make some eaaasing..
	// TODO -> quit easing if no more than 3 picts
	
	
	// round
	
	if ( pct > easePct ) {
		blurRate = 0.0;
	} else {
		blurRate = .5;
	}
	
	dgSceneObject::setPct(pct);
	
}