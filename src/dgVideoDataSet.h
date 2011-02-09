/*
 *  dgVideoDataSet.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 09/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _DGVIDEODATASET
#define _DGVIDEODATASET

#include "ofMain.h"
#include "ofxQTKitVideoPlayer.h"

class dgVideoDataSet {

	
	public:
	dgVideoDataSet();
	~dgVideoDataSet();
	void addVideo(string url);
	vector<ofxQTKitVideoPlayer*>	videos;
	
	
	
};


#endif