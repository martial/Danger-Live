/*
 *  dgVideoData.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 09/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _DGVIDEODATA
#define _DGVIDEODATA

#include "ofMain.h"
#include "dgVideoDataSet.h"
#include "ofxXmlSettings.h"


class dgVideoData {

	public:
	void setup(string xmlURL);
	
	vector<dgVideoDataSet*>	videoSets;
	
	private:
	
	ofxXmlSettings		XML;
	
};


#endif