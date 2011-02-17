/*
 *  dgModuleView.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgModuleView.h"

void dgModuleView::setup (dgData & layoutData, dgCompBuilder & compBuilder, OscReceiver & oscReceiver) {
	
	this->layoutData = &layoutData;
	this->compBuilder = &compBuilder;
	this->oscReceiver = &oscReceiver;
	
	initModulesWrappers();
	setCurrentView(0);
	
}

void dgModuleView::initModulesWrappers () {

	// intro 
	dgModuleIntroWrapper * introWrapper = new dgModuleIntroWrapper();
	introWrapper->setup(layoutData->getModuleByName("intro"), "intro");
	modulesWrappers.push_back(introWrapper);
	
	
}

void dgModuleView::update() {
	
	//printf ("Number of comps : %d\n", currentObjects.size());
	
	// check for related module
	
	
	if ( currentWrapper ) currentWrapper->update();
	
	moduleData * currentModule = layoutData->data[currentViewID];
	
	for ( int i = 0; i<currentModule->cpObjects.size(); i++ ) {
		dgSceneObject  * object = currentModule->cpObjects[i];
		if ( object ) object->update();
	}
	 

}

void dgModuleView::draw () {
	
	//printf("draw module\n");
	moduleData * currentModule = layoutData->data[currentViewID];
	
	for ( int i = 0; i< currentModule->cpObjects.size(); i++ ) {
		dgSceneObject  * object = currentModule->cpObjects[i];
		if ( object )object->draw();
	}
	
	
	if ( currentWrapper ) currentWrapper->draw();
	 

}


/*
 
 */

void dgModuleView::processOsc (customOscMessage & msg) {
	
	// TODO double loop and filter signals for values
	
		
	//for ( int i = 0; i < oscReceiver->messages.size(); i++ ) {
	
		//printf("process : \n");
				
		// first check adress
		vector<dgSceneObject*>  objects;
		vector<dgSceneObject*>  stateObjects;
	
		getRelatedObject(msg.address, &objects, &stateObjects);
		int total = objects.size();
		
		string splitString = msg.address.substr(0, 7);
		float div = (splitString == "/signal" ) ? 1 : 127.0;
	
	//printf(splitString.c_str());
	
		for ( int i=0; i<total; i++) {
			objects[i]->setPct(msg.value/div);
			
		}
		
		total = stateObjects.size();
		for ( int i=0; i<total; i++) {
			stateObjects[i]->setStatePct(msg.value/127);
		
		}
		
		
		
		for ( int j=0; j < msg.stringArgs.size(); j++ ) {	
			
			getRelatedObject( msg.stringArgs[j], &objects, &stateObjects);
			
			
			string splitString = msg.stringArgs[j].substr(0, 7);
			float div = (splitString == "/signal" ) ? 1 : 127.0;
			
			total = objects.size();
			for ( int k=0; k<total; k++) {
				objects[k]->setPct(msg.value/div);
			}
			
			total = stateObjects.size();
			for ( int k=0; k<total; k++) {
				stateObjects[k]->setStatePct(msg.value/127);
			}
				
		}
	
	//printf("objects size : %d\n", total);
		
	objects.clear();
	stateObjects.clear();
		
	//}
	
}

void dgModuleView::getRelatedObject (string val, vector<dgSceneObject*> * pctObjects, vector<dgSceneObject*> * statePctObjects) {
		
	moduleData * currentModule = layoutData->data[currentViewID];
	
	int total = currentModule->cpObjects.size();
	for ( int i = 0; i< total; i++ ) {
		
		//printf("adress: \n");
		//string adress = currentModule->cpObjects[i]->adress;
		//printf(adress.c_str());
		
		if ( currentModule->cpObjects[i]->adress == val  ) {
			pctObjects->push_back(currentModule->cpObjects[i]);
		}
		
		if ( currentModule->cpObjects[i]->adressState == val  ) {
			statePctObjects->push_back(currentModule->cpObjects[i]);
		}
	}
	//printf("objects size before : %d\n", relatedObjects.size());
	//return &relatedObjects;
}

dgAbstractModuleWrapper * dgModuleView::getRelatedWrapper (string name) {
	
	
	for ( int i=0; i<modulesWrappers.size(); i++) {
		if ( modulesWrappers[i]->name == name) return modulesWrappers[i];
	}
	return NULL;
}



/*

*/

void dgModuleView::onOscEvent(customOscMessage & msg) {
	processOsc(msg);
}

void dgModuleView::onMidiEvent(int adress, int val) {
	//moduleView.onMidiEvent(adress, val);
	
	if ( currentWrapper ) currentWrapper->onMidiEvent(adress, val);
	
	if ( adress == 15 ) nextView();
	
	
}

void dgModuleView::nextView () {
	
	int curViewID = currentViewID;
	curViewID++;
	if ( curViewID < 0 || curViewID > layoutData->data.size()-1 ) curViewID = 0;
	setCurrentView(curViewID);
	
	//currentViewID = viewID;
	
	
}

void dgModuleView::setCurrentView(int viewID) {
	
	// check if current id is valid
	if (  viewID > layoutData->data.size()-1 ) return;
	currentViewID = viewID;
	currentWrapper = getRelatedWrapper(layoutData->data[currentViewID]->name);
	//addSceneObjects();
	
}