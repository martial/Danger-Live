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
	setCurrentView(0);
	
	// set osc events
	
	//ofAddListener(this->oscReceiver->oscEvent,this,&dgModuleView::processOsc);
}

void dgModuleView::update() {
	
	processOsc();
	
	
	
	
	//printf ("Number of comps : %d\n", currentObjects.size());

	
	for ( int i = 0; i<currentObjects.size(); i++ ) {
		dgSceneObject  * object = currentObjects[i];
		object->update();
	}

}

void dgModuleView::draw () {
	
	for ( int i = 0; i<currentObjects.size(); i++ ) {
		dgSceneObject  * object = currentObjects[i];
		object->draw();
		
		
	}

}

void dgModuleView::addSceneObjects () {
	
	
	for ( int i = 0; i<currentObjects.size(); i++ ) {
		delete currentObjects[i];
	}
	currentObjects.clear();
	
	moduleData * currentModule = layoutData->data[currentViewID];
	int numOfComponents = currentModule->cpData.size();
	
	for ( int i = 0; i< numOfComponents; i++ ) {
		
		componentData * compData = currentModule->cpData[i];
		dgSceneObject  * sceneObject = compBuilder->createCompByName(compData->name);
		sceneObject->setPosition(compData->pos.x, compData->pos.y);
		sceneObject->adress = compData->adress;
		currentObjects.push_back(sceneObject); 
			
	}
	
}

/*
 
 */

void dgModuleView::processOsc () {
	
	for ( int i = 0; i < oscReceiver->messages.size(); i++ ) {
				
		// first check adress
		dgSceneObject * object;
		object = getRelatedObject(oscReceiver->messages[i]->address);
		if ( object ) {
			//object->active = true;
			continue;
		}
		
		for ( int j=0; j < oscReceiver->messages[i]->stringArgs.size(); j++ ) {			
				object =  getRelatedObject( oscReceiver->messages[i]->stringArgs[j]);
				if ( object ) {
					//object->active = true;
					object->setPct(oscReceiver->messages[i]->value / 127);
				}
				continue;
		}
		
		
	}
	
}

dgSceneObject  * dgModuleView::getRelatedObject (string val) {
	
	for ( int i = 0; i< currentObjects.size(); i++ ) {
		if ( currentObjects[i]->adress == val  ) {
			return currentObjects[i];
		}
	}
	
	return NULL;
}



/*

*/


void dgModuleView::setCurrentView(int viewID) {
	
	// check if current id is valid
	if ( viewID < 0 || viewID > layoutData->data.size()-1 ) return;
	
	currentViewID = viewID;
	addSceneObjects();
	
}