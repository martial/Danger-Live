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

ofTexture * imgAssetsManager::addImage(string url) {
	
	if (!checkIfImageExist(url)) {
		
		loader.loadImage(ofToDataPath(url));
		
		ofTexture * texture = new ofTexture();
		
		texture->allocate( loader.getWidth(), loader.getHeight(), GL_RGBA );				
		texture->loadData( loader.getPixels(), loader.getWidth(), loader.getHeight(), GL_RGBA );
		
		imageName.push_back(ofToDataPath(url));
		imageSet.push_back(texture);
		return texture;
		
	} else {
		
		return  getImage(url);
	
	}
	//return img;
}

ofTexture *  imgAssetsManager::getImage(string url){
	
	for ( int i=0; i<imageSet.size(); i++) {
		if (imageName[i] == url) return imageSet[i];
	}
	return NULL;
	
}

bool  imgAssetsManager::checkIfImageExist(string url) {
		
	for ( int i=0; i<imageSet.size(); i++) {
		if (imageName[i] == url) return true;
	}
	return false;
}

