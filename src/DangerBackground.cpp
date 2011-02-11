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
	background.loadImage("assets/background.png");
	digitalPlaceholder.loadImage("components/DIGITAL/digital-off.png");
	digitalFont.loadFont("fonts/digital-7_italic.ttf", 40);

	
}

void DangerBackground::update () {
}

void DangerBackground::draw (int viewID) {
	
	int ofMidWidth = ofGetWidth() * .5;
	int ofMidHeight = ofGetHeight()  * .5;
	
	background.draw(ofMidWidth - background.width  * .5 , ofMidHeight  - background.height  * .5 );
	
	int digitalXPos = ofMidWidth - digitalPlaceholder.width * .5;
	int digitalYPos = 80;
	digitalPlaceholder.draw(digitalXPos, digitalYPos);
	
	ofSetColor(255, 0, 0);
	
	/*
	if ( viewID < 10 ) {
		digitalFont.drawString("0", digitalXPos +7, digitalYPos +40);
	} 	
	digitalFont.drawString(ofToString(viewID), digitalXPos + 37, digitalYPos +40);
	*/
	ofSetColor(0xffffff);
	// print 
	
	
}

