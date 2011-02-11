/*
 *  ofxUtils.cpp
 *  openFrameworks
 *
 *  Created by Chuck Chase on 30/04/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxUtils.h"



ofPoint ofxUtils::getSizeRatio ( int maxw, int maxh, int currw, int currh ) {

	float w,h;
	
	//int ofW = ofGetWidth();
	//int ofH = ofGetHeight();
	
	float stageAspectRatio = (float)maxw/(float)maxh;
	float imageAspectRatio = (float)currw/(float)currh;
	
	
	if ( stageAspectRatio >= imageAspectRatio ) {
	
	w = (float)maxw;
	h = (float)maxw / imageAspectRatio;
		
	} else {
		
	w = (float)maxh * imageAspectRatio;
	h = (float)maxh;

		
	}
	
	 
	
	
	return 	ofPoint (w,h);
	
}