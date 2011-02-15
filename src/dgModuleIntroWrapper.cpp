/*
 *  dgModuleIntroWrapper.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgModuleIntroWrapper.h"

void dgModuleIntroWrapper::setup(moduleData * relatedModule,string name) {
	
	currentTime = -1.0;
	dgAbstractModuleWrapper::setup(relatedModule, name);
	
	loadingSound.loadSound("sound/LOADER.wav");
	releaseSound.loadSound("sound/Release.wav");

}

void dgModuleIntroWrapper::update() {
	
	// update progress bar
	
	dgSceneObject * bar = relatedModule->getComponentByNameID("launch_bar");
	float timePct = (currentTime == -1.0 ) ? 0 : ( ofGetElapsedTimeMillis() - currentTime)  / 1800;
	if ( bar && timePct <= 1.0) bar->setPct(timePct);	
	
	
	dgSceneObject * switchOn = relatedModule->getComponentByNameID("switch_on");
	if ( switchOn ) {
		
		
	//printf("time pct %f \n", timePct);
		
	if ( timePct > 1.0 ) {
			switchOn->setPct(1.0);
		} else {
			switchOn->setPct(0.0);
		}
	}
	 
	
}

void dgModuleIntroWrapper::draw () {
	

}


void dgModuleIntroWrapper::onMidiEvent(int adress, int val) {
	
	// lanch loading
	if ( adress == 26 && val == 127 ) {
		loadingSound.play();
		currentTime =  ofGetElapsedTimeMillis();
	}
	
	if ( adress == 36  ) {
		dgSceneObject * switchOFF = relatedModule->getComponentByNameID("switch_off");
		currentTime = -1.0;
		if ( val == 127 ) {
			releaseSound.play();
			loadingSound.stop();
			switchOFF->setPct(1);
		}
		
		if ( val == 64 ) {
			switchOFF->setPct(0);
		}
		
	}
}
