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
#include "ofxTimer.h"


class oscObject {
		
	public:
	
	oscObject();
	
	void setMultiplierReferent(oscObject * referent);
	
	oscObject	* multiplierReferent;
	
	string oscAdress;
	string oscMultiplier;
	//string oscAdressSwitch;
	float  pct;
	bool   isStateAdress;
	
	
	void setPct(float val);
	void setPct(float val, float duration);
	void onTimerComplete(ofEventArgs & ahou);
	
	ofEvent<float>	onPctChangeEvent;
	
	ofxTimer		timer;
	
	
	private:
	
};

#endif