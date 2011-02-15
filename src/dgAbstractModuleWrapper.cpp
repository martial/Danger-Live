/*
 *  dgAbstractModuleWrapper.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgAbstractModuleWrapper.h"

void dgAbstractModuleWrapper::setup(moduleData * relatedModule, string name) {
	
	this->name = name;
	this->relatedModule = relatedModule;
	
}

void dgAbstractModuleWrapper::update() {
	
}

void dgAbstractModuleWrapper::draw () {
	
}


/* */ 


void dgAbstractModuleWrapper::onMidiEvent(int adress, int val) {

}