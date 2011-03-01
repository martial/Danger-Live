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
#include "imgAssetsManager.h"
#include "oscObject.h"

class dgSceneObject {

	public:
	
	dgSceneObject();
	virtual ~dgSceneObject();
	virtual void					setup(string name, string type);
	virtual void					setPctObjectsReference(oscObject * pctRef, oscObject * pctStateRef);
	virtual void					init();
	virtual void					initValues();
	virtual void					update();
	virtual void					draw();
	
			void					addMedia(string url, string mediaType);
			void					addConfig(float val);
	virtual void					addSwitchObject(dgSceneObject * switchObj);
	virtual void					addActivitySwitchObject(dgSceneObject * actSwitchObject);
	virtual void					setPosition(ofPoint);
	virtual void					setPosition (int x, int y);
	
	virtual void					setPct(float pct);
	virtual void					setStatePct(float pct);
	virtual void					onPctChangeHandler(float & pct);
	virtual void					onPctStateChangeHandler(float & pct);
	
	
	string							name;
	string							nameId;
	string							adress;
	string							adressState;
	string							adressMultiplier;
	
	
	string							type;
	string							sceneObjectRefName;
	string							activityObjectRefName;
	ofPoint							pos;
	ofPoint							activitySwitchObjPos;
	
	
	
	float							rotation;
	float							blurRate;
	
	int								width, height;
	float							pct, statePct, easePct, oldPct;
	vector<float>					configValues;
	
	vector<ofImage*>				images;
	vector<ofxQTKitVideoPlayer*>	videos;
	dgSceneObject			*		activitySwitchObject;
	
	bool							active;
	
	imgAssetsManager		*		imgAssets;
	oscObject				*		pctRef;
	oscObject				*		pctStateRef;
	
};