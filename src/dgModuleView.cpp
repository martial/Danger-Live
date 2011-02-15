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
	

	
	//for ( int i = 0; i < oscReceiver->messages.size(); i++ ) {
				
		// first check adress
		dgSceneObject * object;
		object = getRelatedObject(msg.address);
		if ( object ) {
			object->setPct(msg.value);
			//object->active = true;
			//continue;
		}
		
		for ( int j=0; j < msg.stringArgs.size(); j++ ) {			
				object =  getRelatedObject( msg.stringArgs[j]);
				if ( object ) {
					//object->active = true;
					
					
					object->setPct(msg.value / 127);
				}
				//continue;
		}
		
		
	//}
	
}

dgSceneObject  * dgModuleView::getRelatedObject (string val) {
		
	moduleData * currentModule = layoutData->data[currentViewID];

	for ( int i = 0; i< currentModule->cpObjects.size(); i++ ) {
		
		/*
		printf("\ncheck module:: ");
		printf(currentModule->cpObjects[i]->adress.c_str());
		printf("\n");
		printf("\nval :: ");
		printf(val.c_str());
		printf("\n");
		
		*/
		if ( currentModule->cpObjects[i]->adress == val  ) {
			return currentModule->cpObjects[i];
		}
	}
	
	return NULL;
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