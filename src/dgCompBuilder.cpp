/*
 *  dgCompBuilder.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 08/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "dgCompBuilder.h"


void dgCompBuilder::setup (string xmlURL) {
	
	
	if ( XML.loadFile(xmlURL) ) {
		
		printf("ok build xml\n");
	} else {
		//exit();
		printf("error build xml\n");
	}

}

dgSceneObject * dgCompBuilder::createCompByName (string name) {
	
		
	XML.pushTag("components", 0);
	
	int numOfComponents = XML.getNumTags("comp");
	//components.reserve(numOfComponents);
	
	dgSceneObject  * component;
	
	
	printf("\ncheck for name : ");
	printf(name.c_str());
	printf("\n");
	
	printf("num of components: %d :", numOfComponents);
	
	for ( int i = 0; i<numOfComponents; i++ ) {
		
		//printf("level %d\n : ", XML.getPushLevel());
		XML.pushTag("comp",i);
	
		
		
		
		string compName = XML.getValue("name", "");
		
		

			if ( compName == name ) {
				
				printf(" | name found");
				printf("\n");
				
		
				string type = XML.getValue("type", "");
				string url = XML.getValue("url", "");
		
		
				if ( type == "video") {
			
					dgVideoObject * videoObject = new dgVideoObject();
					videoObject->setup(url, compName, type);
					component = videoObject;
			
			
				}
				
				if ( type == "image" ) {
			
			
					dgImageObject * imageObject = new dgImageObject();
					imageObject->setup(url, compName, type);
					component = imageObject;
			
			
				}
				
				if ( type == "fader" ) {
					
					
					dgFaderObject * faderObject = new dgFaderObject();
					faderObject->setup(url, compName, type);
					
					
					if (XML.tagExists("config", 0)) {
						
						XML.pushTag("config", 0);
						int numOfConfigsValues = XML.getNumTags("item");
						for (int x=0; x<numOfConfigsValues;x++ ) {
							float val = ofToFloat(XML.getValue("item", "", x));
							faderObject->addConfig(val);						
						}
						XML.popTag();
					}
					component = faderObject;
					
				}
				
				
				
				if ( type == "switch" ) {
					
					
					dgSwitchObject * switchObject = new dgSwitchObject();
					switchObject->setup(url, compName, type);
										
						
					if (XML.tagExists("extras_url", 0)) {

						XML.pushTag("extras_url", 0);
						int numOfExtrasUrl = XML.getNumTags("extraurl");
						for (int z=0; z<numOfExtrasUrl;z++ ) {
							string extraURL = XML.getValue("extraurl", "", z);
							switchObject->addExtraImage(extraURL);
						}
						XML.popTag();
						
					}
					
					component = switchObject;

				}
				
				if ( type == "meter" ) {
					
					
					dgMultipleLedObject * multipleLed = new dgMultipleLedObject();
					multipleLed->setup( compName, type);
					
					string switchID = XML.getValue("switch_id", "");
					multipleLed->sceneObjectRefName = switchID;
					XML.pushTag("config", 0);
					int numOfConfigsValues = XML.getNumTags("item");
					for (int x=0; x<numOfConfigsValues;x++ ) {
						float val = ofToFloat(XML.getValue("item", "", x));
						multipleLed->addConfig(val);	
						printf("ADD WTF CONFIG");
					}
					XML.popTag();
					// ok. How many cols we have ?
				
					component = multipleLed;
					
				}
				
				if ( type == "image_knob" ) {
					
					
					dgRotationBtnObject * rotObject = new dgRotationBtnObject();
					rotObject->setup( url, compName, type);
					
					if (XML.tagExists("config", 0)) {
						
						XML.pushTag("config", 0);
						int numOfConfigsValues = XML.getNumTags("item");
							for (int x=0; x<numOfConfigsValues;x++ ) {
								float val = ofToFloat(XML.getValue("item", "", x));
								rotObject->addConfig(val);	
							}
						XML.popTag();
					}
					
					if (XML.tagExists("extras_url", 0)) {
						
						XML.pushTag("extras_url", 0);
						int numOfExtrasUrl = XML.getNumTags("extraurl");
						for (int z=0; z<numOfExtrasUrl;z++ ) {
							string extraURL = XML.getValue("extraurl", "", z);
							rotObject->addExtraImage(extraURL);
						}
						
						XML.popTag();
					}
					
					component = rotObject;
					
				}

				// see if component has some extras
				
				if (XML.tagExists("medias", 0)) {
					
					XML.pushTag("medias", 0);
					int numOfMedias = XML.getNumTags("media");
					
					//printf ("Number of numOfMedias : %d\n", numOfMedias);
					
					for ( int j=0; j<numOfMedias; j++) {
						
						XML.pushTag("media", j);
						string mediaUrl = XML.getValue("url", "");
						string mediaType = XML.getValue("type", "");
						
						component->addMedia(mediaUrl, mediaType);
						XML.popTag();
					}	
					XML.popTag();
				}
			} else {
					
			}
		
		
		XML.popTag();
	}
	
	
	
	if ( component == NULL ) {
		printf("\nname not found - empty object");
		printf("\n");
	}
	
	
	
	XML.popTag();
	return component;
}

dgSceneObject  dgCompBuilder::getCopyObjectByName (string name) {
	
	for (int i = 0; i< components.size(); i++) {
		if (components[i]->name == name ) return *components[i];
	}
	//return NULL;
}

void dgCompBuilder::draw( ){
	
	int xPos = 0;
	int yPos = 0;
	for (int i = 0; i< components.size(); i++) {
		components[i]->update();
		components[i]->setPosition(xPos, yPos);
		components[i]->draw();
		
		xPos += components[i]->width;
		
		if ( xPos > ofGetWidth() ) {
			xPos = 0;
			yPos += components[i]->height;
		}		
	}
	
}
