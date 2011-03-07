/*
 *  dgVideoModule.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 09/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgVideoModule.h"



void dgVideoModule::setup (dgVideoData & videoData) {

	this->videoData = &videoData;
	
	currentView = 0;
	/* set up views */
	
	for ( int i = 0; i< this->videoData->videoSets.size(); i++ ) {
		dgVideoModuleView * view = new dgVideoModuleView();
		dgVideoDataSet * set  = this->videoData->videoSets[i];
		view->setup(*set);
		views.push_back(view);
	}
	
	logoAlpha = 0.0;
	logoAlphaVariation = 0.0;
	flickrCount = 0;
	flickrIntensity = 1;
	logo.loadImage("components/LOGO_DANGER/LOGO.png");
	//setCurrentView(0);
}

void dgVideoModule::update() {
	
	
	//printf("Video module update \n");
	
	if ( views.size() > 0 ) {
	 views[currentView]->update();
	}
}

void dgVideoModule::draw () {
	
	
	
	
	// 
	
	if ( flickrCount > flickrIntensity ) {
		views[currentView]->draw();
		ofEnableAlphaBlending();
		ofSetColor(255, 255, 255, logoAlpha*200 + logoAlphaVariation * 55 );
		logo.draw(1920*.5 - logo.width * .5 , 120);
		ofDisableAlphaBlending();	
		flickrCount = 0;
		
	} else {
		
	}
	
	
	flickrCount ++;
	
	
	
	
}

ofTexture * dgVideoModule::getVideoTexture () {
	
	return views[currentView]->getVideoTexture();
	
}

//ofxQTKitVideoPlayer  * dgVideoModule::getVideoInstance() {
	//return views[currentView]->getVideoInstance();
//}

ofVideoPlayer * dgVideoModule::getVideoInstance() {
	return views[currentView]->getVideoInstance();
}



void dgVideoModule::init () {
	stop();
	//currentView = viewID;
	views[currentView]->play();
}

void dgVideoModule::play() {
	//views[currentView]->play();
}

void dgVideoModule::stop () {
	
	views[currentView]->stop();
	
}

void dgVideoModule::setCurrentView (int viewID) {
	
	stop();
	currentView = viewID;
	views[currentView]->play();
	
}

void dgVideoModule::setRandomVideo () {
	views[currentView]->setRandomVideo();
}

void dgVideoModule::onBeatEvent (float beatTime) {

	views[currentView]->onBeatEvent(beatTime);
}