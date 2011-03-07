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
	
	//DIR.setVerbose(false);
    int numOfLayouts = DIR.listDir("layouts");
	
	for (int i=0; i<numOfLayouts; i++ ) {
		
		
		if ( XML.loadFile(DIR.getPath(i)) ) {
		} else {
			printf("error loading XML file");
		}
		
		
		
		XML.pushTag("scene", 0);
		
		// push layout data
		data.push_back(new moduleData());
		// set name
		
		
		
		// go through components
		
		data[i]->name = XML.getAttribute("module", "name", "", 0);
		data[i]->layer = XML.getAttribute("module", "layer", "", 0);
		data[i]->layout = XML.getAttribute("module", "layout", "", 0);
	
		XML.pushTag("module", 0);
		
		//data[i]->name = XML.getAttribute("module", "name", "", 0);
		
				
		int numOfComponents = XML.getNumTags("component");
		
		data[i]->cpData.reserve(numOfComponents);
		
		//printf ("Number of components : %d\n", numOfComponents);
		
		for (int j=0; j<numOfComponents; j++ ) {
			
			data[i]->cpData.push_back(new componentData());
			
			XML.pushTag("component", j);
			data[i]->cpData[j]->name = XML.getValue("name", "");
			data[i]->cpData[j]->nameId = XML.getValue("nameID", "");
			data[i]->cpData[j]->adress = XML.getValue("osc_adress", "");
			
			data[i]->cpData[j]->adressMultiplier = XML.getAttribute("osc_adress", "multiplier", "", 0);
			
			data[i]->cpData[j]->adressState = XML.getValue("osc_adress_state", "");
			
			data[i]->cpData[j]->reversePct =  (XML.getValue("reversePct", "") == "true" ) ? true : false;
			
			
			
			
			data[i]->cpData[j]->pos.x = XML.getAttribute("position", "x", 0, 0);
			data[i]->cpData[j]->pos.y = XML.getAttribute("position", "y", 0, 0);
			
			
			data[i]->cpData[j]->range.x = XML.getAttribute("range", "min", 0, 0);
			data[i]->cpData[j]->range.y = XML.getAttribute("range", "max", 1, 0);
						
			if (XML.tagExists("rotation", 0)) {
				data[i]->cpData[j]->rotation = XML.getValue("rotation", 0);	
			} else {
				data[i]->cpData[j]->rotation = 0.0f;
			}

			
			/* osc object manager */
			
			oscObjManager.addObject(data[i]->cpData[j]->adress, false, data[i]->cpData[j]->adressMultiplier);
			oscObjManager.addObject(data[i]->cpData[j]->adressState, true);
			
			
			XML.popTag();
		}
		XML.popTag();
		
	}
	
	debug();
}

void dgData::update() {
	oscObjManager.update();
}



void dgData::addSceneObjects (dgCompBuilder & compBuilder) {
	
	//printf("\nSTARTING COMPONENT BUILD----------------------------------\n");
	
	
	for ( int u=0; u< data.size(); u++ ) {
		
		moduleData * currentModule = data[u];
		int numOfComponents = currentModule->cpData.size();
		
		for ( int i = 0; i< numOfComponents; i++ ) {
			
			componentData * compData = currentModule->cpData[i];
			dgSceneObject  * sceneObject = compBuilder.createCompByName(compData->name);
			
			if (sceneObject) {
						
			sceneObject->setPosition(compData->pos.x, compData->pos.y);
			sceneObject->rotation = compData->rotation;
			sceneObject->adress = compData->adress;
			sceneObject->adressState = compData->adressState;
			sceneObject->adressMultiplier = compData->adressMultiplier;
			sceneObject->nameId = compData->nameId;
			sceneObject->reversePct = compData->reversePct;
			sceneObject->range = compData->range;
			currentModule->cpObjects.push_back(sceneObject);
			}
			
									
		}
		

		//printf("\n------------------------------------------------- BUILD 2 fase\n");
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
				refSceneObject->blurRate = .7;
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
					}
				}
				
			}
				
			
			// finally add the reference object
			sceneObject->setPctObjectsReference(oscObjManager.getObjectsByAdress(sceneObject->adress, sceneObject->adressMultiplier), oscObjManager.getObjectsByAdress(sceneObject->adressState, ""));
			sceneObject->init();
		}
		
			
		/*
		dgSceneObject  * beatObject = compBuilder.createCompByName("LED_A");
		if ( beatObject != NULL) {
			beatObject->setPosition(0, 120);
			beatObject->nameId = "beatObject";
			beatObject->blurRate = 0.0;
			currentModule->cpObjects.push_back(beatObject);
		}
		 
		 */
		
		
	}	
	
	// link referents
	oscObjManager.addReferents();
	
}

moduleData * dgData::getModuleByName(string nameTarget) {
	
	int numOfLayouts = data.size();
	for ( int i=0; i<numOfLayouts; i++ ) {
		
		if ( data[i]->name == nameTarget ) return data[i];
	}
	return NULL;
}


void dgData::onOscEvent (customOscMessage & msg ) {
	
	vector<oscObject*>  objects;
	oscObjManager.getRelatedObjects(msg.address, &objects);
	int total = objects.size();
	
	
	
	
	for ( int i=0; i<total; i++) {
		
		if (msg.address == "/live/master/crossfader" ) {
			msg.value += 1.0;
		}
		
		objects[i]->setPct(msg.value / getPctByAdress(msg.address));
	}
	
	objects.clear();
	
	for ( int j=0; j < msg.stringArgs.size(); j++ ) {	
		oscObjManager.getRelatedObjects(msg.stringArgs[j], &objects);
		
		total = objects.size();
		for ( int k=0; k<total; k++) {
			
			
			if (msg.stringArgs[j] == "/live/master/crossfader" ) {
				msg.value += 1.0;
			}
			objects[k]->setPct(msg.value / getPctByAdress(msg.stringArgs[j]));
		}
		
	}
	
	objects.clear();
	
	// update referents 
	
	
	
	
	
	
}

float dgData::getPctByAdress(string address) {
	
	float div = 127.0;
	
	string splitString = address.substr(0, 7);
	
	
	if ( splitString == "/signal" ) return 1.2;
	
	splitString = address.substr(0, 19);
	if (splitString == "/live/track/volume/" ) {
		return .85;
	}
	
	if (address == "/live/master/crossfader" ) return 2;
	if (address == "/live/master/volume" ) return .85;
	
	return 127.0;
	//return (splitString == "/live/track/volume/" ) ? 1.0 : 127.0;
	
}


void dgData::onBeatEvent () {
	oscObjManager.onBeatEvent();
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

