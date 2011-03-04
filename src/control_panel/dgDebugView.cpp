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
	digitalFont_tiny.loadFont("fonts/digital-7_italic.ttf", 11);
	
	logo.loadImage("assets/logo.png");
	
	fps.setup(1440, 900, 40);
	
	beatLatency = 100;
	currentTime = 0;
	visible = true;
	
	
	
}

void dgDebugView::draw() {
	
	/*
	 */
	
	
	
	
	// draw rect
	ofEnableAlphaBlending();
	
	ofSetColor(0, 0, 0, 210);
	ofRect(0, 0, 1440, ofGetHeight());
	
	// line
	ofSetColor(255, 255, 255, 90);
	ofLine(0, 90, 1440, 90);
	
	
	
	ofSetColor(255, 255, 255);
	logo.draw(1440*.5 - logo.width *.5, 45 - logo.height * .5);
	
	fps.update();
	fps.draw(0,90);
		
	string fps = "fps : ";
	fps += ofToString((int)ofGetFrameRate());
	digitalFont_tiny.drawString(fps, 3, 90  - 14 );
	
	// draw beat man
	float time = ofGetElapsedTimeMillis() - currentTime;
	if ( time < beatLatency ) {
		ofSetColor(255, 255, 255);
		ofRect(1440-90, 0, 90, 90);		
	}
	
	ofSetColor(255, 255, 255);
	//digitalFont.drawString("DANGER_LIVE_PANEL", 10, 35);
	
	
	
	ofDisableAlphaBlending();

}

void dgDebugView::drawSceneFbo (ofxFBOTexture * texture, float width, float height, float scale) {
	
	
	float x,y;
	ofxVec2f videoSize = ofxUtils::getSizeRatio(width, height, (float)texture->texData.width * scale, (float)texture->texData.height* scale);
	
	//
	
	//y = ofGetHeight() *.5 - videoSize.y*.5;
	//float scalew = (videoSize.x  ) /  texture->texData.width;
	//float scaleh = (videoSize.y  ) / texture->texData.height;
	
	
	// little border ( qui va bien )
	x = width *.5 - videoSize.x *scale *.5;
	y =  90 +  ((height -90) * .5 - videoSize.y *scale  * .5);
	
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255, 30);
	ofRect(x-1, y-1, videoSize.x*scale +2, videoSize.y*scale +2);
	ofDisableAlphaBlending();
	ofSetColor(255, 255, 255, 255);
	
	
	texture->draw(x,y ,videoSize.x*scale,videoSize.y*scale);
	
	
	digitalFont_tiny.drawString(ofToString(scale), x+3, y+3);
	
	
}

void dgDebugView::drawCurrentVideo (ofTexture * videoTexture, float width, float height, float scale) {
	//videoTexture->draw(0,0);
	float x,y;
	//ofxVec2f videoSize = ofxUtils::getSizeRatio(width, height, (float)texture->texData.width * scale, (float)texture->texData.height* scale);
	//videoTexture->draw(x,y ,videoSize.x*scale,videoSize.y*scale);
}

void dgDebugView::onBeatEvent() {
	currentTime = ofGetElapsedTimeMillis();	
}