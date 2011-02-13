#include "testApp.h"
#include "Poco/Delegate.h"
#include "Poco/Timestamp.h"



//--------------------------------------------------------------
void testApp::setup(){
	
	printf("welcome\n");
	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	/* Midi / OSC */
	oscReceiver.setup();
	ofAddListener(oscReceiver.beatEvent,this,&testApp::onBeatEvent);
	ofAddListener(oscReceiver.oscEvent,this,&testApp::onOscEvent);
	
	/*
	midiListener.setup(scene);
	midiIn.listPorts();
	midiIn.openPort(0); 
	midiIn.addListener(&midiListener);
	//printf("ahou3\n");
	*/
	 
	/* data */
	builder.setup("components.xml");
	data.setup();
	data.addSceneObjects(builder);
	
	/* scene */
	videoData.setup("videos.xml");
	
	scene.setup(data, videoData, builder, oscReceiver);
	
	
	debugView.setup();
	
	fbo.allocate(1920, 1080,GL_RGB);
	//fbo.setup(ofGetWidth(), ofGetHeight());
	//fbo.attach(texture);
}

//--------------------------------------------------------------
void testApp::update(){
	
	oscReceiver.update();
	scene.update();
	
}

//--------------------------------------------------------------
void testApp::draw(){
	

	
	fbo.begin();
	ofEnableAlphaBlending();
	scene.draw();
	ofDisableAlphaBlending();
	fbo.end();
	
	
	
	if ( debugView.visible ) {
		fbo.draw(ofGetWidth()*.5 - fbo.texData.width*.5, ofGetHeight()*.5-fbo.texData.height*.5);
		debugView.draw();
		debugView.drawSceneFbo(fbo);
	} else {
		
		fbo.draw(0, 0);
		oscReceiver.debugDraw();
		
	}
	//ofDrawBitmapString( ofToString(ofGetFrameRate()), 10, 10 );
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	printf("key : %d\n", key);
	
	switch (key) {
			
		case 'f':
			ofToggleFullscreen();
			break;
		
		case 'q':
			scene.setCurrentView(1);
			break;
		
		case 'w':
			scene.setCurrentView(0);
			break;
			
		case 'p':
			debugView.visible = !debugView.visible;
			break;
		
		#ifdef EDITOR_MODE
		case 'r':
			reset();
		#endif
		
		// up
		case 357:
			scene.changeMode(0);
			break;
		
			//down
		case 359:
			scene.changeMode(1);
			break;
			
		// left
		case 356:
			//scene.setCurrentView(<#int viewID#>))
			break;
			
		// right
		case 358:
			scene.changeMode(1);
			break;
			
			
		default:
			break;
	}
	
	

}

void testApp::onBeatEvent(int & f){
	
	scene.onBeatEvent();
	debugView.onBeatEvent();
}

void testApp::onOscEvent(int & f ) {
	scene.onOscEvent();
	
}

void testApp::reset () {
	builder.setup("components.xml");
	data.clean();
	data.setup();
	data.addSceneObjects(builder);
}


//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

