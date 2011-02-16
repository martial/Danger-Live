/*
 *  dgFaderObject.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 10/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _DGFADEROBJECT
#define _DGFADEROBJECT

#include "ofMain.h";
#include "dgSceneObject.h"

class dgFaderObject : public dgSceneObject {
	
public:
	
	
	dgFaderObject();
	~dgFaderObject();
	
	void					setup(string imgURL, string name, string type);
	void					update();
	void					draw();
	
	void					addExtraImage(string url);
	void					setPct(float pct);
	
	private :
	
	ofImage			*		img;
	int						currentIndex;
	float					easePct;
	float					blurRate;
	
	
	
};


#endif