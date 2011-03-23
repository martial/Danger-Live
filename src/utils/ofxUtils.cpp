/*
 *  ofxUtils.cpp
 *  openFrameworks
 *
 *  Created by Chuck Chase on 30/04/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxUtils.h"



ofPoint ofxUtils::getSizeRatio ( int maxw, int maxh, float currw, float currh, bool keepInto ) {

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
	
	if ( keepInto ) {
		
		if ( currw > maxw ) {
			
			w = (float)maxw;
			float scale = maxw / currw;
			h = (float)currh * scale;
			
		} 
		
		if ( currh > maxh ) {
			
			h = (float)maxh;
			float scale = maxh / currh;
			w = (float)currw * scale;
			
		} 
		
		if ( w > maxw ) {
			
			w = (float)maxw;
			float scale = maxw / currw;
			h = (float)currh * scale;
			
		} 
		
		if ( h > maxh ) {
			
			h = (float)maxh;
			float scale = maxh / currh;
			w = (float)currw * scale;
			
		} 
		
		
	}
	
	 
	
	
	return 	ofPoint (w,h);
	
}