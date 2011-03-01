/*
 *  imgAssetsManager.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 16/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _IMGASSETSMANAGER
#define _IMGASSETSMANAGER

#include "ofMain.h"

class imgAssetsManager  {
	
	public:
		
	imgAssetsManager();
	 ofImage * addImage(string url);
	 ofImage * getImage(string url);
	 bool  checkIfImageExist(string url);
	
private:
	 vector<ofImage*>		imageSet;
	int numOfImgs;
	
};
	


#endif