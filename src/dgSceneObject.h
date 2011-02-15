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
	virtual void					setup(string name, string type);
	virtual void					init();
	virtual void					update();
	virtual void					draw();
	
			void					addMedia(string url, string mediaType);
			void					addConfig(float val);
	virtual void					addSwitchObject(dgSceneObject * switchObj);
	virtual void					addActivitySwitchObject(dgSceneObject * actSwitchObject);
	virtual void					setPosition(ofPoint);
	virtual void					setPosition (int x, int y);
	virtual void					setPct(float pct);
	
	
	
	string							name;
	string							nameId;
	string							adress;
	string							type;
	string							sceneObjectRefName;
	string							activityObjectRefName;
	ofPoint							pos;
	ofPoint							activitySwitchObjPos;
	
	
	
	float							rotation;
	float							blurRate;
	
	int								width, height;
	float							pct, oldPct;
	vector<float>					configValues;
	
	vector<ofImage*>				images;
	vector<ofxQTKitVideoPlayer*>	videos;
	dgSceneObject			*		activitySwitchObject;
	
	bool							active;
	
};