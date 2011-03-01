/*
 *  imgAssetsManager.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 16/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "imgAssetsManager.h"

imgAssetsManager::imgAssetsManager () {
		
	numOfImgs = 0;
}

ofImage * imgAssetsManager::addImage(string url) {
	
	//printf("yo");
	
	//printf("size : %d\n", numOfImgs);
	//numOfImgs++;
	
	if (!checkIfImageExist(url)) {
		ofImage * img = new ofImage();
		img->loadImage(ofToDataPath(url));
		//img->setUseTexture(false);
		imageSet.push_back(img);
		return img;
		
	} else {
		//printf("exist");
		return  getImage(url);
		
	}
	//return img;
}

ofImage *  imgAssetsManager::getImage(string url){
	
	for ( int i=0; i<imageSet.size(); i++) {
		if (imageSet[i]->fileName == url) return imageSet[i];
	}
	return NULL;
	
}

bool  imgAssetsManager::checkIfImageExist(string url) {
	
	//printf("size : %d\n", imageSet.size());
	
	for ( int i=0; i<imageSet.size(); i++) {
		if (imageSet[i]->fileName == url) return true;
	}
	return false;
}

