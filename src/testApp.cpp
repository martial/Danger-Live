#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	printf("welcome\n");
	
	//ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	oscReceiver.setup();
		
	builder.setup("components.xml");
	data.setup("layouts.xml");
	data.addSceneObjects(&builder);
	
	videoData.setup("videos.xml");
	
	scene.setup(data, videoData, builder, oscReceiver);
}

//--------------------------------------------------------------
void testApp::update(){
	
	oscReceiver.update();
	scene.update();
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	scene.draw();
	
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

