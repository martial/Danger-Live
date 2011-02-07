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

class dgModuleView {
	
	public:
	void setup(dgData & data);
	void update();
	void draw();
	
	void setCurrentView(int viewID);
	
	
	private:
	
	dgData		*	data;
	int			currentViewID;
	
};

#endif