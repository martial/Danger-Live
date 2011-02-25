/*
 *  oscObject.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 25/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _OSC_OBJ
#define _OSC_OBJ

#include "ofMain.h"


class oscObject {
		
	public:
	
	string oscAdress;
	//string oscAdressSwitch;
	float  pct;
	bool   isStateAdress;
	
	
	void setPct(float val);
	
	ofEvent<float>	onPctChangeEvent;
	
	private:
	
};

#endif