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
#include "dgVideoModule.h"
#include "dgMixerModuleWrapper.h"
#include "dgLoopModuleWrapper.h"

//#define EDITOR_MODE

class dgModuleView {
	
	public:
	void setup(dgData & layoutData, dgCompBuilder & compBuilder, OscReceiver & oscReceiver, dgSceneEffects & effects, dgVideoModule & videoModule);
	void update();
	void draw();
	void clean();
	
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
	dgVideoModule			*	videoModule;
	
	/* current stuff*/
	
	vector<dgSceneObject*>		currentObjects;
	
	/* wrappers for custom layout actions */
	
	dgAbstractModuleWrapper * getRelatedWrapper (string name);
	
	vector<dgAbstractModuleWrapper*>	modulesWrappers;
	dgAbstractModuleWrapper		*		currentWrapper;
	moduleData					*		currentModule;
	
	dgSceneObject				*		beatObject;
	
	
	
	float						beatLatency, currentTime;
	
	// fade stuff
	float						globalOpacity;
	
	
	ofImage						layerImg;
		
};

#endif