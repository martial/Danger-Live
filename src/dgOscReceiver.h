/*
 *  dgOscReceiver.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __AHDGOSCREVEIVERA
#define __AHDGOSCRECEIVERA

#include "ofMain.h"
#include "ofxOsc.h"

#define OSC_PORT 9001
#define NUM_MSG_STRINGS 24

class DgOscReceiver {
	

	public:
	
	void setup ();
	void update();
	void debugDraw();
	
	private:
	ofxOscReceiver	receiver;
	
	int				current_msg_string;
	string			msg_strings[NUM_MSG_STRINGS];
	float			timers[NUM_MSG_STRINGS];
	
	
};

#endif
