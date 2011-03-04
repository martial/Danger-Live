/*
 *  dgImgSequenceObject.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 14/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

/*
 *  dgSwitchObject.h
 *  danger_live
 *
 *  Created by Martial Geoffre on 09/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef DGIMGSEQCHOBJECT
#define DGIMGSEQCHOBJECT
#include "ofMain.h"
#include "dgSceneObject.h"
#include "ofxDirList.h"

class dgImgSequenceObject : public dgSceneObject {
	
public:
	
	
	dgImgSequenceObject();
	~dgImgSequenceObject();
	
	void					setup(string folderOn, string folderOff ="", string name ="", string type ="");
	void					update();
	void					draw();
	
	void					addExtraImage(string url, string imgSet);
	void					setPct(float pct);
	
	
	
	private :
	
	//ofImage					img;
	vector<ofTexture*>		images;
	vector<ofTexture*>		imagesOff;
	int						currentIndex;
	
	ofxDirList				DIR;
	
};

#endif