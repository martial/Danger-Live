/*
 *  dgVideoModuleView.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 09/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgVideoModuleView.h"

void dgVideoModuleView::setup (dgVideoDataSet * videoSet) {
	
	this->videoSet = videoSet;
	currentVideoID = 0;
}

void dgVideoModuleView::update() {
	
	if ( videoSet->videos[currentVideoID]->getIsMovieDone()) {
		goNext();
	}
	videoSet->videos[currentVideoID]->update();

}

void dgVideoModuleView::draw() {
	
	/*/
	 * Check the ratio so It will work with any resolution 
	 */
		
	float x,y;
	ofxVec2f videoSize = ofxUtils::getSizeRatio(ofGetWidth(), ofGetHeight(), videoSet->videos[currentVideoID]->width, videoSet->videos[currentVideoID]->height);
	x = ofGetWidth() *.5 - videoSize.x*.5;
	y = ofGetHeight() *.5 - videoSize.y*.5;
	float scalew = (videoSize.x  ) /  videoSet->videos[currentVideoID]->width;
	float scaleh = (videoSize.y  ) / videoSet->videos[currentVideoID]->height;
	
	
	videoSet->videos[currentVideoID]->draw(x,y,videoSize.x,videoSize.y);
}

void dgVideoModuleView::goNext() {
	
	videoSet->videos[currentVideoID]->pause();
	currentVideoID++;
	if ( currentVideoID > videoSet->videos.size() -1 ) {
		currentVideoID = 0;
	}
	play();
	
}

void dgVideoModuleView::play() {
	
	
	videoSet->videos[currentVideoID]->setLoopState(OF_LOOP_NONE);
	videoSet->videos[currentVideoID]->play();
	
}

void dgVideoModuleView::stop() {
	
	for ( int i=0; i<videoSet->videos.size(); i++ ) {
		videoSet->videos[i]->pause();
	}
	
}