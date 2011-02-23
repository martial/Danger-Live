#include "dangerApp.h"
#include "Poco/Delegate.h"
#include "Poco/Timestamp.h"

#include "ofxCocoa.h"



//--------------------------------------------------------------
void dangerApp::setup(){
	
	printf("welcome\n");
	

	
	doVSync			= true;
	doDisplayLink	= true;
	
	ofSetVerticalSync(doVSync);	
	MSA::ofxCocoa::setSyncToDisplayLink(false);
	//ofSetFrameRate(0);			// run as fast as you can
	
	//MSA::ofxCocoa::showSystemUI(kUIModeNormal);
	//MSA::ofxCocoa::setTransparent(true);
	//	MSA::ofxCocoa::setWindowLevel(NSScreenSaverWindowLevel);
	
	
	float time = ofGetElapsedTimeMillis();
	
	screen1Size.x = 1440;
	screen1Size.y = 900;
	screen2Size.x = 1920;
	screen2Size.y = 1080;
	
	//ofSetVerticalSync(true);
	ofSetFrameRate(0);
	ofSetLogLevel(OF_LOG_WARNING);
	
	
	/* Midi / OSC */
	oscReceiver.setup();
	ofAddListener(oscReceiver.beatEvent,this,&dangerApp::onBeatEvent);
	ofAddListener(oscReceiver.oscEvent,this,&dangerApp::onOscEvent);
	
	
	midiListener.setup(scene, sceneEffects);
	midiIn.listPorts();
	midiIn.openPort(0); 
	midiIn.addListener(&midiListener);
	
	
	
	/* data */
	builder.setup(ofToDataPath("components.xml"));
	data.setup();
	data.addSceneObjects(builder);
	
	/* scene */
	videoData.setup(ofToDataPath("videos.xml"));
	
	scene.setup(data, videoData, builder, oscReceiver,sceneEffects);
	
	
	debugView.setup();
	
	sceneEffects.setup();
	sceneEffects.setEffectByName("bloom");
	
	fbo = new ofxFBOTexture();
	fbo->allocate(screen2Size.x, screen2Size.y, GL_RGBA);
	fbo->clear(0,0,0,0);
	
	oscDebugEnabled = false;
	
	printf("loaded in %f milliseconds \n",  ofGetElapsedTimeMillis() - time);
	
	
	MSA::ofxCocoa::setSyncToDisplayLink(true);
	//fbo.setup(ofGetWidth(), ofGetHeight());
	//fbo.attach(texture);
}

//--------------------------------------------------------------
void dangerApp::update(){
	
	oscReceiver.update();
	scene.update();
	sceneEffects.update();
}

//--------------------------------------------------------------
void dangerApp::draw(){
	
	//fbo.clear();
	fbo->clear(0,0,0,0);
	ofBackground(0, 0, 0);
	ofSetColor(255, 255, 255);
	fbo->begin();
	ofSetColor(255, 255, 255);
	ofEnableAlphaBlending();
	scene.draw();
	if(oscDebugEnabled)oscReceiver.debugDraw();
	ofDisableAlphaBlending();
	fbo->end();
	
	
	
	ofSetColor(255, 255, 255);
	debugView.draw();
	
	//fbo.draw(0, 0, 320, 240);
	
	
	ofxFBOTexture * sceneFbo =  sceneEffects.draw(fbo, screen1Size.x,0);
	debugView.drawSceneFbo(sceneFbo, screen1Size.x * .5, screen1Size.y * .5);
	
	
	
}

//--------------------------------------------------------------
void dangerApp::keyPressed(int key){
	
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
			MSA::ofxCocoa::setSyncToDisplayLink(false);
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
		case 63235:
			scene.fade();
			break;
			
		case 'o':
			oscReceiver.setup();
			break;
			
		case 'g':
			oscDebugEnabled = !oscDebugEnabled;
			break;
			
		case 'h':
			MSA::ofxCocoa::setSyncToDisplayLink(true);
			break;
			
		default:
			break;
	}
	
	
	
}

void dangerApp::onBeatEvent(int & f){
	
	scene.onBeatEvent();
	debugView.onBeatEvent();
}

void dangerApp::onOscEvent(customOscMessage & f ) {
	scene.onOscEvent(f);
	
}

void dangerApp::reset () {
	builder.setup(ofToDataPath("components.xml"));
	data.clean();
	data.setup();
	data.addSceneObjects(builder);
}


//--------------------------------------------------------------
void dangerApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void dangerApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void dangerApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void dangerApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void dangerApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void dangerApp::windowResized(int w, int h){
	
}

