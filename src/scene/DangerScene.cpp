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
	
	this->effects = &effects;
	
	background.setup();
	moduleView.setup(layoutData, compBuilder, oscReceiver,effects,videoView);
	videoView.setup(videoData);
	videoView.init();
	
	
	currentMode = DGSCENEVIEWMODE_MODULE;
	
	modeToGo = 0;
	viewToGo = 0;
	
	currentView = 0;
	globalOpacity = 1.0;
	globalOpacityDown = 1.0;
	isfading = false;
	sens = 1;
	
}

void DangerScene::clean () {
	
	
	moduleView.clean();
	
}

void DangerScene::update() {
	
	//videoView.update();
	//moduleView.update();
	
		
	
	//return;
	
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
			ofTranslate((int)(1920*.5), 0, 0);
			moduleView.draw();
			ofPopMatrix();
			
			break;
			
		case DGSCENEVIEWMODE_VIDEOS:
			
			videoView.draw();
			
			break;
			
		default:
			break;
	}
	ofDisableAlphaBlending();

}

ofTexture * DangerScene::getVideoTexture () {
		
	return videoView.getVideoTexture();
	
}

void DangerScene::fade () {
	
	
	
	
	effects->blurFadeInOut(550);
	effects->colorFadeInOut(400, 0.0, 3, 0);
	ofAddListener(effects->onFadeChangeEvent, this, &DangerScene::onFadeChangeComplete);
	
	
}


void DangerScene::onFadeChangeComplete (int & e) {
	//printf(" / fade complete");
	ofRemoveListener(effects->onFadeChangeEvent, this, &DangerScene::onFadeChangeComplete);
	
	
	
	// check if we change mode 
	
	if ( modeToGo != currentMode ) {
		
		currentMode = modeToGo;
		//setCurrentView(currentView);
		if ( currentMode == DGSCENEVIEWMODE_VIDEOS ) {
			//videoView.init();
		} else {
			moduleView.setCurrentView(viewToGo);
		}
		
	} else {
		
		
		if ( currentMode == DGSCENEVIEWMODE_MODULE ) {
			moduleView.setCurrentView(viewToGo);
			videoView.stop();
			if ( viewToGo != 1 ) {
				videoView.stop();
			} else {
				videoView.init();
			}
		}
		
		
	}

	
		
}

void DangerScene::setCurrentView(int viewID) {
	
	viewToGo = viewID;
	fade();
	return;
	//this->currentView = viewID;
	
	switch (currentMode) {
			
		case DGSCENEVIEWMODE_MODULE:
			
			moduleView.setCurrentView(viewID);
			if ( viewID != 1 ) {
				videoView.stop();
			} else {
				videoView.init();
			}
			break;
			
			
		case DGSCENEVIEWMODE_VIDEOS:
			
			videoView.setCurrentView(viewID);
			
			break;
			
		default:
			break;
	}
	
}

void DangerScene::changeMode (int mode) {
	
	modeToGo = mode;
	fade();
	return;
	
	
	if ( mode == currentMode ) return;
	currentMode = mode;
	setCurrentView(currentView);
	if ( mode == DGSCENEVIEWMODE_VIDEOS ) videoView.init();
	
}

void DangerScene::changeVideoSet (int set) {
		
	videoView.setCurrentView(set);
	
}

void DangerScene::setRandomVideo () {
	videoView.setRandomVideo();
}

void DangerScene::onMidiEvent(int adress, int val) {
	moduleView.onMidiEvent(adress, val);
	
}

void DangerScene::onOscEvent(customOscMessage & msg) {
	if ( currentMode == DGSCENEVIEWMODE_MODULE ) moduleView.onOscEvent(msg);
}

void DangerScene::setLogoAlpha(float val) {
		
	videoView.logoAlpha = val;
	printf("alpha : %f\n ", val);
}

void DangerScene::setFlickrLogoIntensity (int val) {
	videoView.flickrIntensity = val;
}

void DangerScene::onSignalEvent(float val) {
	videoView.logoAlphaVariation = val;
}

void DangerScene::onBeatEvent () {
	
	// calculate how many time btw one beat and another
	beatTime = ofGetElapsedTimeMillis() - oldTime;
	oldTime = ofGetElapsedTimeMillis();
	
	if ( currentMode == DGSCENEVIEWMODE_VIDEOS || currentView == 1 ) videoView.onBeatEvent(beatTime/1000);
	
	if ( currentMode == DGSCENEVIEWMODE_MODULE ) moduleView.onBeatEvent();
	
}
