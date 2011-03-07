/*
 *  shaderBlur.cpp
 *  openFrameworks
 *
 *  Created by theo on 17/10/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "shaderBlur.h"

//--------------------------------------------------------------
void shaderBlur::setup(int fboW, int fboH){	
	
	
	
	fbo1 = new ofxFBOTexture();
	fbo1->allocate(fboW, fboH, GL_RGBA);
	fbo1->clear(0,0,0,0);
	
	fbo2 = new ofxFBOTexture();
	fbo2->allocate(fboW, fboH, GL_RGBA);
	fbo2->clear(0,0,0,0);
	
		
	shaderH.loadShader("shaders/simpleBlurHorizontal");
	shaderV.loadShader("shaders/simpleBlurVertical");

	noPasses = 1;
	blurDistance = 1.0;
	blurPct = 0.0;
}

//--------------------------------------------------------------
void shaderBlur::beginRender(){
	//fbo1->clear(0,0,0,0);
	fbo1->begin();
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA); 
}

//--------------------------------------------------------------
void shaderBlur::endRender(){
	fbo1->end();
	glDisable(GL_BLEND);
}

//--------------------------------------------------------------
void shaderBlur::setBlurParams(int numPasses, float blurDist){
	noPasses		= ofClamp(numPasses, 1, 100000);
	blurDistance	= blurDist;
}

ofxFBOTexture * shaderBlur::getFboReference() {
	return fbo1;
}

//--------------------------------------------------------------
ofxFBOTexture * shaderBlur::getFbo(float x, float y, float w, float h, bool useShader){
	
	ofxFBOTexture * src, * dst;
	src = fbo1;
	dst = fbo2;
	
	if ( blurPct*blurDistance <= 0.0 ) {
		useShader = false; 
	} else {
		useShader = true; 
	
	}
	
	
	
	if( useShader ){
				
		for(int i = 0; i < noPasses; i++){
			//float blurPer =  blurDistance * ofMap(i, 0, noPasses, 1.0/noPasses, 1.0);
			
			
			
			
			//first the horizontal shader 
			shaderH.setShaderActive(true);
			shaderH.setUniformVariable1f("blurAmnt", blurDistance*blurPct);
			
			//dst->clear(0,0,0,0);
			dst->begin();
			glEnable(GL_BLEND);
			glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA); 
			src->draw(0, 0);
			glDisable(GL_BLEND);
			dst->end();
			
			
			shaderH.setShaderActive(false);
			
			//now the vertical shader
			shaderV.setShaderActive(true);	
			shaderV.setUniformVariable1f("blurAmnt", blurDistance*blurPct);
			
			//src->clear(0, 0, 0, 0);
			src->begin();
			glEnable(GL_BLEND);
			glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA); 
			dst->draw(0,0);
			glDisable(GL_BLEND);
			src->end();
			
			shaderV.setShaderActive(false);
			 
			//printf("woks");
			
		}		
		
	}
	
	//ofEnableAlphaBlending();	
	//ofSetColor(255, 255, 255, 255);
	return src;

}



