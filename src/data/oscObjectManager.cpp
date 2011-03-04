/*
 *  oscObjectManager.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 25/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "oscObjectManager.h"


void oscObjectManager::update(){
	updateMultiplierReferents();
}
void oscObjectManager::draw() {
	
}

void oscObjectManager::addObject(string adress, bool isStateAdress, string multiplier) {
	
	if ( adress =="" ) return;
	
	oscObject * obj = getObjectsByAdress(adress, multiplier);
	
	if ( obj ) {
		//printf("exist");
	} else {
		
		oscObject * newObject = new oscObject();
		newObject->oscAdress = adress;
		newObject->isStateAdress = isStateAdress;
		newObject->oscMultiplier = multiplier;
		objects.push_back(newObject);
	}
	
}

void oscObjectManager::addReferents () {

	for ( int i = 0; i< objects.size(); i++ ) {
		if ( objects[i]->oscMultiplier != "" ) {
			
			// check if exist
			oscObject * multiplierRef = getObjectsByAdress(objects[i]->oscMultiplier, "");
			if (!multiplierRef) {
				addObject(objects[i]->oscMultiplier, false, "");
				
			} else {
				
			}
			
			objects[i]->setMultiplierReferent(getObjectsByAdress(objects[i]->oscMultiplier, ""));
		}
	}
	
}

oscObject * oscObjectManager::getObjectsByAdress(string adress, string multiplier) {
	
	for ( int i = 0; i< objects.size(); i++ ) {
		if ( objects[i]->oscAdress == adress && objects[i]->oscMultiplier == multiplier ) return objects[i];
	}
	return NULL;
}

void oscObjectManager::getRelatedObjects (string val, vector<oscObject*> * oscObjects) {
	
	for ( int i = 0; i< objects.size(); i++ ) {
		if ( objects[i]->oscAdress == val ) oscObjects->push_back(objects[i]);
	}

}


void oscObjectManager::updateMultiplierReferents () {
	
	//for ( int i = 0; i< objects.size(); i++ ) {
		//if ( objects[i]->multiplierReferent  ) {
			//objects[i]->pct = objects[i]->multiplierReferent->pct;
		//}
	//}
	
}


void oscObjectManager::onBeatEvent () {
	
	for ( int i = 0; i< objects.size(); i++ ) {
		
		if ( objects[i]->oscAdress == "tempo" ) {
			
			objects[i]->setPct(1, 25);
			
			
		}
		
	}
	
}
 

