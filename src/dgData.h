/*
 *  dgData.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef DGDATA
#define DGDATA
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "dgData.h"
#include "moduleData.h"
#include "dgCompBuilder.h"
#include "ofxDirList.h"

class dgData  {

	public:
	void setup();
	void addSceneObjects (dgCompBuilder & compBuilder);
	void debug();
	void clean();
	
	vector <moduleData*>		data;
	
	private:
	
	
	
	
	ofxXmlSettings				XML;
	ofxDirList					DIR;
	
};

#endif

