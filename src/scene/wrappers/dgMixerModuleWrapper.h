/*
 *  dgMixerModuleWrapper.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 02/03/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */




#ifndef _DG_MIXER_MODULEWRAPPER
#define _DG_MIXER_MODULEWRAPPER

#include "ofMain.h"
#include "dgAbstractModuleWrapper.h"
#include "moduleData.h"

class dgMixerModuleWrapper : public dgAbstractModuleWrapper {
	
	
public:
	
	void setup(moduleData * relatedModule, dgVideoModule * videoModule, string name);
	void update();
	void draw();
	
	void onMidiEvent(int adress, int val);
	
	void onLaunchAction();
	void onReleaseAction();
	
	
	
private:
	
	ofImage screen;
	
	
};

#endif