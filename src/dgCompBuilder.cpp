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
	} else {
		printf("error");
	}

}

dgSceneObject * dgCompBuilder::createCompByName (string name) {
	
	if (XML.tagExists("components", 0)) XML.pushTag("components", 0);
	
	int numOfComponents = XML.getNumTags("comp");
	components.reserve(numOfComponents);
	
	dgSceneObject  * component;
	
	for ( int i = 0; i<numOfComponents; i++ ) {
		
		// check type
		XML.pushTag("comp", i);
		string compName = XML.getValue("name", "");
		
			if ( compName == name ) {
		
				string type = XML.getValue("type", "");
				string url = XML.getValue("url", "");
		
		
				if ( type == "video") {
			
					dgVideoObject * videoObject = new dgVideoObject();
					videoObject->setup(url, compName);
					component = videoObject;
			
			
				}
				
				if ( type == "image" ) {
			
			
					dgImageObject * imageObject = new dgImageObject();
					imageObject->setup(url, compName);
					component = imageObject;
			
			
				}
				
				
				if ( type == "switch" ) {
					
					
					dgSwitchObject * switchObject = new dgSwitchObject();
					switchObject->setup(url, compName);
										
					
					
						
						XML.pushTag("extras_url", 0);
						int numOfExtrasUrl = XML.getNumTags("extraurl");
						for (int z=0; z<numOfExtrasUrl;z++ ) {
							
							string extraURL = XML.getValue("extraurl", "", z);
							switchObject->addExtraImage(extraURL);
							//printf("-----------------------------------------------------------------------\n");
							//printf(extraURL.c_str());
							//printf("\n");
						}
						XML.popTag();
					
					
					component = switchObject;

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
				}
				XML.popTag();
			}
		XML.popTag();
		
		

	}
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
