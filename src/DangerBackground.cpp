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
	
	// load digital elements
	for ( int i=0; i<13; i++ ) {
		ofImage * img = new ofImage();
		img->loadImage("images/DIGITAL/digital-"+ ofToString(i)+ ".png");
		digitalLeds.push_back(img);
	}
	
}

void DangerBackground::update () {
}

void DangerBackground::draw (int viewID) {
	
	int ofMidWidth = ofGetWidth() * .5;
	int ofMidHeight = ofGetHeight()  * .5;
	
	background.draw(ofMidWidth - background.width  * .5 , ofMidHeight  - background.height  * .5 );
	digitalLeds[viewID]->draw(ofMidWidth - digitalLeds[viewID]->width * .5, 80);

}

