#include "dangerApp.h"
#include "ofxCocoa.h"


//#define DEBUG_DANGER_MODE
//--------------------------------------------------------------
void dangerApp::setup(){
	
	printf("welcome\n");
	float time = ofGetElapsedTimeMillis();
	
	/* Screen */
	ofSetVerticalSync(true);	
	MSA::ofxCocoa::setSyncToDisplayLink(false);
	ofSetFrameRate(60);
	//ofSetLogLevel(OF_LOG);
   
	screens.setup();
	
	videoData.setup(ofToDataPath("videos.xml"));
		
	/* data */
	builder.setup(ofToDataPath("components.xml"));
	data.setup(builder);
	
	appSettings.setup();
	
	/* scene */
	scene.setup(data, videoData, builder, oscReceiver, sceneEffects);
	
	debugView.setup();
	
	sceneEffects.setup(appSettings);
	//sceneEffects.setEffectByName("bloom");
	
	/* Scene main FBO */
	fbo = new ofxFBOTexture();
	fbo->allocate(1920, 1080, GL_RGB);
	
	/* Midi - OSC */
	oscReceiver.setup();
	ofAddListener(oscReceiver.beatEvent,this,&dangerApp::onBeatEvent);
	ofAddListener(oscReceiver.oscEvent,this,&dangerApp::onOscEvent);
	ofAddListener(oscReceiver.masterSignalEvent,this,&dangerApp::onMasterSignalEvent);
	
	midiListener.setup(scene, sceneEffects);
	midiIn.listPorts();
	midiIn.openPort(0); 
	midiIn.addListener(&midiListener);
	
	oscDebugEnabled = false;
    
    #ifdef DEBUG_DANGER_MODE
	fps.setup(500,25, 120);
    #endif
    
    #ifdef _USE_FENSTER
	fenster->setFPS(24);
	fenster->setBounds(0, 0, screen1Size.x*.5, screen1Size.y*.5);
    #endif
    
	printf("loaded in %f milliseconds \n",  ofGetElapsedTimeMillis() - time);
	
	#ifndef DEBUG_DANGER_MODE
	ofHideCursor();
	#endif

}

//--------------------------------------------------------------
void dangerApp::update(){
	
	oscReceiver.update();
	data.update();
	sceneEffects.update();
	scene.update();
    
    #ifdef DEBUG_DANGER_MODE
	fps.update();
    #endif
}

//--------------------------------------------------------------
void dangerApp::draw(){
	
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
	
		
	sceneFbo =  sceneEffects.draw(fbo, 0,0);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA); 
    
    
    //debugView.draw();
	//debugView.drawSceneFbo(sceneFbo, screen1Size.x, screen1Size.y, 0.5);
	//debugView.drawCurrentVideo(scene.getVideoTexture());
    
	// get screen size
	
	// get Screen
	
    
    float x,y;
    ofxVec2f videoSize = ofxUtils::getSizeRatio( screens.mainScreen.x, screens.mainScreen.y, 1920, 1080, true);
    x = screens.mainScreen.x *.5 - videoSize.x*.5;
    y = screens.mainScreen.y *.5 - videoSize.y*.5;
	
	// printf("screen 2 : %f\n",videoSize.y);
	
	if ( !screens.uniqueScreenMode ) {
		// diff
		ofPushMatrix();
		ofTranslate(0, (screens.mainScreen.y - screens.secondScreen.y ), 0);
		debugView.drawSceneFbo(sceneFbo, screens.secondScreen.x, screens.secondScreen.y, 0.5);
		ofPopMatrix();
		x += screens.secondScreen.x;
		
	} 
	
	//ofPushMatrix();
	sceneFbo->draw( x , y, videoSize.x,videoSize.y);
	//ofPopMatrix();
	
	
	glDisable(GL_BLEND);
	
    
    #ifdef DEBUG_DANGER_MODE
	fps.draw(0,400);
    #endif
	 
	
}


//--------------------------------------------------------------
void dangerApp::keyPressed(int key){
	
	printf("key : %d\n", key);
	
	switch (key) {
			
			case 'r':
			sceneEffects.resetColorSettings();
			break;

			
		case 'f':
			ofToggleFullscreen();
            break;
			
		case 'b':
			//sceneEffects.initBloom();
			break;
			
		case 'n':
			//sceneEffects.quitBloom();
			break;
			
		case 'p':
			//debugView.visible = !debugView.visible;
			break;
	
			
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
			
		#ifdef DEBUG_DANGER_MODE
			
			case 'o':
			scene.setCurrentView((int)ofRandom(0, 12));
			break;
			
            case 'g':
			oscDebugEnabled = !oscDebugEnabled;
			break;
            
            case 116:
            scene.setCurrentView((int)(ofRandom(0,3)));
            break;
			
						
			
			
            
         #endif	
        
					
		case 's' :
			screens.toggleCurrentScreen();
			break;
			
		
			
		case 'h':
			//MSA::ofxCocoa::setSyncToDisplayLink(true);
			break;
		
			
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
	sceneEffects.onMasterSignalEvent(val);
}

void dangerApp::reset () {
	builder.setup(ofToDataPath("components.xml"));
	data.clean();
	scene.clean();
	data.setup(builder);
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

#ifdef _USE_FENSTER
void dangerApp::fensterUpdate(){
}

void dangerApp::fensterDraw(){	
	debugView.draw();
	debugView.drawSceneFbo(sceneFbo, screen1Size.x*.5, screen1Size.y*.5, panelViewScale);
	fbo->draw(0, 0);
}
#endif


