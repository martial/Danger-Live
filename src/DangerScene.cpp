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
	videoView.setup(&videoData);
	
	currentMode = DGSCENEVIEWMODE_MODULE;
	
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
			
			background.draw();
			ofEnableAlphaBlending();
			moduleView.draw();
			ofDisableAlphaBlending();
			
			break;
			
		case DGSCENEVIEWMODE_VIDEOS:
			
			videoView.draw();
			
			break;
			
		default:
			break;
	}
	
	

}

void DangerScene::setCurrentView(int viewID) {
	
	switch (currentMode) {
			
		case DGSCENEVIEWMODE_MODULE:
			
			moduleView.setCurrentView(viewID);
			
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
	if ( mode == DGSCENEVIEWMODE_VIDEOS ) videoView.init();
	
}