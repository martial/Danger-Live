/*
 *  dgDebugView.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 13/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgDebugView.h"

void dgDebugView::setup() {
	
	digitalFont.loadFont("fonts/digital-7_italic.ttf", 32);
	digitalFont_tiny.loadFont("fonts/digital-7_italic.ttf", 18);
	beatLatency = 200;
	currentTime = 0;
	visible = true;
}

void dgDebugView::draw() {
	
	// draw rect
	ofEnableAlphaBlending();
	
	ofSetColor(0, 0, 0, 210);
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
	
	// line
	ofSetColor(255, 255, 255, 90);
	ofLine(0, 90, ofGetWidth(), 90);
	
	
	ofSetColor(255, 255, 255);
	
	// draw beat man
	float time = ofGetElapsedTimeMillis() - currentTime;
	if ( time < beatLatency ) {
		ofSetColor(255, 255, 255);
		ofRect(ofGetWidth()-90, 0, 90, 90);		
	}
	
	ofSetColor(255, 255, 255);
	digitalFont.drawString("DANGER_LIVE_PANEL", 10, 35);
	
	string fps = "fps : ";
	fps += ofToString((int)ofGetFrameRate());
	digitalFont_tiny.drawString(fps, 10, 70);
	
	ofDisableAlphaBlending();

}

void dgDebugView::drawSceneFbo (ofxFBOTexture & texture) {
	
	
	float x,y;
	ofxVec2f videoSize = ofxUtils::getSizeRatio(960, 540, texture.texData.width, texture.texData.height);
	
	//
	x = 1440 *.5 - videoSize.x*.5;
	//y = ofGetHeight() *.5 - videoSize.y*.5;
	float scalew = (videoSize.x  ) /  texture.texData.width;
	float scaleh = (videoSize.y  ) / texture.texData.height;
	
	
	// little border ( qui va bien )
	y =  90 + (900-90) * .5 - videoSize.y * .5;
	
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255, 30);
	ofRect(x-1, y-1, videoSize.x+2, videoSize.y+2);
	ofDisableAlphaBlending();
	ofSetColor(255, 255, 255, 255);
	ofEnableAlphaBlending();
	texture.draw(x,y ,videoSize.x,videoSize.y);
	ofDisableAlphaBlending();
	
	
}

void dgDebugView::onBeatEvent() {
	currentTime = ofGetElapsedTimeMillis();	
}