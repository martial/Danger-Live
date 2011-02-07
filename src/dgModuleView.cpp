/*
 *  dgModuleView.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgModuleView.h"

void dgModuleView::setup (dgData & data) {
	
	this->data = &data;

}

void dgModuleView::update() {

}

void dgModuleView::draw () {

}


/*

*/


void dgModuleView::setCurrentView(int viewID) {

	currentViewID = viewID;
	
}