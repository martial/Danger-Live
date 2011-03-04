/*
 *  dgStyleSwitchIntroWrapper.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 18/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgStyleSwitchIntroWrapper.h"


void dgStyleSwitchIntroWrapper::setup(moduleData * relatedModule, dgVideoModule * videoModule, string name) {
	
	dgAbstractModuleWrapper::setup(relatedModule, videoModule,name);
	
	}

void dgStyleSwitchIntroWrapper::update() {
	
	// update progress bar
	
	//dgSceneObject * bar = relatedModule->getComponentByNameID("launch_bar");
		
	
}

void dgStyleSwitchIntroWrapper::draw () {
	
	
}


void dgStyleSwitchIntroWrapper::onMidiEvent(int adress, int val) {
	


}

void dgStyleSwitchIntroWrapper::onOscEvent(customOscMessage & m ) {
	
	
	
	
	for (int i=0; i<relatedModule->cpObjects.size(); i++ ) {
		
		
		
		if ( m.address == relatedModule->cpObjects[i]->nameId ) {
			relatedModule->cpObjects[i]->setPct(1);
			//printf("ok");
		} else {
			relatedModule->cpObjects[i]->setPct(0);
			//printf("quit");
		}
		
	}
		
	
	
}
