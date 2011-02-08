/*
 *  DangerScene.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#pragma once
#include "ofMain.h"
#include "DangerBackground.h"
#include "dgModuleView.h"
#include "dgCompBuilder.h"

class DangerScene {

	public:
	
	DangerScene();
	void setup(dgData & layoutData, dgCompBuilder & compBuilder);
	void update();
	void draw();
	
	/* delete this later */
	void setCurrentView(int viewID);
	
	private:
	
	DangerBackground	background;
	dgModuleView		moduleView;
	
};