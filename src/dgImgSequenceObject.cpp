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
		images[i]->clear();
		delete images[i];
	}
	images.clear();
	
}


void dgImgSequenceObject::setup (string folder, string name, string type) {
	
	dgSceneObject::setup(name, type);
	
	// get imgs
	
	DIR.setVerbose(false);
    int numfOfImgs = DIR.listDir(folder);
	
	for (int i = 0; i<numfOfImgs; i++) {
		addExtraImage(DIR.getPath(i));
	}

	
	//addExtraImage(imgURL);
	
	this->width = images[0]->width;
	this->height = images[0]->height;
	
	easePct = pct;
	blurRate = .2;
	setPct(0);
}



void dgImgSequenceObject::addExtraImage(string url) {
	
	ofImage * img = imgAssets->addImage(url);
	images.push_back(img);
	
	this->width = img->width*.5;
	this->height = img->height * .5;
	
	
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
	images[currentIndex]->draw(0, 0);
	ofPopMatrix();
	ofDisableAlphaBlending();
}


void dgImgSequenceObject::setPct(float pct) {
		
	
	dgSceneObject::setPct(pct);
	
}