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
	void setup (dgVideoDataSet * videoSet);
	void update();
	void draw();
	
	void goNext();
	void play();
	void stop();
	
	private:
	dgVideoDataSet	*	videoSet;
	int					currentVideoID;
	
};

#endif
