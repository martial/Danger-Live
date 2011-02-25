/*
 *  fpsViewer.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 25/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "fpsViewer.h"

void fpsViewer::setup(int width, int height, int maxFps){
	
	this->width = width;
	this->height = height;
	this->maxFps = maxFps;
	
	fpsHistory.reserve(width);
	
	//fps
	
	fpsCounter = 0;
	
}
void fpsViewer::update() {
	
	int posInArray =   fpsCounter % width;
    fpsHistory[posInArray] = (int)ofGetFrameRate();
    fpsCounter++;
	
}
void fpsViewer::draw(int x, int y) {
	
	draw(x,y,width, height);
	
}
void fpsViewer::draw(int x, int y,int width, int height) {
	
	
	
	
	
	ofSetColor(255, 255, 255, 255);
	if (fpsCounter < width){
		for (int i = 0; i < fpsCounter; i++){
			// ofVertex(i, fpsHistory[i]);
			ofSetColor(255, (int)fpsHistory[i] * 255 / maxFps, (int)fpsHistory[i] * 255 / maxFps);
			ofRect(x + i, y + maxFps  - fpsHistory[i], 1, 1);
		}
	} else {
		int start = fpsCounter;
		int end   = fpsCounter + width;
		for (int i = start; i < end; i++){
			int posInArray = i % width;              // this is tricky, it's how we deal with the "jump" in the ring buffer
			//ofVertex(i, fpsHistory[i]);
			ofSetColor(255, (int)fpsHistory[posInArray] * 255 / maxFps ,(int)fpsHistory[posInArray] * 255 / maxFps);
			ofRect(x + i-start, y+maxFps  - fpsHistory[posInArray], 1, 1);
		}
		
	}
	
	
}
