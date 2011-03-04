/*
 *  dgImageObject.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef DGIMGOBJECT
#define DGIMGOBJECT
#include "ofMain.h"
#include "dgSceneObject.h"

class dgImageObject : public dgSceneObject {
	
public:
	
	
							dgImageObject();
							~dgImageObject();
	void					setup(string imgURL, string name, string type);
	void					update();
	void					draw();
		
	private :
	
	ofTexture			*		img;
	
	
	
};

#endif