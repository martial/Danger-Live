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

class dgVideoModuleView {
	
	public :
	void setup (dgVideoDataSet & videoSet);
	void update();
	void draw();
	
	void onBeatEvent (float beatTime);
	
	void goNext();
	void goNext(int & f);
	void play();
	void stop();
	
	private:
	
	void addBeatListener();
	
	dgVideoDataSet	*	videoSet;
	int					currentVideoID;
	float				currentVideoDuration;
	float				beatTime;
	ofEvent<int>		beatEvent;
	bool				isWaitingForBeat;
	
};

#endif
