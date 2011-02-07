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
	
	background.loadImage("assets/background.png");
	
}

void DangerBackground::update () {
}

void DangerBackground::draw () {
	background.draw(ofGetWidth() * .5 - background.width  * .5 , ofGetHeight()  * .5  - background.height  * .5 );
	
}

