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
	
	
	midiListener.setup(scene, sceneEffects);
	midiIn.listPorts();
	midiIn.openPort(0); 
	midiIn.addListener(&midiListener);
	
	
	 
	/* data */
	builder.setup("components.xml");
	data.setup();
	data.addSceneObjects(builder);
	
	/* scene */
	videoData.setup("videos.xml");
	
	scene.setup(data, videoData, builder, oscReceiver);
	
	
	debugView.setup();
	
	sceneEffects.setup();
	//sceneEffects.setEffectByName("bloom");
	
	fbo.allocate(1920, 1080, GL_RGBA);
	
	oscDebugEnabled = false;
	//fbo.setup(ofGetWidth(), ofGetHeight());
	//fbo.attach(texture);
}

//--------------------------------------------------------------
void testApp::update(){
	
	oscReceiver.update();
	scene.update();
	sceneEffects.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	ofBackground(0, 0, 0);
	//fbo.clear(0,0,0,0);
	fbo.begin();
	//fbo.clean();
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255);
	scene.draw();
	if(oscDebugEnabled)oscReceiver.debugDraw();
	ofDisableAlphaBlending();
	fbo.end();
	
	
	
	
	ofSetColor(255, 255, 255);
	debugView.draw();
	debugView.drawSceneFbo(fbo);
	
	// draw proj
	//fbo.draw(1440*.5 - fbo.texData.width*.5, 900*.5-fbo.texData.height*.5);
	
	
	ofPushMatrix();
	//glTranslated(1440, 0, 0);
	//scene.draw();
	sceneEffects.draw(fbo,1440,0);
	ofPopMatrix();
	//fbo.draw(1440, 0);
	
	/*
	if ( debugView.visible ) {
		fbo.draw(1440*.5 - fbo.texData.width*.5, 900*.5-fbo.texData.height*.5);
		//fbo.draw(1440 + (1920 *.5)  - fbo.texData.width*.5, 900*.5-fbo.texData.height*.5);
		debugView.draw();
		debugView.drawSceneFbo(fbo);
	} else {
		
		debugView.draw();
		debugView.drawSceneFbo(fbo);
		fbo.draw(1440, 0);
		//oscReceiver.debugDraw();
		
	}
	 
	 */
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
			//debugView.visible = !debugView.visible;
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
			
		case 'o':
			oscReceiver.setup();
			break;
			
		case 'g':
			oscDebugEnabled = !oscDebugEnabled;
			break;
			
		default:
			break;
	}
	
	

}

void testApp::onBeatEvent(int & f){
	
	scene.onBeatEvent();
	debugView.onBeatEvent();
}

void testApp::onOscEvent(customOscMessage & f ) {
	scene.onOscEvent(f);
	
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

