#pragma once

#include "ofMain.h"
#include "DangerScene.h"
#include "OscReceiver.h"
#include "dgData.h"
#include "dgCompBuilder.h"
#include "dgVideoData.h"
#include "ofxMidiIn.h"
#include "DangerMidiListener.h"
#include "ofEvents.h"
#include "ofxFBOTexture.h"
#include "dgDebugView.h"
#include "customOscMessage.h"
#include "dangerPrefs.h"

#include "ofxFenster.h"

//#define EDITOR_MODE
//#define _USE_FENSTER


#ifdef _USE_FENSTER
class dangerApp : public ofBaseApp , public ofxFensterListener{
#else
class dangerApp : public ofBaseApp {
#endif	

public:
	void setup();
	void update();
	void draw();
	
	#ifdef _USE_FENSTER
	void fensterDraw();
	void fensterUpdate();
	#endif
	
	void reset();
	void onBeatEvent(int & f);
	void onOscEvent(customOscMessage & f ) ;
	void onMasterSignalEvent(float & val);
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	
	
	private :
	
	DangerScene					scene;
	OscReceiver					oscReceiver;
	dgData						data;
	dgVideoData					videoData;
	dgCompBuilder				builder;
	
	ofxMidiIn					midiIn;
	DangerMidiListener			midiListener;
	
	dangerPrefs					appSettings;
		
	dgDebugView					debugView;
		
	ofxFBOTexture		*		fbo;
	ofxFBOTexture		*		sceneFbo;
	dgSceneEffects				sceneEffects;
	
	ofPoint						screen1Size, screen2Size;
	
	bool						oscDebugEnabled;
	
	
	float						panelViewScale;
	float						masterVariation;
	
	
	fpsViewer					fps;
	
	
	
	//ofTexture					texture;
};

//#endif
