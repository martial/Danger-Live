/*
 *  dgMultipleLedObject.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 10/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */



#ifndef _DGMLTLEDOBJ
#define _DGMLTLEDOBJ

#include "ofMain.h";
#include "dgSceneObject.h"
#include "dgSwitchObject.h"

class dgMultipleLedObject : public dgSceneObject {
	
public:
	
	
	dgMultipleLedObject();
	~dgMultipleLedObject();
	
	void					setup(string name, string type);
	void					init();
	void					addSwitchObject(dgSceneObject * switchObj);
	void					update();
	void					draw();
	
	void					addExtraImage(string url);
	void					setPct(float pct);
	
	private :
	
	vector<dgSceneObject*>			switchObjects;

	
	
};


#endif