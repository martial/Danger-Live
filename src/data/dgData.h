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
#include "oscObjectManager.h"
#include "customOscMessage.h"

class dgData  {

	public:
	void setup(dgCompBuilder & compBuilder);
	void update();
	//void addSceneObjects (dgCompBuilder & compBuilder);
	void debug();
	void clean();
	
	float getPctByAdress(string address);
	
	void onOscEvent (customOscMessage & msg );
	void onBeatEvent();
	
	moduleData * getModuleByName(string nameTarget);
	
	
	
	vector <moduleData*>		data;
	
	private:
	
	
	
	oscObjectManager			oscObjManager;
	ofxXmlSettings				XML;
	ofxDirList					DIR;
	
};

#endif

