/*
 *  dgLoopModuleWrapper.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 04/03/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgLoopModuleWrapper.h"


void dgLoopModuleWrapper::setup(moduleData * relatedModule, dgVideoModule * videoModule, string name) {
	
	dgAbstractModuleWrapper::setup(relatedModule, videoModule,name);
	currentTime = 0.0;
	
	
	ofAddListener(timer.TIMER_REACHED, this, &dgLoopModuleWrapper::onTimerComplete);
	
	beatRepBtn = relatedModule->getComponentByNameID("beat_main");	
	beatRepBtnOnOff = relatedModule->getComponentByNameID("beat_main_onoff");
	
	beatRepOnOffPct = beatRepBtn->statePct;
	isWaitingForBeat = false;
	initiated = false;
	
}

void dgLoopModuleWrapper::init () {
	
	
	centralPos.x = 0;
	centralPos.y = 160;
	
	// set central switch
	centralSwitch = builder->createCompByName("BOUTON_POUSSOIR_B");
	
	// create left
	
	totalLedsSide = 6;
	for ( int i=0; i<totalLedsSide*2;i++) {
		
		dgSceneObject * switchObj = builder->createCompByName("BOUTON_POUSSOIR_B");
		
		if ( i<totalLedsSide ) {
		leftSwitches.push_back(switchObj);
		} else {
		rightSwitches.push_back(switchObj);
			
		}		
	}
	
	
}

void dgLoopModuleWrapper::update() {
	
	
	currentBeatPct  =  1.0 - beatRepBtn->pct;

	
	// get value of main btn
	
	centralSwitch->update();
	
	for ( int i=0; i<totalLedsSide;i++) {
		leftSwitches[i]->update();
		rightSwitches[i]->update();
	}
	
}

void dgLoopModuleWrapper::draw () {
	
	
	ofPushMatrix();
	ofTranslate(centralPos.x, centralPos.y, 0);
	centralSwitch->draw();
	
	
	// left
	for ( int i=0; i<totalLedsSide;i++) {
		
		dgSceneObject * switchObj = leftSwitches[i];
		ofPushMatrix();
		ofTranslate(-centralSwitch->width + i * -switchObj->width, 0, 0);
		switchObj->draw();
		ofPopMatrix();
		
	}
	
	for ( int i=0; i<totalLedsSide;i++) {
		
		dgSceneObject * switchObj = rightSwitches[i];
		ofPushMatrix();
		ofTranslate(centralSwitch->width + i * switchObj->width, 0, 0);
		switchObj->draw();
		ofPopMatrix();
		
	}
		
	ofPopMatrix();
	
}


void dgLoopModuleWrapper::onMidiEvent(int adress, int val) {
	
}

void dgLoopModuleWrapper::onBeatEvent () {
	
	
	if ( beatRepBtnOnOff->pct == 0.0 ) return;
	
	centralSwitch->setPct(1.0);
	
	int step = round(currentBeatPct * totalLedsSide);
	
	for ( int i=0; i<totalLedsSide;i++) {
		
		dgSceneObject * switchObj = leftSwitches[i];
		if ( step > i ) {
			switchObj->setPct(1.0);
		} else {
			switchObj->setPct(0.0);
		}
		
	}
	
	for ( int i=0; i<totalLedsSide;i++) {
		
		dgSceneObject * switchObj = rightSwitches[i];
		if ( step > i ) {
			switchObj->setPct(1.0);
		} else {
			switchObj->setPct(0.0);
		}
		
	}
	
	
	
	if ( beatTime != 0.0  ) {
		timer.reset();
		timer.setup(100, false);
		timer.startTimer();	
		
	}
		
	ofAddListener(timer.TIMER_REACHED, this, &dgLoopModuleWrapper::onTimerComplete);
	beatTime = (ofGetElapsedTimeMillis() - currentTime );
	currentTime = ofGetElapsedTimeMillis();
	
}


void dgLoopModuleWrapper::onTimerComplete(ofEventArgs & ahou) {
	
	
	for ( int i=0; i< totalLedsSide;i++) {
		dgSceneObject * switchObj = leftSwitches[i];
		switchObj->setPct(0.0);		
	}
	
	for ( int i=0; i< totalLedsSide;i++) {
		dgSceneObject * switchObj = rightSwitches[i];
		switchObj->setPct(0.0);		
	}
	
	
	
	centralSwitch->setPct(0.0);
	
	
	ofRemoveListener(timer.TIMER_REACHED, this, &dgLoopModuleWrapper::onTimerComplete);
	
}

void dgLoopModuleWrapper::onTimerOff(ofEventArgs & ahou) {
	ofRemoveListener(timerOff.TIMER_REACHED, this, &dgLoopModuleWrapper::onTimerOff);
	centralSwitch->setPct(0.0);

}




