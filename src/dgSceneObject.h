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
#include "ofxQTKitVideoPlayer.h"

class dgSceneObject {

	public:
	
	dgSceneObject();
	virtual ~dgSceneObject();
	virtual void					setup(string name);
	virtual void					update();
	virtual void					draw();
	
			void					addMedia(string url, string mediaType);
	
	virtual void					setPosition(ofPoint);
	virtual void					setPosition (int x, int y);
	virtual void					setPct(float pct);
	
	
	
	string							name;
	string							adress;
	ofPoint							pos;
	
	int								width, height;
	float							pct;
	
	vector<ofImage*>				images;
	vector<ofxQTKitVideoPlayer*>	videos;
	
	bool							active;
	
};