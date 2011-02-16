/*
 *  dgSceneObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgSceneObject.h"

dgSceneObject::dgSceneObject() {
	
	
	
}

dgSceneObject::~dgSceneObject() {
	//printf("adios from simple object\n");
	
	for (int i=0; i<images.size(); i++) {
		images[i]->clear();
		delete images[i];
	}
	images.clear();
}

void dgSceneObject::init () {
	
}


void dgSceneObject::setup (string name, string type) {
	
	this->name = name;
	this->type = type;
	
	pos.x = 0;
	pos.y = 0;
	
	width = 0;
	height = 0;
	
	blurRate = 0.0;
	
	rotation = 0.0;
	
	active = false;
	
	pct = 0.0;
	oldPct = 0.0;
	
	activitySwitchObject = NULL;
	
}

void dgSceneObject::update () {
	
	if ( activitySwitchObject ) {
		float activityPct = ( oldPct != pct ) ? 1.0 : 0.0;
		activitySwitchObject->setPct(activityPct);
		activitySwitchObject->update();
	}
	
	
	for (int j=0; j<videos.size(); j++) {
		videos[j]->update();
	}
	
	this->oldPct = pct;
	
	//pct = ofClamp(abs(cos(ofGetFrameNum()/100)), 0, 1);
	
}

void dgSceneObject::draw () {
	
	
	
		
	
	
	if ( activitySwitchObject ) {
		ofEnableAlphaBlending();

		ofPushMatrix();
		ofTranslate(pos.x, pos.y, 0);
		ofRotate((int)rotation, 0, 0, 1);
		activitySwitchObject->draw();
		ofPopMatrix();
		ofDisableAlphaBlending();
	}
	
		
	float xPos, yPos;
	ofEnableAlphaBlending();

	for (int i=0; i<images.size(); i++) {
		
		// center pos
		xPos =  - images[i]->width *.5;
		yPos =  - images[i]->height *.5;
		
		ofPushMatrix();
		ofTranslate(pos.x +xPos, pos.y +yPos, 0);
		ofRotate((int)rotation, 0, 0, 1);
		images[i]->draw(0,0);
		ofPopMatrix();
	}
	
	// draw medias
	for (int j=0; j<videos.size(); j++) {
		xPos =  - videos[j]->width *.5;
		yPos =  - videos[j]->height *.5;
		ofPushMatrix();
		ofTranslate(pos.x +xPos, pos.y +yPos, 0);
		ofRotate(rotation, 0, 0, 1);
		ofEnableAlphaBlending();
		videos[j]->draw(0,0);
		ofDisableAlphaBlending();
		ofPopMatrix();
	}
	ofDisableAlphaBlending();
	
	
	
}


/*
 getter and setter
*/

void dgSceneObject::setPosition (ofPoint pos) {
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

void dgSceneObject::setPosition (int x, int y) {
	this->pos.x = x;
	this->pos.y = y;
	
	//printf("set position %d\n ", x);
}

void dgSceneObject::setPct(float pct) {
	
	if ( pct != this->pct   ) {
	this->pct = pct;
	}
	
}


/*
adding extras to component, can be video or image for now
*/

void dgSceneObject::addMedia(string url, string mediaType) {
	
		
	int currentIndex;
	
	if ( mediaType == "image" ) {
		ofImage * img = imgAssets->addImage(url);
		images.push_back(img);
	}
	
	if ( mediaType == "video" ) {
		ofxQTKitVideoPlayer * video = new ofxQTKitVideoPlayer();
		video->loadMovie(url, OFXQTVIDEOPLAYER_MODE_TEXTURE_ONLY);
		videos.push_back(video);
	}
				
}

void dgSceneObject::addConfig(float val) {
	configValues.push_back(val);
}

void dgSceneObject::addSwitchObject(dgSceneObject * switchObj) {
		// nothing
}

void dgSceneObject::addActivitySwitchObject(dgSceneObject * actSwitchObject) {
	this->activitySwitchObject = actSwitchObject;
}

