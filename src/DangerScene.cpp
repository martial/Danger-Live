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

void DangerScene::setup(dgData & layoutData, dgCompBuilder & compBuilder, OscReceiver & oscReceiver) {
	background.setup();
	
	moduleView.setup(layoutData, compBuilder, oscReceiver);
}

void DangerScene::update() {
	moduleView.update();
}

void DangerScene::draw () {
	
	background.draw();
	ofEnableAlphaBlending();
	moduleView.draw();
	ofDisableAlphaBlending();

}

void DangerScene::setCurrentView(int viewID) {
	
	moduleView.setCurrentView(viewID);
}