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
	int mode = OFXQTVIDEOPLAYER_MODE_TEXTURE_ONLY;
	ofxQTKitVideoPlayer * video = new ofxQTKitVideoPlayer();
	video->loadMovie(url,mode);
#else 
	ofVideoPlayer * video = new ofVideoPlayer();
	video->loadMovie(url);
	video->setUseTexture(true);
#endif
	
	
	videos.push_back(video);

}