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
	currentVideoDuration = 0;
	isWaitingForBeat = false;
}

void dgVideoModuleView::update() {
	
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
	
	
	int oldVideo = currentVideoID;
	
	currentVideoID++;
	if ( currentVideoID > videoSet->videos.size() -1 ) {
		currentVideoID = 0;
	}
	play();
	
	videoSet->videos[oldVideo]->setPosition(0);
	videoSet->videos[oldVideo]->pause();

	
}

/* Event for next video*/
void dgVideoModuleView::goNext(int & f) {
	//printf("Shoot! \n");
	goNext();
	isWaitingForBeat = false;
	//ofRemoveListener(beatEvent,this,&dgVideoModuleView::goNext);
	
}

void dgVideoModuleView::play() {
	
	
	currentVideoDuration = videoSet->videos[currentVideoID]->getDuration() ;
	//videoSet->videos[currentVideoID]->setLoopState(OF_LOOP_NONE);
	
	videoSet->videos[currentVideoID]->play();
	
}

void dgVideoModuleView::stop() {
	
	for ( int i=0; i<videoSet->videos.size(); i++ ) {
		videoSet->videos[i]->setPosition(0);
		videoSet->videos[i]->pause();
	}
	
}

void dgVideoModuleView::onBeatEvent (float beatTime) {

	this->beatTime = beatTime;
	if (  currentVideoDuration - videoSet->videos[currentVideoID]->getPositionInSeconds() < beatTime*2 && beatTime != 0  ) {
		goNext();
	}		
}


/*
 Private
 */


void dgVideoModuleView::addBeatListener () {
	
	
		printf("Add listener \n");
	//ofAddListener(beatEvent,this,&dgVideoModuleView::goNext);
	isWaitingForBeat = true;
}



