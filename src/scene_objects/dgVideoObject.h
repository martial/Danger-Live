/*
 *  dgVideoObject.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef DGVIDEOOBJ
#define DGVIDEOOBJ
#include "ofMain.h"
#include "dgSceneObject.h"
#include "ofxQTKitVideoPlayer.h"

class dgVideoObject : public dgSceneObject {

	public:
	dgVideoObject();
	~dgVideoObject();
	void					setup(string videoUrl, string name, string type);
	void					update();
	void					draw();
	
	void					setPct(float pct);
	
	private :
	
	ofxQTKitVideoPlayer		* mainVideo;
	
	
	
};

#endif