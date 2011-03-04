/*
 *  dgAbstractModuleWrapper.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _DG_MODULE_ABSTRWRAPPER
#define _DG_MODULE_ABSTRWRAPPER

#include "ofMain.h"
#include "moduleData.h"
#include "customOscMessage.h"
#include "dgVideoModule.h"

class dgAbstractModuleWrapper {
	
	
public:
	
	virtual void setup(moduleData * relatedModule, dgVideoModule * videoModule, string name);
	virtual void update();
	virtual void draw();
	
	virtual void onMidiEvent(int adress, int val);
	virtual void onOscEvent(customOscMessage & m );
	
	string name;
	moduleData	*	relatedModule;	
	dgVideoModule *	videoModule;
	
	
private:
	
	
	
};

#endif