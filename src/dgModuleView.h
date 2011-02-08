/*
 *  dgModuleView.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef DGMODULEVIEW
#define DGMODULEVIEW

#include "ofMain.h"
#include "dgData.h"
#include "dgCompBuilder.h"

class dgModuleView {
	
	public:
	void setup(dgData & layoutData, dgCompBuilder & compBuilder);
	void update();
	void draw();
		
	void setCurrentView(int viewID);
	
	
	private:
	
	void addSceneObjects();

	
	dgData					*	layoutData;
	dgCompBuilder			*	compBuilder;
	
	int							currentViewID;
	
	vector<dgSceneObject*>		currentObjects;
	
};

#endif