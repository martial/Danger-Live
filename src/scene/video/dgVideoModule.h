/*
 *  dgVideoModule.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 09/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */



#ifndef _DGVIDEOMODULE
#define _DGVIDEOMODULE

#include "ofMain.h"
#include "dgVideoData.h"
#include "dgVideoDataSet.h"
#include "dgVideoModuleView.h"

class dgVideoModule {
		
	
	public :
	
	void setup(dgVideoData & videoData);
	void update();
	void draw();
	
	ofTexture	* getVideoTexture();
	
	void init();
	void stop();
	void setCurrentView (int viewID);
	
	void onBeatEvent(float beatTime);
	
	
	private:
	
	dgVideoData		*			videoData;
	
	vector<dgVideoModuleView*>	views;
	
	int							currentView;
	
	
};

#endif