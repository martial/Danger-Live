/*
 *  oscObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 25/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "oscObject.h"

void oscObject::setPct(float val) {
	this->pct = val/127;
	ofNotifyEvent(onPctChangeEvent, this->pct);
	
	/*
	 
	 
	 if ( splitString != "/signal" ) {
	 splitString = msg.address.substr(0, 19);
	 div = (splitString == "/live/track/volume/" ) ? 1.0 : 127.0;
	 if ( splitString =="/live/track/volume/" ) {
	 
	 //printf("ok\n");
	 //printf("val : %f\n", div);
	 //printf("val msg : %f\n", msg.value);
	 
	 
	 }
	 }
	 
	 */
	
}