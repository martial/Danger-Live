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

void DangerScene::setup(dgData & layoutData, dgVideoData & videoData, dgCompBuilder & compBuilder, OscReceiver & oscReceiver) {
	
	background.setup();
	moduleView.setup(layoutData, compBuilder, oscReceiver);
	videoView.setup(videoData);
	
	currentMode = DGSCENEVIEWMODE_MODULE;
	
	currentView = 0;
	
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
	
	
	switch (currentMode) {
			
		case DGSCENEVIEWMODE_MODULE:
			
			background.draw(currentView);
			ofPushMatrix();
			ofTranslate(1920*.5 - 1280*.5, 0, 0);
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

void DangerScene::onOscEvent() {
	if ( currentMode == DGSCENEVIEWMODE_MODULE ) moduleView.onOscEvent();
}

void DangerScene::onBeatEvent () {
	
	// calculate how many time btw one beat and another
	beatTime = ofGetElapsedTimeMillis() - oldTime;
	oldTime = ofGetElapsedTimeMillis();
	
	if ( currentMode == DGSCENEVIEWMODE_VIDEOS ) videoView.onBeatEvent(beatTime/1000);
	
}
