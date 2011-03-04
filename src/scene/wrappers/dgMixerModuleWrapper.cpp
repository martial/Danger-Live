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
	
		
}

void dgMixerModuleWrapper::draw () {
	
	ofTexture * video = videoModule->getVideoTexture();
	
	
	float scale = .327;
	ofEnableAlphaBlending();
	screen.draw(-screen.width * .5 - 6, 105);
	ofDisableAlphaBlending();
	video->draw(-video->getWidth()* scale * .5+5, 155, video->getWidth()*scale, video->getHeight()*scale);
	
	
}


void dgMixerModuleWrapper::onMidiEvent(int adress, int val) {
	
}
