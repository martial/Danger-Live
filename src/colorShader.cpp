/*
 *  colorShader.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 16/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "colorShader.h"


//--------------------------------------------------------------
void colorShader::setup(int fboW, int fboH){	
	
	ofBackground(255,255,255);	
	//ofSetVerticalSync(true);
	
	fbo1.allocate(fboW, fboH, GL_RGBA);
	fbo2.allocate(fboW, fboH, GL_RGBA);
	
	fbo1.clear(0,0,0,0);
	fbo2.clear(0,0,0,0);
	
	
	clrShader.loadShader("shaders/color");
	//shaderV.loadShader("shaders/simpleBlurVertical");
	
	brightness = 1.0;
	saturation = 1.0;
	contrast = 1.0;
	
	saturationPct = 1.0;
	contrastPct = 1.0;
	brightnessPct = 1.0;
	
	
}

//--------------------------------------------------------------
void colorShader::beginRender(){
	fbo1.swapIn();
	fbo1.setupScreenForMe();
}

//--------------------------------------------------------------
void colorShader::endRender(){
	fbo1.swapOut();
	fbo1.setupScreenForThem();
}

//--------------------------------------------------------------
void colorShader::setColorSettings(float brightness, float saturation, float contrast){
	this->brightness = brightness;
	this->saturation = saturation;
	this->contrast = contrast;
	

}

//--------------------------------------------------------------
ofxFBOTexture * colorShader::getTexture(bool useShader){
	
	
	//printf("brightness shader %f\n", brightness );
	
	ofxFBOTexture * src, * dst;
	src = &fbo1;
	dst = &fbo2;
	
	if( useShader ){
		
		
			//float blurPer =  blurDistance * ofMap(i, 0, noPasses, 1.0/noPasses, 1.0);
			
			//first the horizontal shader 
			clrShader.setShaderActive(true);
			clrShader.setUniformVariable1f("brightness", brightness * brightnessPct);
			clrShader.setUniformVariable1f("saturation", saturation * saturationPct);
			clrShader.setUniformVariable1f("contrast", contrast * contrastPct);
			
			dst->swapIn();
			dst->setupScreenForMe();
			ofEnableAlphaBlending();		
			src->draw(0, 0);
			ofDisableAlphaBlending();
			dst->swapOut();
			dst->setupScreenForThem();
			clrShader.setShaderActive(false);
			
		}		
		
	
	
	//ofEnableAlphaBlending();	
	ofSetColor(255, 255, 255, 255);
	//dst->draw(x, y, w, h);	
	return dst;
}
