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
	
	float r = (float)currw/(float)currh;
	float wr = (float)maxw/(float)maxh;
	
	
		w = (float)maxw;
		h = (float)maxw / r;
		

	
	
	return 	ofPoint (w,h);
	
}