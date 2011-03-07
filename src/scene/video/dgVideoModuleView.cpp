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
	
	#ifdef USEOFXQTKIT
	fboVideo = new ofxFBOTexture();
	fboVideo->clear(0, 0, 0, 0);
	fboVideo->allocate(this->videoSet->videos[0]->getWidth(), this->videoSet->videos[0]->getHeight(), GL_RGB);
	#endif
	
	
	
	
	
}

void dgVideoModuleView::update() {
	
	
	
	//printf("VIDEOS PLAYING : %d\n", count);
	
	// weird.
	#ifdef USEOFXQTKIT
	
	// update fbo
	ofxQTKitVideoPlayer * video = videoSet->videos[currentVideoID];
	videoSet->videos[currentVideoID]->update();
	#else
	videoSet->videos[currentVideoID]->update();
	
	if ( !videoSet->videos[currentVideoID]->isPlaying() ) {
	videoSet->videos[currentVideoID]->play();
	}
	#endif
	
	//printf("Video view update \n");
	
}

void dgVideoModuleView::draw() {
	
	/*/
	 * Check the ratio so It will work with any resolution 
	 */
	ofSetVerticalSync(true);
	
	float x,y;
	ofxVec2f videoSize = ofxUtils::getSizeRatio(1920, 1080, videoSet->videos[currentVideoID]->width, videoSet->videos[currentVideoID]->height);
	x = 1920 *.5 - videoSize.x*.5;
	y = 1080 *.5 - videoSize.y*.5;
	float scalew = (videoSize.x  ) /  videoSet->videos[currentVideoID]->width;
	float scaleh = (videoSize.y  ) / videoSet->videos[currentVideoID]->height;
	
	
	//videoSet->videos[currentVideoID]->draw(x,y,videoSize.x,videoSize.y);
	
	
	#ifdef USEOFXQTKIT
	videoSet->videos[currentVideoID]->draw(x,y,videoSize.x,videoSize.y);	
	#else
	videoSet->videos[currentVideoID]->draw(x,y,videoSize.x,videoSize.y);
		
	#endif
	
	
	//printf("draw video\n");
	
	//videoSet->videos[currentVideoID]->draw(0,0);
	
	
}

ofTexture * dgVideoModuleView::getVideoTexture () {
	
	#ifndef USEOFXQTKIT
	return &videoSet->videos[currentVideoID]->getTextureReference();
	#else 
	return fboVideo;
	#endif	
	
}

ofVideoPlayer * dgVideoModuleView::getVideoInstance() {
	return videoSet->videos[currentVideoID];
}

/*
ofxQTKitVideoPlayer * dgVideoModuleView::getVideoInstance () {
	
	return NULL;
	//return videoSet->videos[currentVideoID];
	
}
 
 */


void dgVideoModuleView::goNext() {
	
	
	int oldVideo = currentVideoID;
	
	//stop();
	videoSet->videos[currentVideoID]->setPosition(0);
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

void dgVideoModuleView::setRandomVideo() {
	
	videoSet->videos[currentVideoID]->setPosition(0);
	
	int rdm = getRandom(videoSet->videos.size() -1);
	while ( rdm == currentVideoID) {
		rdm = getRandom(videoSet->videos.size() -1);
	}
	
	currentVideoID = rdm;
	play();
}

int dgVideoModuleView::getRandom (int max) {
	return round(ofRandom(0, max));
}

void dgVideoModuleView::play() {
	
	
	
	
	stop();
	
	printf("PLAY VIDEO \n");
	currentVideoDuration = videoSet->videos[currentVideoID]->getDuration();
	
	videoSet->videos[currentVideoID]->play();
	
	
	
}

void dgVideoModuleView::stop() {
	
	printf("STOP VIDEO \n");
	
	
	for ( int i=0; i<videoSet->videos.size(); i++ ) {
		
		
		#ifdef USEOFXQTKIT
		//videoSet->videos[i]->pause();
		videoSet->videos[i]->stop();
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



