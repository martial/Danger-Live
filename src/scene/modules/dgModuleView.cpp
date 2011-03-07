/*
 *  dgModuleView.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgModuleView.h"

void dgModuleView::setup (dgData & layoutData, dgCompBuilder & compBuilder, OscReceiver & oscReceiver, dgSceneEffects & effects, dgVideoModule & videoModule) {
	
	this->layoutData = &layoutData;
	this->compBuilder = &compBuilder;
	this->oscReceiver = &oscReceiver;
	this->effects = &effects;
	this->videoModule = &videoModule;
	
	currentModule = NULL;
	
	initModulesWrappers();
	setCurrentView(0);
	
	beatLatency = 100;
	currentTime = 0;
	
	globalOpacity = 255;
	
}

void dgModuleView::clean () {
	
	currentModule = NULL;
	currentWrapper = NULL;
	
}

void dgModuleView::initModulesWrappers () {

	// intro 
	
	/*
	dgModuleIntroWrapper * introWrapper = new dgModuleIntroWrapper();
	introWrapper->setup(layoutData->getModuleByName("intro"), videoModule,  "intro");
	modulesWrappers.push_back(introWrapper);
	
	
	dgStyleSwitchIntroWrapper * switchWrapper = new dgStyleSwitchIntroWrapper();
	switchWrapper->setup(layoutData->getModuleByName("styleswitch"), videoModule, "styleswitch");
	modulesWrappers.push_back(switchWrapper);
	
	 
	 */
	 
	dgMixerModuleWrapper * mixerWrapper = new  dgMixerModuleWrapper();
	mixerWrapper->setup(layoutData->getModuleByName("mixer"), videoModule, "mixer");
	modulesWrappers.push_back(mixerWrapper);
	
	
	dgLoopModuleWrapper * loop = new dgLoopModuleWrapper();
	loop->setCompBuilder(compBuilder);
	loop->setup(layoutData->getModuleByName("loop"), videoModule, "loop");
	loop->init();
	modulesWrappers.push_back(loop);
	 
	 
	
}

void dgModuleView::update() {
	
	//if (!currentModule) return;
	
	if ( currentWrapper ) currentWrapper->update();
	
	int total = currentModule->cpObjects.size();
	for ( int i = 0; i<total; i++ ) {
		dgSceneObject  * object = currentModule->cpObjects[i];
		object->update();
	}
	 

}

void dgModuleView::draw () {
	
	//if (!currentModule) return;;
	
	ofEnableAlphaBlending();
	layerImg.draw(-layerImg.width*.5, 0);
	ofDisableAlphaBlending();
	
	int total = currentModule->cpObjects.size();
	for ( int i = 0; i< currentModule->cpObjects.size(); i++ ) {
		dgSceneObject  * object = currentModule->cpObjects[i];
		object->draw();
	}
	
	
	if ( currentWrapper ) currentWrapper->draw();
	
	
	/*
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
	
	
#ifdef EDITOR_MODE
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255, 130);
	layerImg.draw(-layerImg.width*.5, 0);
	ofSetColor(255, 255, 255, 255);
	ofDisableAlphaBlending();
#endif
	 
	 */

}


/*
 
 */

void dgModuleView::processOsc (customOscMessage & msg) {
	
		
}

void dgModuleView::getRelatedObject (string val, vector<dgSceneObject*> * pctObjects, vector<dgSceneObject*> * statePctObjects) {
		
	
	int total = currentModule->cpObjects.size();
	for ( int i = 0; i< total; i++ ) {
		if ( currentModule->cpObjects[i]->adress == val  ) {
			pctObjects->push_back(currentModule->cpObjects[i]);
		}
		if ( currentModule->cpObjects[i]->adressState == val  ) {
			statePctObjects->push_back(currentModule->cpObjects[i]);
		}
	}
	
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
	//processOsc(msg);
	if ( currentWrapper ) currentWrapper->onOscEvent(msg);
}

void dgModuleView::onBeatEvent() {
	
	
	currentTime = ofGetElapsedTimeMillis();	
	if ( currentWrapper ) currentWrapper->onBeatEvent();
	
}

void dgModuleView::onMidiEvent(int adress, int val) {
	//moduleView.onMidiEvent(adress, val);
	
	if ( currentWrapper ) currentWrapper->onMidiEvent(adress, val);
	
	
	
}

void dgModuleView::nextView () {
		
	int curViewID = currentViewID;
	curViewID++;
	
	if ( curViewID < 0 || curViewID > layoutData->data.size()-1 ) curViewID = 0;
	setCurrentView(curViewID);
	
	
}



void dgModuleView::setCurrentView(int viewID) {
	
	// check if current id is valid
	if (  viewID > layoutData->data.size()-1 ) return;
	currentViewID = viewID;
	
	currentModule = layoutData->data[currentViewID];
	
	
	currentWrapper = NULL;
	currentWrapper = getRelatedWrapper(layoutData->data[currentViewID]->name);
	
	for ( int i = 0; i< currentModule->cpObjects.size(); i++ ) {
		currentModule->cpObjects[i]->initValues();
	}
	 
	 
	
	
	if ( currentModule->layout != "" ) {
		layerImg.loadImage(currentModule->layout);
		
	} else {
		layerImg.clear();
	}
	
	
	/*
	// get beat object
	beatObject = NULL;
	for ( int i = 0; i< currentModule->cpObjects.size(); i++ ) {
		if ( currentModule->cpObjects[i]->nameId == "beatObject" ) {
			beatObject = currentModule->cpObjects[i];
		}
	}
	 
	
	
	
	
	#ifdef EDITOR_MODE

	if ( currentModule->layer != "" ) {
		layerImg.loadImage(currentModule->layer);
		printf("go!\n");
		printf(currentModule->layer.c_str());
		printf("\n");
	} else {
		layerImg.clear();
	}
	#endif
	 */
	//addSceneObjects();
	
}