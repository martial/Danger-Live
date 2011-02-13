/*
 *  DangerScene.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#define DGSCENEVIEWMODE_MODULE 0
#define DGSCENEVIEWMODE_VIDEOS 1

#ifndef DGSCENE
#define DGSCENE

#include "ofMain.h"
#include "DangerBackground.h"
#include "dgModuleView.h"
#include "dgCompBuilder.h"
#include "OscReceiver.h"
#include "dgVideoModule.h"

class DangerScene {

	public:
	
	DangerScene();
	void setup(dgData & layoutData, dgVideoData & videoData, dgCompBuilder & compBuilder, OscReceiver & oscReceiver);
	void update();
	void draw();
	
	void changeMode (int mode); 
	
	
	void onOscEvent();
	void onBeatEvent();
	
	/* delete this later */
	void setCurrentView(int viewID);
	
	private:
	
	DangerBackground	background;
	dgModuleView		moduleView;
	dgVideoModule		videoView;
	
	int					currentMode;
	int					currentView;
	
	
	/* beat utils*/ 
	
	float				oldTime;
	float				beatTime;
	
};

#endif