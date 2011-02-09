/*
 *  DangerBackground.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include "ofMain.h"

class DangerBackground {

	
	public :
	DangerBackground();
	void setup();
	void update();
	void draw(int viewID);
	
	private:
	
	ofImage				background;
	vector<ofImage*>	digitalLeds;
	
	
	
	
};