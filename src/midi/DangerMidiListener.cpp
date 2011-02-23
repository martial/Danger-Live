/*
 *  MyMidiListener.cpp
 *  emptyExample
 *
 *  Created by Martial Geoffre Rouland on 14/04/2010.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "DangerMidiListener.h"

void DangerMidiListener::setup(DangerScene & scene, dgSceneEffects & sceneEffects) {
	
	this->scene = &scene;
	this->sceneEffects = &sceneEffects;
	oldVal = 0;
}

// Method that receives MIDI event messages.
void DangerMidiListener::newMidiMessage(ofxMidiEventArgs& eventArgs){
	
	
	cout << "byteOne = " << eventArgs.byteOne << endl;
	cout << "byteTwo[" << eventArgs.byteTwo << endl;
	
	Boolean isIncreasing = ( eventArgs.byteTwo < oldVal ) ? false : true;
	if (  eventArgs.byteTwo == 127 ) isIncreasing = true;
	if ( eventArgs.byteTwo == 0 ) isIncreasing = false;
	//cout << "val[" << val << endl;
	
	scene->onMidiEvent(eventArgs.byteOne, eventArgs.byteTwo);
	
	float val;
	
	switch ( eventArgs.byteOne ) {
			
		case 23:
			scene->changeMode(DGSCENEVIEWMODE_MODULE);
			break;
			
		
		// [0,0]
		case 44:
			scene->changeMode(DGSCENEVIEWMODE_MODULE);
			break;
		
		// [0,1]
		case 48:
			scene->changeMode(DGSCENEVIEWMODE_VIDEOS);
			break;
			
			
		case 20:
			val = (float)eventArgs.byteTwo * 2.0 / 127.0;
			sceneEffects->setContrast(val);
			break;
			
		case 21:
			val = (float) eventArgs.byteTwo * 2.0 / 127.0;;
			sceneEffects->setSaturation(val);
			break;
			
		case 22:
			val = (float)eventArgs.byteTwo * 2.0/ 127.0;;
			sceneEffects->setBrightness(val);
			break;
			
					
	}
	
	
	// Do the stuff you need to do with 
	// the ofxMidiEventArgs instance.
}