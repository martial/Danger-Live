/*
 *  DangerScene.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "DangerScene.h"


DangerScene::DangerScene() {
	

}

void DangerScene::setup(dgData & layoutData, dgVideoData & videoData, dgCompBuilder & compBuilder, OscReceiver & oscReceiver, dgSceneEffects & effects) {
	
	background.setup();
	moduleView.setup(layoutData, compBuilder, oscReceiver,effects);
	videoView.setup(videoData);
	
	this->effects = &effects;
	
	currentMode = DGSCENEVIEWMODE_MODULE;
	
	currentView = 0;
	globalOpacity = 1.0;
	globalOpacityDown = 1.0;
	isfading = false;
	sens = 1;
	
}

void DangerScene::update() {
	
	
	switch (currentMode) {
			
		case DGSCENEVIEWMODE_MODULE:
			moduleView.update();
			break;
			
			
		case DGSCENEVIEWMODE_VIDEOS:
			videoView.update();
			break;
			
		default:
			break;
	}
	
	
	
}

void DangerScene::draw () {
	
	if(isfading && currentMode == DGSCENEVIEWMODE_MODULE ) {
		
		globalOpacity += .25 * (float)sens;
		globalOpacityDown -= .25 * (float)sens;
					
		if (sens == -1 && globalOpacity<.25 ) {
			sens = 1;
			moduleView.nextView();
			return;
		} 
		
		if (sens == 1 && globalOpacity > 1 ) {
			globalOpacityDown = 1.0;
			isfading = false;
			//continue;
			
		} 
		
		//printf("globalOpacityDown %f\n :",globalOpacityDown);
		
		if ( globalOpacity > 1.0 ) globalOpacity = 1.0;
		//if ( globalOpacityDown < 0.0 ) globalOpacityDown = 0.0;
		
		effects->brightnessPct = globalOpacity;
		effects->saturationPct = globalOpacity;
		effects->contrastPct = globalOpacityDown;
		//effects->blurPct = abs(1-globalOpacity);
		
	}
	
	ofEnableAlphaBlending();
	//ofSetColor(255, 255, 255, globalOpacity);
	
	switch (currentMode) {
			
		case DGSCENEVIEWMODE_MODULE:
			
			background.draw(moduleView.currentViewID);
			ofPushMatrix();
			// push on the right and center axis
			ofTranslate(1920*.5 - 1280*.5 + 1280*.5, 0, 0);
			moduleView.draw();
			ofPopMatrix();
			
			break;
			
		case DGSCENEVIEWMODE_VIDEOS:
			
			videoView.draw();
			
			break;
			
		default:
			break;
	}
	//ofDisableAlphaBlending();
	

}

void DangerScene::fade () {
	
	isfading = true;
	sens = -1;

	
}

void DangerScene::setCurrentView(int viewID) {
	
	this->currentView = viewID;
	
	switch (currentMode) {
			
		case DGSCENEVIEWMODE_MODULE:
			
			moduleView.setCurrentView(viewID);
			videoView.stop();
			
			break;
			
			
		case DGSCENEVIEWMODE_VIDEOS:
			
			videoView.setCurrentView(viewID);
			
			break;
			
		default:
			break;
	}
	
}

void DangerScene::changeMode (int mode) {
	
	currentMode = mode;
	setCurrentView(currentView);
	if ( mode == DGSCENEVIEWMODE_VIDEOS ) videoView.init();
	
}

void DangerScene::onMidiEvent(int adress, int val) {
	moduleView.onMidiEvent(adress, val);
	
	if ( adress == 27 && val == 127 ) {
		fade();
	}
	
}

void DangerScene::onOscEvent(customOscMessage & msg) {
	if ( currentMode == DGSCENEVIEWMODE_MODULE ) moduleView.onOscEvent(msg);
}

void DangerScene::onBeatEvent () {
	
	// calculate how many time btw one beat and another
	beatTime = ofGetElapsedTimeMillis() - oldTime;
	oldTime = ofGetElapsedTimeMillis();
	
	if ( currentMode == DGSCENEVIEWMODE_VIDEOS ) videoView.onBeatEvent(beatTime/1000);
	if ( currentMode == DGSCENEVIEWMODE_MODULE ) moduleView.onBeatEvent();
	
}
