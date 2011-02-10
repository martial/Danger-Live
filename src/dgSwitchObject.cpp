/*
 *  dgSwitchObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 09/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgSwitchObject.h"

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
	
	ofImage * img = new ofImage();
	img->loadImage(url);
	images.push_back(img);
	
	
}

void dgSwitchObject::update () {
	
	dgSceneObject::update();
	
	easePct = blurRate * easePct + (1 - blurRate) * pct;
	currentIndex = floor((easePct * (images.size())) + 0.5);
	if ( currentIndex > images.size()-1 ) currentIndex = images.size()-1;
	//printf("---- \n");
	//printf("pct %f\n", easePct);
	//printf("easePCt %f\n", easePct);
	//printf("currentIndex %d\n", currentIndex);
	
}

void dgSwitchObject::draw () {
	
	dgSceneObject::draw();
	
	ofEnableAlphaBlending();
	images[currentIndex]->draw(pos.x, pos.y);
	ofDisableAlphaBlending();
}


void dgSwitchObject::setPct(float pct) {
	
	// lets make some eaaasing..
	// TODO -> quit easing if no more than 3 picts
	
	
	// round
	
	dgSceneObject::setPct(pct);
	
}