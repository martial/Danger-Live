/*
 *  dgData.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgData.h"

void dgData::setup () {
	
	//printf("set up data \n");
	
	DIR.setVerbose(false);
    int numOfLayouts = DIR.listDir("layouts");

	
	
		
	
	//int numOfLayouts = XML.getNumTags("module");
	//data.reserve(numOfLayouts);
	
	
	printf ("Number of laouts : %d\n", numOfLayouts);
	
	for (int i=0; i<numOfLayouts; i++ ) {
		
		
		if ( XML.loadFile(DIR.getPath(i)) ) {
		} else {
			printf("error loading XML file");
		}
		
		
		
		XML.pushTag("scene", 0);
		
		// push layout data
		data.push_back(new moduleData());
		// set name
		data[i]->name = XML.getAttribute("module", "name", 0, i);
		
		
		// go through components
		
		XML.pushTag("module", i);
		
		int numOfComponents = XML.getNumTags("component");
		
		data[i]->cpData.reserve(numOfComponents);
		
		//printf ("Number of components : %d\n", numOfComponents);
		
		for (int j=0; j<numOfComponents; j++ ) {
			
			data[i]->cpData.push_back(new componentData());
			
			XML.pushTag("component", j);
			data[i]->cpData[j]->name = XML.getValue("name", "");
			data[i]->cpData[j]->adress = XML.getValue("osc_adress", "");
			
			
			
			data[i]->cpData[j]->pos.x = XML.getAttribute("position", "x", 0, 0);
			data[i]->cpData[j]->pos.y = XML.getAttribute("position", "y", 0, 0);
			
			
			data[i]->cpData[j]->range.x = XML.getAttribute("range", "min", 0, 0);
			data[i]->cpData[j]->range.y = XML.getAttribute("range", "max", 127, 0);
			
			
			if (XML.tagExists("rotation", 0)) {
				data[i]->cpData[j]->rotation = XML.getValue("rotation", 0);	
			} else {
				data[i]->cpData[j]->rotation = 0.0f;
			}

			

			
			
			XML.popTag();
		}
		XML.popTag();
		
	}
	
	debug();
}



void dgData::addSceneObjects (dgCompBuilder & compBuilder) {
	
	printf("\nSTARTING COMPONENT BUILD----------------------------------\n");
	
	
	for ( int u=0; u< data.size(); u++ ) {
		
		moduleData * currentModule = data[u];
		int numOfComponents = currentModule->cpData.size();
		
		for ( int i = 0; i< numOfComponents; i++ ) {
			
			componentData * compData = currentModule->cpData[i];
			dgSceneObject  * sceneObject = compBuilder.createCompByName(compData->name);
			
			if (sceneObject) {
				
				/*
			printf("\ncomponent built : ");
			printf(sceneObject->name.c_str());
			printf("\n");
			*/
				
				
			sceneObject->setPosition(compData->pos.x, compData->pos.y);
			sceneObject->rotation = compData->rotation;
			sceneObject->adress = compData->adress;
			currentModule->cpObjects.push_back(sceneObject);
			}
						
		}
		

		printf("\n------------------------------------------------- BUILD 2 fase\n");
		for ( int j = 0; j< currentModule->cpObjects.size(); j++ ) {
			
			
			
			dgSceneObject  * sceneObject =  currentModule->cpObjects[j];
			
			/*
			printf("\ndouble check object : ");
			printf(sceneObject->name.c_str());
			printf(" | ");
			printf(sceneObject->type.c_str());
			printf("\n");
			 */
			
			if ( sceneObject->activityObjectRefName != "") {
				dgSceneObject  * refSceneObject = compBuilder.createCompByName(sceneObject->activityObjectRefName);
				if(refSceneObject) {
				refSceneObject->pos = sceneObject->activitySwitchObjPos;
				sceneObject->addActivitySwitchObject(refSceneObject);
				}
				//printf("add activity object : " );
			}
			
			
			if ( sceneObject->type == "meter") {
				int numOfRows = (int)sceneObject->configValues[1];
				
				//printf("\nmeter object ");
				//printf(sceneObject->name.c_str());
				//printf("\n");
				
				for (int k=0; k<numOfRows; k++ ) {
				dgSceneObject  * refSceneObject = compBuilder.createCompByName(sceneObject->sceneObjectRefName);
				if ( refSceneObject) {
					sceneObject->addSwitchObject(refSceneObject);
					sceneObject->init();
					}
				}
			}
			
			
		}
		 
		 
		
	}	
	
}


void dgData::clean() {

	for ( int u=0; u< data.size(); u++ ) {
		data[u]->clean();
		delete data[u];
		//data = NULL;
	}
	data.clear();
	
}


void dgData::debug () {
		
	int numOfLayouts = data.size();
	
	for ( int i=0; i<numOfLayouts; i++ ) {
		
		int numOfComponents = data[i]->cpData.size();
		
		for (int j=0; j < numOfComponents; j++) {
			
			//printf("ahou");
			
		}
		
	}
	
	
}

