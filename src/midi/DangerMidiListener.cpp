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
	/*
	switch ( eventArgs.byteFour ) {
				
		case 2:
			scene->changeVideoSet(2);
			break;
			
	}
	 
	 */
	
	
	float val;
		
	scene->onMidiEvent(eventArgs.byteOne, eventArgs.byteTwo);
	
	switch ( eventArgs.byteOne ) {
			
		case 2:
			scene->setLogoAlpha((float)eventArgs.byteTwo / 127 );
			break;
			
		case 3:
			scene->setFlickrLogoIntensity((int)(eventArgs.byteTwo / 4));
			break;
			
		case 13:
			sceneEffects->masterSignalVariation = (float)((float)eventArgs.byteTwo / 127 * 2);
			break;
			
			
		case 23:
			if ( eventArgs.byteTwo != 127 ) break;
			//scene->setRandomVideo();
			break;
			
		case 33:
			if ( eventArgs.byteTwo != 127 ) break;
			//scene->changeVideoSet(1);
			break;
			
		case 31:
			if ( eventArgs.byteTwo != 127 ) break;
			scene->changeMode(DGSCENEVIEWMODE_VIDEOS);
			break;
			
		
		// [0,0]
		case 41:
			if ( eventArgs.byteTwo != 127 ) break;
			scene->changeMode(DGSCENEVIEWMODE_MODULE);
			scene->setCurrentView(1);
			break;
		
		// [0,1]
		case 30:
			if ( eventArgs.byteTwo != 127 ) break;
			scene->changeMode(DGSCENEVIEWMODE_MODULE);
			scene->setCurrentView(2);
			break;
			
		case 40:
			if ( eventArgs.byteTwo != 127 ) break; 
			scene->changeMode(DGSCENEVIEWMODE_MODULE);
			scene->setCurrentView(3);
			break;
			
		case 29:
			if ( eventArgs.byteTwo != 127 ) break;
			scene->changeMode(DGSCENEVIEWMODE_MODULE);
			scene->setCurrentView(4);
			break;
			
		case 39:
			if ( eventArgs.byteTwo != 127 ) break;
			scene->changeMode(DGSCENEVIEWMODE_MODULE);
			scene->setCurrentView(5);
			break;
			
		case 28:
			if ( eventArgs.byteTwo != 127 ) break;
			scene->changeMode(DGSCENEVIEWMODE_MODULE);
			scene->setCurrentView(6);
			break;
			
		case 38:
			if ( eventArgs.byteTwo != 127 ) break; 
			scene->changeMode(DGSCENEVIEWMODE_MODULE);
			scene->setCurrentView(7);
			break;
			
		case 27:
			if ( eventArgs.byteTwo != 127 ) break;
			scene->changeMode(DGSCENEVIEWMODE_MODULE);
			scene->setCurrentView(8);
			break;
			
		case 37:
			if ( eventArgs.byteTwo != 127 ) break;
			scene->changeMode(DGSCENEVIEWMODE_MODULE);
			scene->setCurrentView(9);
			break;
			
			
			/* */
		case 24:
			if ( eventArgs.byteTwo != 127 ) break;
			scene->changeMode(DGSCENEVIEWMODE_MODULE);
			scene->setCurrentView(0);
			break;
			
		case 34:
			if ( eventArgs.byteTwo != 127 ) break;
			scene->changeMode(DGSCENEVIEWMODE_MODULE);
			scene->setCurrentView(10);
			break;
			
			
		case 15:
			val = (float)eventArgs.byteTwo * 2.0 / 127.0;
			sceneEffects->setContrast(val);
			break;
			
		case 16:
			val = (float) eventArgs.byteTwo * 2.0 / 127.0;;
			sceneEffects->setSaturation(val);
			break;
			
		case 14:
			val = (float)eventArgs.byteTwo * 2.0/ 127.0;;
			sceneEffects->setBrightness(val);
			break;
			
					
	}
	
	
	// Do the stuff you need to do with 
	// the ofxMidiEventArgs instance.
}