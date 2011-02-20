#include "testApp.h"
#include "Poco/Delegate.h"
#include "Poco/Timestamp.h"



//--------------------------------------------------------------
void testApp::setup(){
	
	printf("welcome\n");
	
	
	
	float time = ofGetElapsedTimeMillis();
	
	screen1Size.x = 1440;
	screen1Size.y = 900;
	screen2Size.x = 1900;
	screen2Size.y = 1200;
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetLogLevel(OF_LOG_WARNING);
	
	
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
	
	scene.setup(data, videoData, builder, oscReceiver,sceneEffects);
	
	
	debugView.setup();
	
	sceneEffects.setup();
	sceneEffects.setEffectByName("bloom");
	
	fbo.allocate(screen2Size.x, screen2Size.y, GL_RGBA);
	
	oscDebugEnabled = false;
	
	printf("loaded in %f milliseconds \n",  ofGetElapsedTimeMillis() - time);
	
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
	ofSetColor(255, 255, 255);
	fbo.begin();
	ofSetColor(255, 255, 255);
	ofEnableAlphaBlending();
	scene.draw();
	if(oscDebugEnabled)oscReceiver.debugDraw();
	ofDisableAlphaBlending();
	fbo.end();
	
	
	
	ofSetColor(255, 255, 255);
	debugView.draw();
		
	
	ofxFBOTexture * sceneFbo =  sceneEffects.draw(fbo, screen1Size.x,0);
	debugView.drawSceneFbo(sceneFbo, screen1Size.x * .5, screen1Size.y * .5);
	
	
		
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	//printf("key : %d\n", key);
	
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

