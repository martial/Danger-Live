/*
 *  dgVideoObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgVideoObject.h"

dgVideoObject::dgVideoObject() {
}


dgVideoObject::~dgVideoObject() {
	//printf("adios from video object\n");
	
	
	//mainVideo->pause();
	//mainVideo->closeMovie();
	delete mainVideo;
	//mainVideo = NULL;
}



void dgVideoObject::setup (string videoUrl, string name, string type) {
	
	dgSceneObject::setup(name, type);
	
	int mode = OFXQTVIDEOPLAYER_MODE_TEXTURE_ONLY;
	mainVideo = new ofxQTKitVideoPlayer();
	mainVideo->loadMovie(ofToDataPath(videoUrl), mode);
	
	this->width = mainVideo->width;
	this->height = mainVideo->height;
	
	//mainVideo->play();
	
	
	
}

void dgVideoObject::update () {
	
	dgSceneObject::update();
	mainVideo->update();
	
}

void dgVideoObject::draw () {
	
	dgSceneObject::draw();
	
	ofEnableAlphaBlending();
	ofPushMatrix();
	ofTranslate(pos.x - width *.5, pos.y - height * .5, 0);
	mainVideo->draw(0, 0);
	ofPopMatrix();
	ofDisableAlphaBlending();
}


/*


*/


void dgVideoObject::setPct(float pct) {
	//printf ("Number of pct : %f\n", pct);
	if ( this->pct != pct ) {
	dgSceneObject::setPct(pct);
	mainVideo->setPosition(pct);
	}
	
}