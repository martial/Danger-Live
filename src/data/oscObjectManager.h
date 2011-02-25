/*
 *  oscObjectManager.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 25/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _OSC_OBJMANAGER
#define _OSC_OBJMANAGER

#include "ofMain.h"
#include "oscObject.h"

class oscObjectManager {
	
	public:
	
	//void setup();
	void update();
	void draw();
	
	void addObject(string adress, bool isStateAdress);
	oscObject * getObjectsByAdress(string adress) ;
	void getRelatedObjects (string val, vector<oscObject*> * oscObjects);
	
	private:
	
	vector<oscObject*>		objects;
	
	
};

#endif