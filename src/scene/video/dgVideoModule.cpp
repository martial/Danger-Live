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
	//setCurrentView(0);
}

void dgVideoModule::update() {
	
	if ( views.size() > 0 ) {
	 views[currentView]->update();
	}
}

void dgVideoModule::draw () {
	
	views[currentView]->draw();

}

ofTexture * dgVideoModule::getVideoTexture () {
	
	return views[currentView]->getVideoTexture();
	
}

void dgVideoModule::init () {
	setCurrentView(currentView);
}

void dgVideoModule::stop () {
	
	views[currentView]->stop();
	
	
}

void dgVideoModule::setCurrentView (int viewID) {
	
	views[currentView]->stop();
	currentView = viewID;
	views[currentView]->play();
	
}

void dgVideoModule::onBeatEvent (float beatTime) {

	views[currentView]->onBeatEvent(beatTime);
}