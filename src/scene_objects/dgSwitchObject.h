/*
 *  dgSwitchObject.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 09/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef DGSWITCCHOBJECT
#define DGSWITCCHOBJECT
#include "ofMain.h"
#include "dgSceneObject.h"

class dgSwitchObject : public dgSceneObject {
	
public:
	
	
	dgSwitchObject();
	~dgSwitchObject();
	
	void					setup(string imgURL, string name, string type);
	void					update();
	void					draw();
	
	void					addExtraImage(string url);
	void					setPct(float pct);
	

	
	private :
	
	//ofImage					img;
	vector<ofTexture*>		imageSet;
	int						imagesSize;
	int						currentIndex;
		
	
	
};

#endif