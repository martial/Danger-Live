/*
 *  DangerScene.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#pragma once
#include "ofMain.h"
#include "DangerBackground.h"

class DangerScene {

	public:
	
	DangerScene();
	void setup();
	void update();
	void draw();
	
	private:
	
	DangerBackground	background;
	
};