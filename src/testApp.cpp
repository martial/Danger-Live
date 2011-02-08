#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	printf("welcome\n");
	
	//ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	
	oscReceiver.setup();
	//video.setup("videos/knob.mov", "video");
	data.setup("layouts.xml");
	
	builder.setup("components.xml");

	
	scene.setup(data, builder, oscReceiver);
}

//--------------------------------------------------------------
void testApp::update(){
	//video.update();
	scene.update();
	oscReceiver.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	
	scene.draw();
	//video.draw();
	
	//builder.draw();
	//oscReceiver.debugDraw();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	switch (key) {
		case 'q':
			scene.setCurrentView(1);
			break;
		
		case 'w':
			scene.setCurrentView(0);
			break;
		
		default:
			break;
	}
	
	

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

