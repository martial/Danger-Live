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
#include "customOscMessage.h"
#include "dgSceneEffects.h"

class DangerScene {

	public:
	
	DangerScene();
	void setup(dgData & layoutData, dgVideoData & videoData, dgCompBuilder & compBuilder, OscReceiver & oscReceiver, dgSceneEffects & effects);
	void update();
	void draw();
	void clean();
	
	ofTexture * getVideoTexture();
	
	void changeMode (int mode); 
	
	
	void onOscEvent(customOscMessage & msg);
	void onBeatEvent();
	void onMidiEvent(int adress, int val);
	
	void fade();	
	void onFadeChangeComplete (int & e);
	/* delete this later */
	void setCurrentView(int viewID);
	
	float				globalOpacity,globalOpacityDown;
	
	private:
	
	DangerBackground	background;
	dgModuleView		moduleView;
	dgVideoModule		videoView;
	dgSceneEffects	*	effects;
	
	int					currentMode;
	int					currentView;
	
	
	/* beat utils*/ 
	
	float				oldTime;
	float				beatTime;
	
	/*		*/
	

	bool				isfading;
	bool				isFadeIn;
	int				sens;
	
};

#endif