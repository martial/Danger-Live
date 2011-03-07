/*
 *  dgLoopModuleWrapper.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 04/03/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _LOOP_WRAPPER
#define _LOOP_WRAPPER

#include "ofMain.h"
#include "dgAbstractModuleWrapper.h"
#include "moduleData.h"
#include "ofxTimer.h"

class dgLoopModuleWrapper : public dgAbstractModuleWrapper {
	
	
public:
	
	void setup(moduleData * relatedModule, dgVideoModule * videoModule, string name);
	void update();
	void draw();
	
	void init();
	
	void onMidiEvent(int adress, int val);
	void onBeatEvent();
	void onTimerComplete(ofEventArgs & ahou);
	void onTimerOff(ofEventArgs & ahou);
	
	void onLaunchAction();
	void onReleaseAction();
	
	
	
private:
	
	ofImage screen;
	
	vector<dgSceneObject*>		leftSwitches;
	vector<dgSceneObject*>		rightSwitches;
	dgSceneObject		*		centralSwitch;
	
	
	ofxTimer					timer;
	ofxTimer					timerOff;
	
	ofPoint						centralPos;
	int							totalLedsSide;
	
	dgSceneObject *				beatRepBtn;
	dgSceneObject *				beatRepBtnOnOff;
	float						currentBeatPct;
	float						currentTime;
	float						beatTime;
	
	float						beatRepOnOffPct;
	bool						isWaitingForBeat;
	bool						initiated;
	
};

#endif