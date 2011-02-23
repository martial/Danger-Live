/*
 *  dgAbstractEffect.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 15/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgAbstractEffect.h"

void dgAbstractEffect::setup(string name) {
	this->name = name;
}

void dgAbstractEffect::init() {
	
}

void dgAbstractEffect::update() {

}

void dgAbstractEffect::draw(ofxFBOTexture & fbo) {

}

ofxFBOTexture *  dgAbstractEffect::draw(ofxFBOTexture & fbo, int x, int y) {

}