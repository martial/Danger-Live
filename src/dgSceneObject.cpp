/*
 *  dgSceneObject.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgSceneObject.h"


void dgSceneObject::setup (string name) {
	
	this->name = name;
	
	pos.x = 0;
	pos.y = 0;

}

void dgSceneObject::update () {

}

void dgSceneObject::draw () {

}


/*

*/

void dgSceneObject::setPosition (ofPoint pos) {
	
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	
	
}