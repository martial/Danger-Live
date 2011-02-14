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

class dgModuleView {
	
	public:
	void setup(dgData & layoutData, dgCompBuilder & compBuilder, OscReceiver & oscReceiver);
	void update();
	void draw();
		
	void setCurrentView(int viewID);
	
	void onOscEvent(customOscMessage & msg);
	
	private:
	
	/* Communication OSC*/
	void processOsc (customOscMessage & msg);
	dgSceneObject  * getRelatedObject(string val);

	/* Instances  */
	dgData					*	layoutData;
	dgCompBuilder			*	compBuilder;
	OscReceiver				*	oscReceiver;
	
	int							currentViewID;
	vector<dgSceneObject*>		currentObjects;
	
	/* */
	
	
};

#endif