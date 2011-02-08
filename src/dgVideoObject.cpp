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
	printf("adios from video object\n");
	mainVideo->close();
	delete mainVideo;
	mainVideo = NULL;
}



void dgVideoObject::setup (string videoUrl, string name) {
	
	dgSceneObject::setup(name);
	
	int mode = OFXQTVIDEOPLAYER_MODE_PIXELS_ONLY;
	mainVideo = new ofxQTKitVideoPlayer();
	mainVideo->loadMovie(videoUrl, mode);
	
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
	
	//ofEnableAlphaBlending();
	mainVideo->draw(pos.x, pos.y);
	//ofDisableAlphaBlending();
}


/*


*/


void dgVideoObject::setPct(float pct) {
	//printf ("Number of pct : %f\n", pct);
	dgSceneObject::setPct(pct);
	mainVideo->setPosition(pct);
	
}