/*
 *  dgCompBuilder.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 08/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef DGCOMPBUILDER
#define DGCOMPBUILDER

#include "ofMain.h"
#include "imgAssetsManager.h"
#include "ofxXmlSettings.h"
#include "dgSceneObject.h"
#include "dgVideoObject.h"
#include "dgImageObject.h"
#include "dgSwitchObject.h"
#include "dgFaderObject.h"
#include "dgMultipleLedObject.h"
#include "dgRotationBtnObject.h"
#include "dgImgSequenceObject.h"
#include "dgProgressBarObject.h"
#include "dgOpacitySwitchObject.h"

class dgCompBuilder {
	
	public :
	
	void setup(string xmlURL);
	void draw();
	void init();
	
	dgSceneObject   getCopyObjectByName (string name); 
	dgSceneObject * createCompByName (string name);
	
	
	vector<dgSceneObject*>	 components;
	
	private:
	
	ofxXmlSettings		XML;
	imgAssetsManager	imgsAssets;
	
};

#endif