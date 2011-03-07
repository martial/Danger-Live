/*
 *  dgMixerModuleWrapper.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 02/03/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgMixerModuleWrapper.h"



void dgMixerModuleWrapper::setup(moduleData * relatedModule, dgVideoModule * videoModule, string name) {
	
	dgAbstractModuleWrapper::setup(relatedModule, videoModule,name);
	screen.loadImage("components/SCREEN/screen.png");
	
}

void dgMixerModuleWrapper::update() {
	//video = videoModule->getVideoTexture();
	
	// view
	
	dgVideoModuleView * videoView = videoModule->views[videoModule->currentView];
	
	
	videoInstance = videoView->videoSet->videos[ videoView->currentVideoID];
	//videoInstance = videoSet[]
	
	//videoInstance = videoModule->getVideoInstance();
	videoInstance->update();
}

void dgMixerModuleWrapper::draw () {
	
	
	
	
	
	float scale = .327;
	ofEnableAlphaBlending();
	screen.draw(-screen.width * .5 - 6, 105);
	ofDisableAlphaBlending();
	
	
	/*
	if ( videoInstance ){
		
		if ( videoInstance->isLoaded() && videoInstance->width > 0 ) {
		videoInstance->draw(-videoInstance->getWidth()* scale * .5+5, 155, videoInstance->getWidth()*scale, videoInstance->getHeight()*scale);
			
		}
	
	}
	 
	 */
	
	//video->draw(-video->getWidth()* scale * .5+5, 155, video->getWidth()*scale, video->getHeight()*scale);
	//videoInstance->update();
	//videoInstance->draw(0,0);
	ofEnableAlphaBlending();
	ofSetVerticalSync(false);
	videoInstance->draw((int)(-videoInstance->width* scale * .5+5), 155, (int)(videoInstance->width * scale), (int)(videoInstance->height * scale));
	ofDisableAlphaBlending();
	
}


void dgMixerModuleWrapper::onMidiEvent(int adress, int val) {
	
}
