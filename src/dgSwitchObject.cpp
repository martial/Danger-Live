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
	
}


void dgSwitchObject::setup (string imgURL, string name, string type) {
	
	dgSceneObject::setup(name, type);
	
	// first image is default state
	addExtraImage(imgURL);
	
	this->width = images[0]->width;
	this->height = images[0]->height;
	
	easePct = pct;
	blurRate = .8;
	setPct(0);
}

void dgSwitchObject::addExtraImage(string url) {
	
	ofImage * img = imgAssets->addImage(url);
	
	//ofImage * img = new ofImage();
	//img->loadImage(url);
	images.push_back(img);
	
	
}

void dgSwitchObject::update () {
	
	dgSceneObject::update();
	
	easePct = blurRate * easePct + (1 - blurRate) * pct;
	currentIndex = floor((easePct * (images.size())));
	if ( currentIndex > images.size()-1 ) currentIndex = images.size()-1;
	//printf("---- \n");
	//printf("pct %f\n", easePct);
	//printf("easePCt %f\n", easePct);
	//printf("currentIndex %d\n", currentIndex);
	
}

void dgSwitchObject::draw () {
	
	dgSceneObject::draw();
	
	
	
	
	
	
	
	ofPushMatrix();
	ofTranslate((int)pos.x, (int)pos.y, 0);
	
	
	ofRotate(rotation, 0, 0, 1);
	ofEnableAlphaBlending();
	images[currentIndex]->draw((int)(-width * .5), (int)(-height * .5));
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