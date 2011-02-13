/*
 *  dgVideoModuleView.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 09/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgVideoModuleView.h"

//#define USEOFXQTKIT

void dgVideoModuleView::setup (dgVideoDataSet & videoSet) {
	
	this->videoSet = &videoSet;
	currentVideoID = 0;
	currentVideoDuration = 0;
	isWaitingForBeat = false;
}

void dgVideoModuleView::update() {
	
	// weird.
	#ifdef USEOFXQTKIT
	#else
	videoSet->videos[currentVideoID]->play();
	#endif
	
	videoSet->videos[currentVideoID]->idleMovie();
	
}

void dgVideoModuleView::draw() {
	
	/*/
	 * Check the ratio so It will work with any resolution 
	 */
		
	float x,y;
	ofxVec2f videoSize = ofxUtils::getSizeRatio(1920, 1080, videoSet->videos[currentVideoID]->width, videoSet->videos[currentVideoID]->height);
	x = 1920 *.5 - videoSize.x*.5;
	y = 1080 *.5 - videoSize.y*.5;
	float scalew = (videoSize.x  ) /  videoSet->videos[currentVideoID]->width;
	float scaleh = (videoSize.y  ) / videoSet->videos[currentVideoID]->height;
	
	
	videoSet->videos[currentVideoID]->draw(x,y,videoSize.x,videoSize.y);
	
	
	printf("draw video\n");
	
	//videoSet->videos[currentVideoID]->draw(0,0);
	
	
}

void dgVideoModuleView::goNext() {
	
	
	int oldVideo = currentVideoID;
	
	stop();
	
	currentVideoID++;
	if ( currentVideoID > videoSet->videos.size() -1 ) {
		currentVideoID = 0;
	}
	play();
	
	//videoSet->videos[oldVideo]->setPosition(0);
	//videoSet->videos[oldVideo]->stop();

	
}

/* Event for next video*/
void dgVideoModuleView::goNext(int & f) {
	//printf("Shoot! \n");
	goNext();
	isWaitingForBeat = false;
	//ofRemoveListener(beatEvent,this,&dgVideoModuleView::goNext);
	
}

void dgVideoModuleView::play() {
	
	
	currentVideoDuration = videoSet->videos[currentVideoID]->getDuration();
	videoSet->videos[currentVideoID]->setLoopState(OF_LOOP_NONE);
	//videoSet->videos[currentVideoID]->setSpeed(1.0);
	videoSet->videos[currentVideoID]->play();
	
}

void dgVideoModuleView::stop() {
	
	for ( int i=0; i<videoSet->videos.size(); i++ ) {
		videoSet->videos[i]->setPosition(0);
		
		#ifdef USEOFXQTKIT
		videoSet->videos[i]->pause();
		#else 
		videoSet->videos[i]->stop();
		#endif
		
		
	}
}

void dgVideoModuleView::onBeatEvent (float beatTime) {

	this->beatTime = beatTime;
	
	float currentVideoPos = videoSet->videos[currentVideoID]->getPosition() * currentVideoDuration;
	
	if (  currentVideoDuration - currentVideoPos < beatTime*2 && beatTime != 0  ) {
		goNext();
	}		
}


/*
 Private
 */


void dgVideoModuleView::addBeatListener () {
	
	
		
	//ofAddListener(beatEvent,this,&dgVideoModuleView::goNext);
	isWaitingForBeat = true;
}



