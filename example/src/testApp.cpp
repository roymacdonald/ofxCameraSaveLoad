#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
    glEnable(GL_DEPTH_TEST);
	cam.setDistance(100);
    cam.setLensOffset(ofVec2f(1, 0));
    cam.setAspectRatio(1);
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	cam.begin();		
	ofRotateX(ofRadToDeg(.5));
	ofRotateY(ofRadToDeg(-.5));
	
	ofBackground(0);
	
	ofSetColor(255,0,0);
	ofFill();
	ofBox(30);
	ofNoFill();
	ofSetColor(0);
	ofBox(30);
	
	ofPushMatrix();
	ofTranslate(0,0,20);
	ofSetColor(0,0,255);
	ofFill();
	ofBox(5);
	ofNoFill();
	ofSetColor(0);
	ofBox(5);
	ofPopMatrix();
	cam.end();
	ofSetColor(255);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch(key) {
		case 'F':
		case 'f':
			ofToggleFullscreen();
			break;
        case 's':
            ofxSaveCamera(cam, "camaraSettings");
            break;
        case 'r':
            cam.reset();
            cam.setLensOffset(ofVec2f());
            cam.setForceAspectRatio(false);
            break;
        case 'l':
            ofxLoadCamera(cam, "camaraSettings");
            break;
	}
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){}
//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){}
//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){}
//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){}
//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){}
