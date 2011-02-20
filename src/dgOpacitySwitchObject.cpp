/*
 *  dgOpacitySwitchObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 16/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgOpacitySwitchObject.h"

dgOpacitySwitchObject::dgOpacitySwitchObject() {
	
}

dgOpacitySwitchObject::~dgOpacitySwitchObject() {
		
	
	for (int i=0; i<imageSet.size(); i++) {
		imageSet[i]->clear();
		delete imageSet[i];
	}
	imageSet.clear();
	
	img->clear();
	delete img;
}


void dgOpacitySwitchObject::setup (string imgURL, string name, string type) {
	
	dgSceneObject::setup(name, type);
	
	// first image is default state
	//addExtraImage(imgURL);
	
		
	img = imgAssets->addImage(imgURL);
	
	this->width = img->width;
	this->height = img->height;

	//this->width = img->width;
	//this->height = img->height;
	
	
	easePct = pct;
	blurRate = .1;
	setPct(0);
}

void dgOpacitySwitchObject::addExtraImage(string url) {
	
	ofImage * img = imgAssets->addImage(url);
	imageSet.push_back(img);
	
	
}

void dgOpacitySwitchObject::update () {
	
	dgSceneObject::update();
	
	easePct = blurRate * easePct + (1 - blurRate) * pct;
	
	int fakeTotal = imageSet.size();
	fakeTotal -=1;
	currentIndex = floor(easePct * (fakeTotal) );
	
	if ( currentIndex > imageSet.size()-2 ) currentIndex = imageSet.size()-2;
	//printf("---- \n");
	//printf("pct %f\n", easePct);
	//printf("easePCt %f\n", easePct);
	//printf("currentIndex %d\n", currentIndex);
	
}

void dgOpacitySwitchObject::draw () {
	
	dgSceneObject::draw();
	
	// find pct between each step
	
	int fakeTotal = imageSet.size();
	fakeTotal -=1;
	float stepValue = 1 / ( (float)fakeTotal);

	float currentStepPct = ((float)currentIndex * stepValue);
	float nextStepPct = (((float)currentIndex+1.0) * stepValue) -(float)currentStepPct;
	
	float pctStep = easePct - ( (float)currentIndex * stepValue );
	
	float alphaPct =   (pctStep / stepValue ) ;

	
	ofEnableAlphaBlending();
	ofPushMatrix();
	ofTranslate(pos.x - width *.5, pos.y - height * .5, 0);
	ofSetColor(255, 255, 255, 255);
	img->draw(0,0);
	
	
	
		
		if ( images.size() > 1 ) {
	
			ofSetColor(255, 255, 255, (1-alphaPct) * 255);
			imageSet[currentIndex]->draw(0, 0);
	
	
			ofSetColor(255, 255, 255, alphaPct * 255);
			imageSet[currentIndex+1]->draw(0, 0);
		
		} else  {
		//printf("ok");
		ofSetColor(255, 255, 255, (easePct) * 255);
		imageSet[0]->draw(0, 0);

		
		}	
	
	
	ofPopMatrix();
	ofDisableAlphaBlending();
	
	ofSetColor(255, 255, 255, 255);
	
}


void dgOpacitySwitchObject::setPct(float pct) {
	
	// lets make some eaaasing..
	// TODO -> quit easing if no more than 3 picts
	
	
	// round
	
	dgSceneObject::setPct(pct);
	
}