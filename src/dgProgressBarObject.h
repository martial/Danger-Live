/*
 *  dgProgressBarObject.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef DGPROGOBJECT
#define DGPROGOBJECT
#include "ofMain.h"
#include "dgSceneObject.h"

class dgProgressBarObject : public dgSceneObject {
	
public:
	
	
	dgProgressBarObject();
	~dgProgressBarObject();
	void					setup(string name, string type);
	void					update();
	void					draw();
	
	private :
	

	
	
};

#endif