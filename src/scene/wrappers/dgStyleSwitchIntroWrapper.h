/*
 *  dgStyleSwitchIntroWrapper.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 18/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _DG_STYLESWITCH_WRAPPER
#define _DG_STYLESWITCH_WRAPPER

#include "ofMain.h"
#include "dgAbstractModuleWrapper.h"
#include "moduleData.h"

class dgStyleSwitchIntroWrapper : public dgAbstractModuleWrapper {
	
	
public:
	
	void setup(moduleData * relatedModule, string name);
	void update();
	void draw();
	
	void onMidiEvent(int adress, int val);
	void onOscEvent(customOscMessage & m );
	
	void onLaunchAction();
	void onReleaseAction();
	
	
	
private:
	
	};

#endif