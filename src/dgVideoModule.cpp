/*
 *  dgVideoModule.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 09/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgVideoModule.h"



void dgVideoModule::setup (dgVideoData * videoData) {

	this->videoData = videoData;
	currentView = 0;
	
	/* set up views */
	
	for ( int i = 0; i< videoData->videoSets.size(); i++ ) {
		dgVideoModuleView * view = new dgVideoModuleView();
		view->setup(videoData->videoSets[i]);
		views.push_back(view);
	}
	
}

void dgVideoModule::update() {
	
	views[currentView]->update();

}

void dgVideoModule::draw () {
	
	views[currentView]->draw();

}

void dgVideoModule::init () {
	setCurrentView(currentView);
}

void dgVideoModule::setCurrentView (int viewID) {
	
	views[currentView]->stop();
	currentView = viewID;
	views[currentView]->play();
	
}