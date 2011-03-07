/*
 *  moduleData.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */



#ifndef MODULEDATA
#define MODULEDATA

#include "ofMain.h"
#include "componentData.h"
#include "dgSceneObject.h"

class moduleData {

	public:
	
	moduleData();
	~moduleData();
	void setup();
	
	dgSceneObject * getComponentByNameID (string nameId );
		
	
	
	vector <componentData*>	cpData;
	vector <dgSceneObject*>	cpObjects;
	
	string						name;
	string						layer;
	string						layout;
	
	void clean();
	
	private:
	
	
	
};


#endif