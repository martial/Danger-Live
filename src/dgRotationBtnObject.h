/*
 *  dgRotationBtnObject.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 11/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _DGROTBTNOBJ
#define _DGROTBTNOBJ

#include "ofMain.h"
#include "dgSceneObject.h"

class dgRotationBtnObject : public dgSceneObject {

	public:
	
	dgRotationBtnObject();
	~dgRotationBtnObject();
	
	void					setup(string imgURL, string name, string type);
	void					update();
	void					draw();
	
	void					addExtraImage(string url);
	void					addActivitySwitchObject(dgSceneObject * actSwitchObject);
	
	
	private :
	
	ofImage					img;
	vector<ofImage*>		frontImages;
	float					btnRotation;
	
	
	
};

#endif