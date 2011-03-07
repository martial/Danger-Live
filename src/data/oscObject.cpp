/*
 *  oscObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 25/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "oscObject.h"

oscObject::oscObject () {
	multiplierReferent = NULL;
	oscMultiplier = "";
	pct = 0.0;
}

void oscObject::setMultiplierReferent(oscObject * referent) {

	if ( !referent ) {
		
		printf("Error - no multiplier referent here \n");
		
	} else {
			
		this->multiplierReferent = referent;
		
	}
	
}

void oscObject::setPct(float val) {
	this->pct = val;
	if ( multiplierReferent ) {
		this->pct *= multiplierReferent->pct;
	}
	

	
	
	/*
	if ( oscAdress.substr(0, 19) == "/live/track/volume/" ) {
			printf("ok from osc %f\n", pct);
	}
	 */
	
	ofNotifyEvent(onPctChangeEvent, this->pct);	
}

void oscObject::setPct(float val, float duration) {
	
	this->pct = val;
	ofNotifyEvent(onPctChangeEvent, this->pct);	
	
	printf("OK !");
	
	timer.stopTimer();
	timer.setup(15, false);
	timer.startTimer();
	ofRemoveListener(timer.TIMER_REACHED, this, &oscObject::onTimerComplete);
	ofAddListener(timer.TIMER_REACHED, this, &oscObject::onTimerComplete);
}

void oscObject::onTimerComplete(ofEventArgs & ahou) {
	printf("DONE !");
	this->pct = 0.0;
	ofRemoveListener(timer.TIMER_REACHED, this, &oscObject::onTimerComplete);
	ofNotifyEvent(onPctChangeEvent, this->pct);	
}