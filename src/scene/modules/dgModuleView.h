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
#include "dgStyleSwitchIntroWrapper.h"
#include "dgSceneEffects.h"

class dgModuleView {
	
	public:
	void setup(dgData & layoutData, dgCompBuilder & compBuilder, OscReceiver & oscReceiver, dgSceneEffects & effects);
	void update();
	void draw();
	
	void initModulesWrappers();
		
	void setCurrentView(int viewID);
	
	void onBeatEvent();
	void onOscEvent(customOscMessage & msg);
	void onMidiEvent(int adress, int val);
	
	int							currentViewID;
	
	void nextView();
	
	private:
	
	
	
	/* Communication OSC*/
	void processOsc (customOscMessage & msg);
	void  getRelatedObject(string val, vector<dgSceneObject*> * objects, vector<dgSceneObject*> * statePctObjects);

	/* Instances  */
	dgData					*	layoutData;
	dgCompBuilder			*	compBuilder;
	OscReceiver				*	oscReceiver;
	dgSceneEffects			*	effects;
	
	/* current stuff*/
	
	vector<dgSceneObject*>		currentObjects;
	
	/* wrappers for custom layout actions */
	dgAbstractModuleWrapper * getRelatedWrapper (string name);
	vector<dgAbstractModuleWrapper*>	modulesWrappers;
	dgAbstractModuleWrapper		*		currentWrapper;
	
	moduleData * currentModule;
	
	dgSceneObject		*			beatObject;
	
	
	// beat stuff
	
	float	beatLatency, currentTime;
	
	// fade stuff
	float						globalOpacity;
	
	
};

#endif