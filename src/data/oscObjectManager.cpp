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
	
}
void oscObjectManager::draw() {
	
}

void oscObjectManager::addObject(string adress, bool isStateAdress) {
	
	if ( adress =="" ) return;
	
	oscObject * obj = getObjectsByAdress(adress);
	
	if ( obj ) {
		
	} else {
		
		oscObject * newObject = new oscObject();
		newObject->oscAdress = adress;
		newObject->isStateAdress = isStateAdress;
		objects.push_back(newObject);
	}
	
}
oscObject * oscObjectManager::getObjectsByAdress(string adress) {
	
	for ( int i = 0; i< objects.size(); i++ ) {
		if ( objects[i]->oscAdress == adress ) return objects[i];
	}
	return NULL;
}

void oscObjectManager::getRelatedObjects (string val, vector<oscObject*> * oscObjects) {
	
	for ( int i = 0; i< objects.size(); i++ ) {
		if ( objects[i]->oscAdress == val ) oscObjects->push_back(objects[i]);
	}

}