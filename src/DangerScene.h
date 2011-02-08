/*
 *  DangerScene.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef DGSCENE
#define DGSCENE

#include "ofMain.h"
#include "DangerBackground.h"
#include "dgModuleView.h"
#include "dgCompBuilder.h"
#include "OscReceiver.h"

class DangerScene {

	public:
	
	DangerScene();
	void setup(dgData & layoutData, dgCompBuilder & compBuilder, OscReceiver & oscReceiver);
	void update();
	void draw();
	
	/* delete this later */
	void setCurrentView(int viewID);
	
	private:
	
	DangerBackground	background;
	dgModuleView		moduleView;
	
};

#endif