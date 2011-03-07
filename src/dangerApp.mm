#include "dangerApp.h"
#include "ofxCocoa.h"



//--------------------------------------------------------------
void dangerApp::setup(){
	
	printf("welcome\n");
	float time = ofGetElapsedTimeMillis();
		
	
	/* Screen */
	ofSetVerticalSync(true);	
	MSA::ofxCocoa::setSyncToDisplayLink(false);
	ofSetFrameRate(60);
	//ofSetLogLevel(OF_LOG_NONE);
	
	screen1Size = MSA::ofxCocoa::getSizeForScreen(0);
	if ( MSA::ofxCocoa::getNumberOfScreen() > 1 ) {
		screen2Size = MSA::ofxCocoa::getSizeForScreen(1);
	}
	
	#ifdef _USE_FENSTER
	fenster->setFPS(24);
	fenster->setBounds(0, 0, screen1Size.x*.5, screen1Size.y*.5);
	#endif
	
	
	videoData.setup(ofToDataPath("videos.xml"));
		
	/* data */
	builder.setup(ofToDataPath("components.xml"));
	//builder.init();
	data.setup();
	data.addSceneObjects(builder);
	
	
	appSettings.setup();
	
	
	/* scene */
	scene.setup(data, videoData, builder, oscReceiver, sceneEffects);
	
	//debugView.setup();
	
	sceneEffects.setup(appSettings);
	//sceneEffects.setEffectByName("bloom");
	
	/* Scene main FBO */
	fbo = new ofxFBOTexture();
	fbo->allocate(1920, 1080, GL_RGB);
	fbo->clear(0,0,0,0);
	
	oscDebugEnabled = false;
	
	panelViewScale = .5;
	fps.setup(500,25, 120);
	
	
	/* Midi / OSC */
	oscReceiver.setup();
	ofAddListener(oscReceiver.beatEvent,this,&dangerApp::onBeatEvent);
	ofAddListener(oscReceiver.oscEvent,this,&dangerApp::onOscEvent);
	ofAddListener(oscReceiver.masterSignalEvent,this,&dangerApp::onMasterSignalEvent);
	
	
	midiListener.setup(scene, sceneEffects);
	midiIn.listPorts();
	midiIn.openPort(0); 
	midiIn.addListener(&midiListener);
	
	
	masterVariation = 1.0;
	
	printf("loaded in %f milliseconds \n",  ofGetElapsedTimeMillis() - time);

	
	//MSA::ofxCocoa::setSyncToDisplayLink(true);
}

//--------------------------------------------------------------
void dangerApp::update(){
	
	oscReceiver.update();
	data.update();
	sceneEffects.update();
	scene.update();
	fps.update();
}

//--------------------------------------------------------------
void dangerApp::draw(){
	
	
	ofSetupGraphicDefaults();
	
	
	//----------------------------------------------------
	
	//glutFullScreen();

	
	
	
	//fbo.clear();
	fbo->clear(0,0,0,0);
	//ofSetupGraphicDefaults();
	ofBackground(0, 0, 0);
	
	ofSetColor(255, 255, 255);
	fbo->begin();
	ofEnableAlphaBlending();
	scene.draw();
	if(oscDebugEnabled)oscReceiver.debugDraw();
	ofDisableAlphaBlending();
	glPopAttrib();
	fbo->end();
	

	
	ofSetColor(255, 255, 255);
	//debugView.draw();
		
	sceneFbo =  sceneEffects.draw(fbo, 0,0);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA); 
	//debugView.drawSceneFbo(sceneFbo, screen1Size.x, screen1Size.y, panelViewScale);
	//debugView.drawCurrentVideo(scene.getVideoTexture());
	sceneFbo->draw( 0, 0);
	//scene.draw();
	glDisable(GL_BLEND);
	
	//fps.draw(0,0);
	 
	
}


#ifdef _USE_FENSTER
void dangerApp::fensterUpdate(){
	
}

void dangerApp::fensterDraw(){
	
	
	debugView.draw();
	debugView.drawSceneFbo(sceneFbo, screen1Size.x*.5, screen1Size.y*.5, panelViewScale);
	//fbo->draw(0, 0);
}

#endif

//--------------------------------------------------------------
void dangerApp::keyPressed(int key){
	
	printf("key : %d\n", key);
	
	switch (key) {
			
		case 'f':
			ofToggleFullscreen();
			
			//fenster->toggleFullscreen();
			break;
			
		case 'b':
			sceneEffects.initBloom();
			break;
			
		case 'n':
			sceneEffects.quitBloom();
			break;
			
		case 'p':
			//debugView.visible = !debugView.visible;
			break;
			
		#ifdef EDITOR_MODE
		case 'r':
			MSA::ofxCocoa::setSyncToDisplayLink(false);
			reset();
		#endif
			
	
			
		case 63234:
			scene.changeVideoSet(0);
			break;
			
			//down
		case 63233:
			scene.changeVideoSet(1);
			break;
			
			// left
		case 63235:
			scene.changeVideoSet(2);
			break;
			
		case 32:
			scene.setRandomVideo();
			break;
			
		
						
		case 'g':
			oscDebugEnabled = !oscDebugEnabled;
			break;
			
			
					
		
		
			
		case 'h':
			//MSA::ofxCocoa::setSyncToDisplayLink(true);
			break;
		/*
		case 'z':
			panelViewScale -= 0.1;
			if ( panelViewScale < 0 ) panelViewScale = 0;
			break;
			
		case 'x':
			panelViewScale += 0.1;
			
			break;
			 
			*/
			
		default:
			break;
	}
	
	
	
}

void dangerApp::onBeatEvent(int & f){
	
	scene.onBeatEvent();
	data.onBeatEvent();
	debugView.onBeatEvent();
	
	
}

void dangerApp::onOscEvent(customOscMessage & f ) {
	data.onOscEvent(f);
	scene.onOscEvent(f);
	
}

void dangerApp::onMasterSignalEvent(float & val) {
	sceneEffects.onMasterSignalEvent(val * sceneEffects.masterSignalVariation);
}

void dangerApp::reset () {
	builder.setup(ofToDataPath("components.xml"));
	data.clean();
	scene.clean();
	data.setup();
	data.addSceneObjects(builder);
	scene.changeMode(0);
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

