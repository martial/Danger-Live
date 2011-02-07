#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	printf("welcome\n");
	
	ofSetFrameRate(60);
	scene.setup();
	
	oscReceiver.setup();
	video.setup("videos/knob.mov", "video");
	data.setup("layouts.xml");

}

//--------------------------------------------------------------
void testApp::update(){
	video.update();
	oscReceiver.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	
	scene.draw();
	video.draw();
	oscReceiver.debugDraw();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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

