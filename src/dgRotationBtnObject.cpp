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
	
	img = imgAssets->addImage(imgURL);
	this->width = img->width;
	this->height = img->height;
	
	easePct = pct;
	blurRate = .3;
	
}

void dgRotationBtnObject::addExtraImage(string url) {
	
	ofImage * img = imgAssets->addImage(url);
	frontImages.push_back(img);
	
	
}

void dgRotationBtnObject::addActivitySwitchObject(dgSceneObject * actSwitchObject) {
	dgSceneObject::addActivitySwitchObject(actSwitchObject);
}

void dgRotationBtnObject::update () {
	
	dgSceneObject::update();
	
	easePct = blurRate * easePct + (1 - blurRate) * pct;
	
	//pct += .01;	
	// find good rotation
	float startingRot = this->configValues[0];
	float endingRot = this->configValues[1];
	btnRotation = startingRot + (endingRot*easePct);
	
	
	
	
}

void dgRotationBtnObject::draw () {
	
	dgSceneObject::draw();
	
	ofEnableAlphaBlending();
	
	ofPushMatrix();
	
	ofTranslate(pos.x - width *.5, pos.y - height * .5, 0);
	
	ofPushMatrix();
	ofTranslate(img->width*.5, img->height*.5, 0);
	ofRotate(btnRotation, 0, 0, 1);
	img->draw(-img->width*.5, -img->height*.5);
	ofPopMatrix();
	
	for (int i=0; i<frontImages.size(); i++) {
		frontImages[i]->draw(0, 0 );
	}
	
	ofPopMatrix();
	
	ofDisableAlphaBlending();
}

void dgRotationBtnObject::setPct(float pct ) {
	dgSceneObject::setPct(pct);
	
	
	}
