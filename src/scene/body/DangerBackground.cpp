/*
 *  DangerBackground.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "DangerBackground.h"

// Constructor
DangerBackground::DangerBackground(){
	
}

void DangerBackground::setup () {
	
	// load bg
	background.loadImage("components/BACKGROUND/BackgroundTest.png");
	digitalPlaceholder.loadImage("components/DIGITAL/digital-off.png");
	digitalFont.loadFont("fonts/digital-7_italic.ttf", 40);
	
	
	//DIR.setVerbose(false);
    int numfOfImgs = DIR.listDir("components/DIGITAL");
	
	for (int i = 0; i<numfOfImgs; i++) {
		ofImage * img = new ofImage();
		img->loadImage(DIR.getPath(i));
		digitalLeds.push_back(img);
		//printf("view ahou %d\n",i);

	}
	
	
}

void DangerBackground::update () {
}

void DangerBackground::draw (int viewID) {
	
	float x,y;
	ofxVec2f imgSize = ofxUtils::getSizeRatio(1920, 1080, background.width, background.height);
	x = 1920 *.5 - imgSize.x*.5;
	y = 1080 *.5 - imgSize.y*.5;
	float scalew = (imgSize.x  ) /  background.width;
	float scaleh = (imgSize.y  ) / background.height;
	
	
	
		
	background.draw(x,y,imgSize.x, imgSize.y);
	
	
	
	//printf("view id %d\n",viewID);
	if ( viewID >= 0 && viewID < digitalLeds.size() -1 ) {
		float ofMidWidth = 1920 * .5;
		int digitalXPos = ofMidWidth - digitalLeds[viewID]->width * .5;
		int digitalYPos = 40;
		digitalLeds[viewID]->draw(digitalXPos, digitalYPos);
	}
	
	
	// draw beat impulse
	
	
	
	/*
	if ( viewID < 10 ) {
		digitalFont.drawString("0", digitalXPos +7, digitalYPos +40);
	} 	
	digitalFont.drawString(ofToString(viewID), digitalXPos + 37, digitalYPos +40);
	*/
	ofSetColor(0xffffff);
	// print 
	
	
}

