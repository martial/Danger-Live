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
	printf("adios from simple object\n");
	
	for (int i=0; i<images.size(); i++) {
		images[i]->clear();
		delete images[i];
	}
	images.clear();
}


void dgSceneObject::setup (string name) {
	
	this->name = name;
	
	pos.x = 0;
	pos.y = 0;
	
	width = 0;
	height = 0;
	
	active = false;
	
}

void dgSceneObject::update () {
	
	for (int j=0; j<videos.size(); j++) {
		videos[j]->update();
	}

}

void dgSceneObject::draw () {
	
	if ( active ) {
		pos.x += ofRandom(0, 1);
	}
	
	float xPos, yPos;
	
	for (int i=0; i<images.size(); i++) {
		
		// center pos
		xPos = this->width * .5 - images[i]->width *.5;
		yPos = this->height * .5 - images[i]->height *.5;
		images[i]->draw(pos.x + xPos, pos.y + yPos);
	}
	
	// draw medias
	for (int j=0; j<videos.size(); j++) {
		xPos = this->width * .5 - videos[j]->width *.5;
		yPos = this->height * .5 - videos[j]->height *.5;
		videos[j]->draw(pos.x + xPos, pos.y + yPos);
	}
	
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
	
	printf("set position %d\n ", x);
}

void dgSceneObject::setPct(float pct) {
	
	this->pct = pct;
	
}


/*
adding extras to component, can be video or image for now
*/

void dgSceneObject::addMedia(string url, string mediaType) {
	
		
	int currentIndex;
	
	if ( mediaType == "image" ) {
		ofImage * img = new ofImage(); 
		img->loadImage(url);
		
		images.push_back(img);
	}
	
	if ( mediaType == "video" ) {
		ofxQTKitVideoPlayer * video = new ofxQTKitVideoPlayer();
		video->loadMovie(url, OFXQTVIDEOPLAYER_MODE_TEXTURE_ONLY);
		videos.push_back(video);
	}
				
}