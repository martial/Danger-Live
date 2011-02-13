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
	
	//addSceneObjects();
	
	// set osc events
	
	//ofAddListener(this->oscReceiver->oscEvent,this,&dgModuleView::processOsc);
}

void dgModuleView::update() {
	
	
	
	
	
	
	//printf ("Number of comps : %d\n", currentObjects.size());
	moduleData * currentModule = layoutData->data[currentViewID];
	
	for ( int i = 0; i<currentModule->cpObjects.size(); i++ ) {
		dgSceneObject  * object = currentModule->cpObjects[i];
		object->update();
	}
	 

}

void dgModuleView::draw () {
	
	printf("draw module\n");
	moduleData * currentModule = layoutData->data[currentViewID];
	
	for ( int i = 0; i< currentModule->cpObjects.size(); i++ ) {
		dgSceneObject  * object = currentModule->cpObjects[i];
		object->draw();
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
			object->setPct(oscReceiver->messages[i]->value / 5);
			//object->active = true;
			//continue;
		}
		
		for ( int j=0; j < oscReceiver->messages[i]->stringArgs.size(); j++ ) {			
				object =  getRelatedObject( oscReceiver->messages[i]->stringArgs[j]);
				if ( object ) {
					//object->active = true;
					//printf("ptinnn");
					object->setPct(oscReceiver->messages[i]->value / 127);
				}
				//continue;
		}
		
		
	}
	
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



/*

*/

void dgModuleView::onOscEvent() {
	processOsc();
}

void dgModuleView::setCurrentView(int viewID) {
	
	// check if current id is valid
	if ( viewID < 0 || viewID > layoutData->data.size()-1 ) return;
	
	currentViewID = viewID;
	//addSceneObjects();
	
}