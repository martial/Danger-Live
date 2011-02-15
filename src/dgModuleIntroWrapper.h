/*
 *  dgModuleIntroWrapper.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _DG_MODULE_INTROWRAPPER
#define _DG_MODULE_INTROWRAPPER

#include "ofMain.h"
#include "dgAbstractModuleWrapper.h"
#include "moduleData.h"

class dgModuleIntroWrapper : public dgAbstractModuleWrapper {
	
	
	public:
	
	void setup(moduleData * relatedModule, string name);
	void update();
	void draw();
	
	void onMidiEvent(int adress, int val);
	
	void onLaunchAction();
	void onReleaseAction();
	

	
	private:
	
	ofSoundPlayer	loadingSound;
	ofSoundPlayer	releaseSound;
	float			currentTime;
};

#endif