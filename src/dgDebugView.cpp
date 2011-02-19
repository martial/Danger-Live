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
	
	beatLatency = 100;
	currentTime = 0;
	visible = true;
	
	
	//fps
	numOfFps = 1440;
	fpsCounter = 0;
}

void dgDebugView::draw() {
	
	/*
	 */
	
	
	int posInArray =   fpsCounter % numOfFps;
    fpsHistory[posInArray] = (int)ofGetFrameRate();
    fpsCounter++;
	//if (fpsCounter > 256 ) fpsCounter = 0;
	
	// draw rect
	ofEnableAlphaBlending();
	
	ofSetColor(0, 0, 0, 210);
	ofRect(0, 0, 1440, ofGetHeight());
	
	// line
	ofSetColor(255, 255, 255, 90);
	ofLine(0, 90, 1440, 90);
	
	
	
	ofSetColor(255, 255, 255);
	logo.draw(1440*.5 - logo.width *.5, 45 - logo.height * .5);
	
	int fpsxPos = 1;
	int fpsyPos = 90;
	int fpsWidth = numOfFps;
	int fpsHeight = 60;
	ofSetColor(255, 255, 255, 120);
	/*
	ofLine(fpsxPos, fpsyPos, fpsWidth, fpsyPos);
	ofLine(fpsWidth, fpsyPos, fpsWidth, fpsyPos+fpsHeight);
	ofLine(fpsWidth, fpsyPos+fpsHeight, fpsxPos, fpsyPos+fpsHeight);
	ofLine(fpsxPos, fpsyPos+fpsHeight, fpsxPos, fpsyPos);
	 */
	
	ofSetColor(255, 255, 255, 255);
	 if (fpsCounter < numOfFps){
		 for (int i = 0; i < fpsCounter; i++){
			// ofVertex(i, fpsHistory[i]);
			 ofSetColor(255, (int)fpsHistory[i] * 255 / 60, (int)fpsHistory[i] * 255 / 60);
			 ofRect(fpsxPos + i, fpsyPos + fpsHeight  - fpsHistory[i], 1, 1);
		 }
	 } else {
		 int start = fpsCounter;
		 int end   = fpsCounter + numOfFps;
		 for (int i = start; i < end; i++){
			 int posInArray = i % numOfFps;              // this is tricky, it's how we deal with the "jump" in the ring buffer
			 //ofVertex(i, fpsHistory[i]);
			 ofSetColor(255, (int)fpsHistory[posInArray] * 255 / 60 ,(int)fpsHistory[posInArray] * 255 / 60);
			 ofRect(fpsxPos + i-start, fpsyPos+fpsHeight  - fpsHistory[posInArray], 1, 1);
		 }
		 
	 }
	
	string fps = "fps : ";
	fps += ofToString((int)ofGetFrameRate());
	digitalFont_tiny.drawString(fps, fpsxPos, fpsyPos  - 14 );
	
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

void dgDebugView::drawSceneFbo (ofxFBOTexture * texture, int width, int height) {
	
	
	float x,y;
	ofxVec2f videoSize = ofxUtils::getSizeRatio(width, height, texture->texData.width, texture->texData.height);
	
	//
	x = 1440 *.5 - videoSize.x*.5;
	//y = ofGetHeight() *.5 - videoSize.y*.5;
	float scalew = (videoSize.x  ) /  texture->texData.width;
	float scaleh = (videoSize.y  ) / texture->texData.height;
	
	
	// little border ( qui va bien )
	y =  90 + (900-90) * .5 - videoSize.y * .5;
	
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255, 30);
	ofRect(x-1, y-1, videoSize.x+2, videoSize.y+2);
	
	ofSetColor(255, 255, 255, 255);
	
	texture->draw(x,y ,videoSize.x,videoSize.y);
	ofDisableAlphaBlending();
	
	
}

void dgDebugView::onBeatEvent() {
	currentTime = ofGetElapsedTimeMillis();	
}