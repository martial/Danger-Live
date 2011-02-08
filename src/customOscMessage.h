/*
 *  customOscMessage.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 08/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef CUSTOMOSCMESSAGE
#define CUSTOMOSCMESSAGE

#include "ofMain.h"

class customOscMessage {

	
	public : 
	customOscMessage();
	~customOscMessage();
	string address;
	float value;
	vector<string>		stringArgs;
	
	
};

#endif