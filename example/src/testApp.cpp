#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
    ofxLoadCamera(cam, "ofEasyCamSettings");
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
	ofDrawBox(30);
	ofNoFill();
	ofSetColor(0);
	ofDrawBox(30);
	
	ofPushMatrix();
	ofTranslate(0,0,20);
	ofSetColor(0,0,255);
	ofFill();
	ofDrawBox(5);
	ofNoFill();
	ofSetColor(0);
	ofDrawBox(5);
	ofPopMatrix();
	cam.end();
	
	ofSetColor(255);
    ofDrawBitmapStringHighlight("press key:\n\'s\' to save camera.\n\'l\' to load", 50, 50);
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch(key) {
		case 'F':
		case 'f':
			ofToggleFullscreen();
			break;
        case 's':
            ofxSaveCamera(cam, "ofEasyCamSettings");
            break;
        case 'r':
            cam.reset();
            cam.setLensOffset(ofVec2f());
            cam.setForceAspectRatio(false);
            break;
        case 'l':
            ofxLoadCamera(cam, "ofEasyCamSettings");
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
