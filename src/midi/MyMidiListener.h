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
#include "ofxQTKitVideoPlayer.h"

class MyMidiListener : public ofxMidiListener {
	
public:
	MyMidiListener();
	~MyMidiListener();
	void setup(ofxQTKitVideoPlayer & vid,  ofxQTKitVideoPlayer & vid2);
	void newMidiMessage(ofxMidiEventArgs& eventArgs);
	
	ofxQTKitVideoPlayer			*			video;
	ofxQTKitVideoPlayer			*			video2;
	
	
	int									oldVal;
	
};