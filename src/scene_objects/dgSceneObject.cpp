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
	
	reversePct = false;

}

dgSceneObject::~dgSceneObject() {
	//printf("adios from simple object\n");
	
	for (int i=0; i<images.size(); i++) {
		//images[i]->clear();
		delete images[i];
		images[i] = NULL;
	}
	images.clear();
	
	for (int i=0; i<videos.size(); i++) {
		//videos[i]->clear();
		//delete videos[i];
	}
	videos.clear();
	
	if ( activitySwitchObject ) {
		//delete activitySwitchObject;
		activitySwitchObject = NULL;
	}
	
	configValues.clear();
	
	if ( pctRef ) ofRemoveListener(pctRef->onPctChangeEvent, this, &dgSceneObject::onPctChangeHandler);
	if ( pctStateRef ) ofRemoveListener(pctStateRef->onPctChangeEvent, this, &dgSceneObject::onPctStateChangeHandler);
	
	
	pctRef = NULL;
	pctStateRef = NULL;
	
}

void dgSceneObject::init () {
	
	
	
	
}

void dgSceneObject::initValues () {

	if ( pctRef ) {
		setPct(pctRef->pct);
		easePct = pct;
	}
	if ( pctStateRef ) {
		setStatePct(pctStateRef->pct);
	}
	
	
	printf("-------\n");
	printf("init values for ");
	printf(name.c_str());
	printf("\n");
	printf("pct : %f\n ", pct);
	printf("state pct : %f\n ",statePct);
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
	
	pct = (reversePct ) ? 1.0 : 0.0;
	easePct = 0.0;
	statePct = 1.0;
	oldPct = 0.0;
	
	activitySwitchObject = NULL;
	pctRef = NULL;
	pctStateRef = NULL;
	
}

void dgSceneObject::setPctObjectsReference(oscObject * pctRef, oscObject * pctStateRef) {
	
	this->pctRef = pctRef;
	this->pctStateRef = pctStateRef;
	
	
	if ( pctRef ) ofAddListener(pctRef->onPctChangeEvent, this, &dgSceneObject::onPctChangeHandler);
	if ( pctStateRef ) {
		statePct = 0.0;
		ofAddListener(pctStateRef->onPctChangeEvent, this, &dgSceneObject::onPctStateChangeHandler);
	}
		//if ( pctStateRef ) 
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
	
	
	//if (!active ) return;
		
	
	
	if ( activitySwitchObject ) {
		ofEnableAlphaBlending();

		ofPushMatrix();
		ofTranslate(pos.x, pos.y, 0);
		ofRotate((int)rotation + activitySwitchRotation, 0, 0, 1);
		activitySwitchObject->draw();
		ofPopMatrix();
		ofDisableAlphaBlending();
	}
	
		
	float xPos, yPos;
	ofEnableAlphaBlending();

	for (int i=0; i<images.size(); i++) {
		
		// center pos
		xPos =  - images[i]->getWidth() *.5;
		yPos =  - images[i]->getHeight() *.5;
		
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
	
	// draw beat 
	
	
	
	
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
	
	
	if ( pct < this->range.x ) pct = 0.0;
	//if ( pct > this->range.y ) pct = 1.0;
	
	
	this->pct = ( reversePct ) ? 1.0 - pct :pct;
	
	
	
	
}

void dgSceneObject::setStatePct(float pct) {
	
	if ( pct != this->statePct   ) {
		this->statePct = pct;
	}
	
}

void dgSceneObject::onPctChangeHandler(float & pct) {
	setPct(pct);
}

void dgSceneObject::onPctStateChangeHandler(float & pct) {
	setStatePct(pct);
}


/*
adding extras to component, can be video or image for now
*/

void dgSceneObject::addMedia(string url, string mediaType) {
	
		
	int currentIndex;
	
	if ( mediaType == "image" ) {
		ofTexture * img = imgAssets->addImage(url);
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

