/*
 *  componentData.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef COMPDATA
#define COMPDATA

#include "ofMain.h"


class componentData {

	public:
	
	componentData();
	~componentData();
	string		name;
	string		adress;
	ofPoint		range;
	ofPoint		pos;
	float		rotation;
	
};

#endif
