/*
 *  dgVideoModuleView.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 09/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _DGVIDEOMODULEVIEW
#define _DGVIDEOMODULEVIEW

#include "ofMain.h"
#include "dgVideoDataSet.h"
#include "ofxVec2f.h"
#include "ofxUtils.h"
#include "ofxFBOTexture.h"

//#define USEOFXQTKIT

class dgVideoModuleView {
	
	public :
	void setup (dgVideoDataSet & videoSet);
	void update();
	void draw();
	
	ofTexture	* getVideoTexture();
	//ofxQTKitVideoPlayer  * getVideoInstance();
	ofVideoPlayer * getVideoInstance();
	
	void onBeatEvent (float beatTime);
	
	void goNext();
	void goNext(int & f);
	void play();
	void stop();
	void setRandomVideo();
	int getRandom (int max);
	
	dgVideoDataSet	*	videoSet;
	int					currentVideoID;
	
	private:
	
	void addBeatListener();
	
	
	
	float				currentVideoDuration;
	float				beatTime;
	ofEvent<int>		beatEvent;
	bool				isWaitingForBeat;
	
	#ifdef USEOFXQTKIT
	ofxFBOTexture	*	fboVideo;
	#endif
};

#endif
