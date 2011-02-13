/*
 *  moduleData.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "moduleData.h"


moduleData::moduleData() {
	
}

moduleData::~moduleData() {
	
}

void moduleData::setup() {

	
}

void moduleData::clean () {
	
	
	for ( int i=0; i<cpData.size(); i++ ) {
		delete cpData[i];
		//cpData[i] = NULL;		
	}
	cpData.clear();
	
	for ( int j=0; j<cpObjects.size(); j++ ) {
		delete cpObjects[j];
		cpObjects[j] = NULL;		
	}
	cpObjects.clear();
	
}

