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
	 ofTexture * addImage(string url);
	 ofTexture * getImage(string url);
	 bool  checkIfImageExist(string url);
	
private:
	ofImage					loader;
	vector<ofTexture*>		imageSet;
	vector<string>			imageName;
	int numOfImgs;
	
};
	


#endif