/*
 *  dgImgSequenceObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 14/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgImgSequenceObject.h"


dgImgSequenceObject::dgImgSequenceObject() {
	
}

dgImgSequenceObject::~dgImgSequenceObject() {
	
	for ( int i= 0; i< images.size(); i++) {
		//images[i]->clear();
		//delete images[i];
	}
	images.clear();
	
}


void dgImgSequenceObject::setup (string folderOn, string folderOff, string name , string type ) {
	
	dgSceneObject::setup(name, type);
	
	// get imgs
	
	//DIR.setLogLevel();
    int numfOfImgs = DIR.listDir(folderOn);
	
	for (int i = 0; i<numfOfImgs; i++) {
		addExtraImage(DIR.getPath(i), "");
	}
	
	if ( folderOff != "") {
			
		DIR.reset();
		numfOfImgs= DIR.listDir(folderOff);
		for (int i = 0; i<numfOfImgs; i++) {
			addExtraImage(DIR.getPath(i), "off_state");
		}
		
	}

	
	//addExtraImage(imgURL);
	
	this->width = images[0]->getWidth();
	this->height = images[0]->getHeight();
	
	easePct = pct;
	blurRate = .35;
	setPct(0);
}



void dgImgSequenceObject::addExtraImage(string url, string imgSet) {
	
	
	if ( imgSet =="off_state" ) {
	
	ofTexture * img = imgAssets->addImage(url);
	imagesOff.push_back(img);
	
	this->width = img->getWidth()*.5;
	this->height = img->getHeight() * .5;
	
	} else  {
		
	ofTexture * img = imgAssets->addImage(url);
	images.push_back(img);
		
	this->width = img->getWidth()*.5;
	this->height = img->getHeight() * .5;
		
		
	}
	
	
	
}



void dgImgSequenceObject::update () {
	
	dgSceneObject::update();
	
	
	
	easePct = blurRate * easePct + (1 - blurRate) * pct;
	currentIndex = floor((easePct * (images.size())) + 0.5);
	if ( currentIndex > images.size()-1 ) currentIndex = images.size()-1;
	
	
	
	//printf("---- \n");
	//printf("pct %f\n", easePct);
	//printf("easePCt %f\n", easePct);
	//printf("currentIndex %d\n", currentIndex);
	
}

void dgImgSequenceObject::draw () {
	
	dgSceneObject::draw();
	
	ofEnableAlphaBlending();
	ofPushMatrix();
	ofTranslate(pos.x - width *.5, pos.y - height * .5, 0);
	
	if ( currentIndex >= 0 && currentIndex <= images.size() -1) {
		
	if (imagesOff.size() == images.size() && statePct == 0.0) {
		imagesOff[currentIndex]->draw(0,0);
	} 
	
	if ( statePct > 0 ) { 
		ofSetColor(255, 255, 255, statePct * 255);
		images[currentIndex]->draw(0, 0);
	} else {
			
		if (imagesOff.size() <= 0 ) {
			ofSetColor(255, 255, 255, 255);
			images[0]->draw(0, 0);
		}
	}
		
	
	
	}
	
	ofPopMatrix();
	ofDisableAlphaBlending();
}


void dgImgSequenceObject::setPct(float pct) {
		
	
	dgSceneObject::setPct(pct);
	
}