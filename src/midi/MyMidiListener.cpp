/*
 *  MyMidiListener.cpp
 *  emptyExample
 *
 *  Created by Martial Geoffre Rouland on 14/04/2010.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "MyMidiListener.h"



// Constructor
MyMidiListener::MyMidiListener(){
}

// Destructor
MyMidiListener::~MyMidiListener(){
}

void MyMidiListener::setup(ofxQTKitVideoPlayer & vid, ofxQTKitVideoPlayer & vid2 ) {
	
	video = &vid;
	video2 = &vid2;

	
	oldVal = 0;
}

// Method that receives MIDI event messages.
void MyMidiListener::newMidiMessage(ofxMidiEventArgs& eventArgs){
	
	
	cout << "byteOne = " << eventArgs.byteOne << endl;
	cout << "byteTwo[" << eventArgs.byteTwo << endl;
	
	Boolean isIncreasing = ( eventArgs.byteTwo < oldVal ) ? false : true;
	if (  eventArgs.byteTwo == 127 ) isIncreasing = true;
	if ( eventArgs.byteTwo == 0 ) isIncreasing = false;
	//cout << "val[" << val << endl;
	
	int val;
	
	switch ( eventArgs.byteOne ) {
				
		case 13:
			val = 127- eventArgs.byteTwo;
			//playerManager->setGlobalSpeed(-127 + val*2);
			video->setPosition(eventArgs.byteTwo / (float)127);
			break;
			
		case 12:
			val = 127- eventArgs.byteTwo;
			//playerManager->setGlobalSpeed(-127 + val*2);
			video2->setPosition(eventArgs.byteTwo / (float)127);
			break;
			
					
	}
	
	
	// Do the stuff you need to do with 
	// the ofxMidiEventArgs instance.
}