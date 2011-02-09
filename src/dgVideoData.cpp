/*
 *  dgVideoData.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 09/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgVideoData.h"

void dgVideoData::setup(string xmlURL) {
	
	if ( XML.loadFile(xmlURL) ) {
	} else {
		printf("error loading video XML file");
	}
	
	XML.pushTag("videos", 0);
	
	int numOfSets = XML.getNumTags("set");
	videoSets.reserve(numOfSets);
	
	printf("num of videos sets %d\n", numOfSets);
	
	
	for ( int i=0; i<numOfSets; i++ ) {
		
		XML.pushTag("set", i);
		
		int numOfVideos = XML.getNumTags("video");
		
		printf("num of videos %d\n", numOfVideos);
		
		dgVideoDataSet * videoSet = new dgVideoDataSet();
		for ( int j=0; j<numOfVideos; j++ ) {
			
			//XML.pushTag("video", j);
			string url = XML.getValue("video", "", j);
			
			//printf(url.c_str());
			
			videoSet->addVideo("videoModule/"+url);
			
			//XML.popTag();
			
		}
		XML.popTag();
		videoSets.push_back(videoSet);
	}

}