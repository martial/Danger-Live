/*
 *  dgSceneObject.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include "ofMain.h"

class dgSceneObject {

	public:
	
	virtual void setup(string name);
	virtual void update();
	virtual void draw();
	
	virtual void setPosition(ofPoint);
	
	
	string			name;
	ofPoint			pos;
	
	
};