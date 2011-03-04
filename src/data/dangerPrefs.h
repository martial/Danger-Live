/*
 *  dangerPrefs.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 01/03/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _DG_PREFS
#define _DG_PREFS

#include "ofMain.h"
#include "ofxXmlSettings.h"



class dangerPrefs {

	public :
	//dangerPrefs();
	void setup();
	
	float getContrast();
	float getBrightness();
	float getSaturation();
	
	
	void saveContrast(float val);
	void saveBrightness(float val);
	void saveSaturation(float val);
	
	void saveColorSettings(float contrastPct, float brightnessPct, float saturationPct);
	
	
	
	
	private :
	
	ofxXmlSettings		XML;
	
	
};

#endif
