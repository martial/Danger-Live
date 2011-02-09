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
	
	ofxQTKitVideoPlayer * video = new ofxQTKitVideoPlayer();
	video->loadMovie(url, OFXQTVIDEOPLAYER_MODE_PIXELS_ONLY);
	videos.push_back(video);

}