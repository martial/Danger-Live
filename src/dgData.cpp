/*
 *  dgData.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgData.h"

void dgData::setup (string xmlURL) {
	
	printf("set up data \n");
	
	
	if ( XML.loadFile(xmlURL) ) {
	} else {
			printf("error");
	}
	XML.pushTag("scene", 0);
	
	int numOfLayouts = XML.getNumTags("module");
	data.reserve(numOfLayouts);
	
	
	printf ("Number of laouts : %d\n", numOfLayouts);
	
	for (int i=0; i<numOfLayouts; i++ ) {
		
		// push layout data
		data.push_back(new moduleData());
		// set name
		data[i]->name = XML.getAttribute("module", "name", 0, i);
		
		
		// go through components
		
		XML.pushTag("module", i);
		
		int numOfComponents = XML.getNumTags("component");
		
		data[i]->cpData.reserve(numOfComponents);
		
		printf ("Number of components : %d\n", numOfComponents);
		
		for (int j=0; j<numOfComponents; j++ ) {
			
			data[i]->cpData.push_back(new componentData());
			
			XML.pushTag("component", j);
			data[i]->cpData[j]->name = XML.getValue("name", "");
			data[i]->cpData[j]->adress = XML.getValue("osc_adress", "");
			
			
			
			data[i]->cpData[j]->pos.x = XML.getAttribute("position", "x", 0, 0);
			data[i]->cpData[j]->pos.y = XML.getAttribute("position", "y", 0, 0);
			
			
			
			data[i]->cpData[j]->range.x = XML.getAttribute("range", "min", 0, 0);
			data[i]->cpData[j]->range.y = XML.getAttribute("range", "max", 127, 0);
			
			XML.popTag();
		}
		XML.popTag();
		
	}
	
	debug();
}


void dgData::debug () {
		
	int numOfLayouts = data.size();
	
	for ( int i=0; i<numOfLayouts; i++ ) {
		
		
		///printf(data[i]->name.c_str());
		
		// num of components
		
		//printf("ok");
		
		int numOfComponents = data[i]->cpData.size();
		
		for (int j=0; j < numOfComponents; j++) {
			
			//printf("ahou");
			
		}
		
	}
	
	
}

