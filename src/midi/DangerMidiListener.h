/*
 *  MyMidiListener.h
 *  emptyExample
 *
 *  Created by Martial Geoffre Rouland on 14/04/2010.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include "ofMain.h"
#include "ofxMidi.h"
#include "DangerScene.h"
#include "dgSceneEffects.h"

class DangerMidiListener : public ofxMidiListener {
	
public:

	void setup(DangerScene & scene, dgSceneEffects & sceneEffects);
	void newMidiMessage(ofxMidiEventArgs& eventArgs);
	
	
	
	
	int									oldVal;
	DangerScene				*			scene;
	dgSceneEffects			*			sceneEffects;
};