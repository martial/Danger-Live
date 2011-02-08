/*
 *  dgModuleView.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgModuleView.h"

void dgModuleView::setup (dgData & layoutData, dgCompBuilder & compBuilder) {
	
	this->layoutData = &layoutData;
	this->compBuilder = &compBuilder;
	setCurrentView(0);
}

void dgModuleView::update() {
	
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
	
	// clean vector
	
	//while(!currentObjects.empty()) delete currentObjects.front(), currentObjects.pop_front();
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
		currentObjects.push_back(sceneObject); 
		
		
			
	}
	
	
}




/*

*/


void dgModuleView::setCurrentView(int viewID) {
	
	// check if current id is valid
	if ( viewID < 0 || viewID > layoutData->data.size()-1 ) return;
	
	currentViewID = viewID;
	addSceneObjects();
	
}