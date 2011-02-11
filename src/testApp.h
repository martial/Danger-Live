#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "DangerScene.h"
#include "OscReceiver.h"
#include "dgData.h"
#include "dgCompBuilder.h"
#include "dgVideoData.h"
#include "ofxMidiIn.h"
#include "DangerMidiListener.h"
#include "ofEvents.h"
#include "ofxFbo.h"



class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
		void onBeatEvent(int & f);
		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
	
	
		private :
		
		DangerScene			scene;
		OscReceiver			oscReceiver;
		dgData				data;
		dgVideoData			videoData;
		dgCompBuilder		builder;
	
		ofxMidiIn				midiIn;
		DangerMidiListener		midiListener;
	
		ofxFbo						fbo;
		ofTexture					texture;
};

#endif
