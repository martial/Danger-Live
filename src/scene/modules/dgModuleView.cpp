/*
 *  dgModuleView.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgModuleView.h"

void dgModuleView::setup (dgData & layoutData, dgCompBuilder & compBuilder, OscReceiver & oscReceiver, dgSceneEffects & effects) {
	
	this->layoutData = &layoutData;
	this->compBuilder = &compBuilder;
	this->oscReceiver = &oscReceiver;
	this->effects = &effects;
	
	currentModule = NULL;
	
	initModulesWrappers();
	setCurrentView(1);
	
	beatLatency = 100;
	currentTime = 0;
	
	globalOpacity = 255;
	
}

void dgModuleView::initModulesWrappers () {

	// intro 
	dgModuleIntroWrapper * introWrapper = new dgModuleIntroWrapper();
	introWrapper->setup(layoutData->getModuleByName("intro"), "intro");
	modulesWrappers.push_back(introWrapper);
	
	dgStyleSwitchIntroWrapper * switchWrapper = new dgStyleSwitchIntroWrapper();
	switchWrapper->setup(layoutData->getModuleByName("styleswitch"), "styleswitch");
	modulesWrappers.push_back(switchWrapper);
	
	
}

void dgModuleView::update() {
	
	if (!currentModule) return;
	
	//printf ("Number of comps : %d\n", currentObjects.size());
	
	// check for related module
	
	
	if ( currentWrapper ) currentWrapper->update();
	
	
	for ( int i = 0; i<currentModule->cpObjects.size(); i++ ) {
		dgSceneObject  * object = currentModule->cpObjects[i];
		if ( object ) object->update();
	}
	 

}

void dgModuleView::draw () {
	
	if (!currentModule) return;;
	
	for ( int i = 0; i< currentModule->cpObjects.size(); i++ ) {
		dgSceneObject  * object = currentModule->cpObjects[i];
		if ( object )object->draw();
	}
	
	
	if ( currentWrapper ) currentWrapper->draw();
	
	if ( beatObject ) {
		
		float time = ofGetElapsedTimeMillis() - currentTime;
		if ( time < beatLatency ) {
			beatObject->setPct(1.0);
		} else {
			beatObject->setPct(0.0);
		}
	} else {
			//printf("error");
	}
	 

}


/*
 
 */

void dgModuleView::processOsc (customOscMessage & msg) {
	
		
}

void dgModuleView::getRelatedObject (string val, vector<dgSceneObject*> * pctObjects, vector<dgSceneObject*> * statePctObjects) {
		
	
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
	if ( currentWrapper ) currentWrapper->onOscEvent(msg);
}

void dgModuleView::onBeatEvent() {
	
	
	currentTime = ofGetElapsedTimeMillis();	
	
	
}

void dgModuleView::onMidiEvent(int adress, int val) {
	//moduleView.onMidiEvent(adress, val);
	
	if ( currentWrapper ) currentWrapper->onMidiEvent(adress, val);
	if ( adress == 15 ) nextView();
	
	
}

void dgModuleView::nextView () {
	
	printf("next view \n");
	
	int curViewID = currentViewID;
	curViewID++;
	
	if ( curViewID < 0 || curViewID > layoutData->data.size()-1 ) curViewID = 0;
	
	
	printf("curViewID: %d \n", curViewID);
	setCurrentView(curViewID);
	
	//currentViewID = viewID;
	
	
}



void dgModuleView::setCurrentView(int viewID) {
	
	// check if current id is valid
	if (  viewID > layoutData->data.size()-1 ) return;
	currentViewID = viewID;
	
	currentModule = layoutData->data[currentViewID];
	currentWrapper = getRelatedWrapper(layoutData->data[currentViewID]->name);
	
	for ( int i = 0; i< currentModule->cpObjects.size(); i++ ) {
		currentModule->cpObjects[i]->initValues();
	}
	
	// get beat object
	beatObject = NULL;
	for ( int i = 0; i< currentModule->cpObjects.size(); i++ ) {
		if ( currentModule->cpObjects[i]->nameId == "beatObject" ) {
			beatObject = currentModule->cpObjects[i];
		}
	}
	
	
	//addSceneObjects();
	
}