/*
 *  fpsViewer.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 25/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _FPSVIEWER
#define _FPSVIEWER

#include "ofMain.h"

class fpsViewer {
	
	
	public :
	
	void setup(int width, int height, int maxFps);
	void update();
	void draw(int x, int y);
	void draw(int x, int y,int width, int height);
	
	private :
	
	int width, height, maxFps;
	
	/* fps */
	
	vector<int>		fpsHistory;
	int				fpsCounter;
	
};

#endif
