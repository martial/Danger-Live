/*
 *  dgOpacitySwitchObject.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 16/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef DGOPACTIYSWITCCHOBJECT
#define DGOPACTIYSWITCCHOBJECT
#include "ofMain.h"
#include "dgSceneObject.h"

class dgOpacitySwitchObject : public dgSceneObject {
	
public:
	
	
	dgOpacitySwitchObject();
	~dgOpacitySwitchObject();
	
	void					setup(string imgURL, string name, string type);
	void					update();
	void					draw();
	
	void					addExtraImage(string url);
	void					setPct(float pct);
	
	
	
	private :
	
	ofImage			*		img;
	vector<ofImage*>		imageSet;
	int						currentIndex;
	
	
	
};

#endif