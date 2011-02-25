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
	
	effects->blurFadeInOut(600);
	effects->colorFadeInOut(500, 0.2, 3, 0);
	ofAddListener(effects->onFadeChangeEvent, this, &DangerScene::onFadeChangeComplete);
	
	
}


void DangerScene::onFadeChangeComplete (int & e) {
	printf(" / fade complete");
	ofRemoveListener(effects->onFadeChangeEvent, this, &DangerScene::onFadeChangeComplete);
	if ( currentMode == DGSCENEVIEWMODE_MODULE ) moduleView.nextView();
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
