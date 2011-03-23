/*
 *  OscReveiver.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 08/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef __OSC_DG_RECEIVER
#define __OSC_DG_RECEIVER

#include "ofMain.h";
#include "ofxOscReceiver.h"
#include "customOscMessage.h"
//#include "ofEvents.h"
#include "ofEvents.h"

#define OSC_PORT 9001
#define NUM_MSG_STRINGS 24

class OscReceiver {
	
public:
	
	void setup ();
	void update();
	void debugDraw();
	
	vector<customOscMessage*> * getMessages();
	vector<customOscMessage> messages;
	
	ofEvent<int>	beatEvent;
	ofEvent<customOscMessage>	oscEvent;
	ofEvent<float>				masterSignalEvent;
	
	
	//ofEvent<float>	test;
	
private:
	ofxOscReceiver	receiver;
	
	int				current_msg_string;
	string			msg_strings[NUM_MSG_STRINGS];
	float			timers[NUM_MSG_STRINGS];
	
	float			currentTime;
	
	
	//ofEvent<customOscMessage> newFloatEvent;
	
};

#endif


