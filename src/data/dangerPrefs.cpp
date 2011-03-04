/*
 *  dangerPrefs.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 01/03/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dangerPrefs.h"

void dangerPrefs::setup () {
	
	
	if( XML.loadFile("settings.xml") ){
		//message = "mySettings.xml loaded!";
	}else{
		//message = "unable to load mySettings.xml check data/ folder";
		XML.setValue("SETTINGS:COLOR:CONTRAST", 1.0);
		XML.setValue("SETTINGS:COLOR:BRIGHTNESS", 1.0);
		XML.setValue("SETTINGS:COLOR:SATURATION", 1.0);
		XML.saveFile("settings.xml");
		
	}

}

float dangerPrefs::getContrast () {
	XML.pushTag("SETTINGS", 0);
	XML.pushTag("COLOR", 0);
	float val = XML.getValue("CONTRAST", 1.0, 0);
	XML.popTag();
	XML.popTag();
	return val;
}

float dangerPrefs::getBrightness () {
	XML.pushTag("SETTINGS", 0);
	XML.pushTag("COLOR", 0);
	float val = XML.getValue("BRIGHTNESS", 1.0, 0);
	XML.popTag();
	XML.popTag();
	return val;

}

float dangerPrefs::getSaturation () {
	
	XML.pushTag("SETTINGS", 0);
	XML.pushTag("COLOR", 0);
	float val = XML.getValue("SATURATION", 1.0, 0);
	XML.popTag();
	XML.popTag();
	return val;

}

void dangerPrefs::saveContrast(float val) {
	
	
	XML.setValue("SETTINGS:COLOR:CONTRAST", val);
	XML.saveFile("settings.xml");
	
}

void dangerPrefs::saveBrightness(float val) {
	
	
	XML.setValue("SETTINGS:COLOR:BRIGHTNESS", val);
	XML.saveFile("settings.xml");
	
}

void dangerPrefs::saveSaturation(float val) {
	

	XML.setValue("SETTINGS:COLOR:SATURATION", val);
	XML.saveFile("settings.xml");
	
}

void dangerPrefs::saveColorSettings(float contrastPct, float brightnessPct, float saturationPct) {
	
	
	//XML.setValue("SETTINGS:COLOR:CONTRAST", contrastPct);
	//XML.setValue("SETTINGS:COLOR:BRIGHTNESS", brightnessPct);
	//XML.setValue("SETTINGS:COLOR:SATURATION", saturationPct);
	//XML.saveFile("settings.xml");

}