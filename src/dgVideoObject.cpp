/*
 *  dgVideoObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgVideoObject.h"

void dgVideoObject::setup (string videoUrl, string name) {
	
	dgSceneObject::setup(name);
	
	int mode = OFXQTVIDEOPLAYER_MODE_TEXTURE_ONLY;
	mainVideo.loadMovie(videoUrl, mode);
	mainVideo.play();
}

void dgVideoObject::update () {
	
	dgSceneObject::update();
	
	mainVideo.update();
	
}

void dgVideoObject::draw () {
	
	dgSceneObject::draw();
	
	ofEnableAlphaBlending();
	mainVideo.draw(pos.x, pos.y);
	ofDisableAlphaBlending();
}


/*


*/


void dgVideoObject::setPct(float pct) {
	
	
	mainVideo.setPosition(pct);
	
	
}