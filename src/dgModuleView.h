/*
 *  dgModuleView.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef DGMODULEVIEW
#define DGMODULEVIEW

#include "ofMain.h"
#include "dgData.h"
#include "dgCompBuilder.h"
#include "OscReceiver.h"
#include "customOscMessage.h"
#include "dgAbstractModuleWrapper.h"
#include "dgModuleIntroWrapper.h"

class dgModuleView {
	
	public:
	void setup(dgData & layoutData, dgCompBuilder & compBuilder, OscReceiver & oscReceiver);
	void update();
	void draw();
	
	void initModulesWrappers();
		
	void setCurrentView(int viewID);
	
	void onOscEvent(customOscMessage & msg);
	void onMidiEvent(int adress, int val);
	
	private:
	
	void nextView();
	
	/* Communication OSC*/
	void processOsc (customOscMessage & msg);
	void  getRelatedObject(string val, vector<dgSceneObject*> * objects, vector<dgSceneObject*> * statePctObjects);

	/* Instances  */
	dgData					*	layoutData;
	dgCompBuilder			*	compBuilder;
	OscReceiver				*	oscReceiver;
	
	/* current stuff*/
	int							currentViewID;
	vector<dgSceneObject*>		currentObjects;
	
	/* wrappers for custom layout actions */
	dgAbstractModuleWrapper * getRelatedWrapper (string name);
	vector<dgAbstractModuleWrapper*>	modulesWrappers;
	dgAbstractModuleWrapper		*		currentWrapper;
	
	
};

#endif