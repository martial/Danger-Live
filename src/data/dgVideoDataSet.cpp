/*
 *  dgVideoDataSet.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 09/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgVideoDataSet.h"

dgVideoDataSet::dgVideoDataSet() {
	
}

dgVideoDataSet::~dgVideoDataSet() {
	
}

void dgVideoDataSet::addVideo(string url) {
	
	
#ifdef USEOFXQTKIT
	ofxQTKitVideoPlayer * video = new ofxQTKitVideoPlayer();
	video->loadMovie(url,1);
#else 
	ofVideoPlayer * video = new ofVideoPlayer();
	video->loadMovie(url);
#endif
	
	
	videos.push_back(video);

}