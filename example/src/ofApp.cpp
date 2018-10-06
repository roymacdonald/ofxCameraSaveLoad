#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
//    ofxLoadCamera(cam, "ofEasyCamSettings");
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	cam.begin();
	// Begin drawing cubes
#if OF_VERSION_MAJOR>0 || OF_VERSION_MINOR>9
	ofRotateYRad(.5);
	ofRotateYRad(-.5);
#else
	ofRotateY(.5);
	ofRotateY(-.5);
#endif
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
	// End drawing cubes
	cam.end();
	
	ofSetColor(255);
	string msg = "press key:\n";
	msg += "\'s\' : save camera\n";
	msg += "\'l\' : load camera\n";
	msg += "\'r\' : reset camera\n";
	msg += "\'f\' : toggle fullscreen\n";
    ofDrawBitmapStringHighlight(msg, 50, 50);
	
	
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
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
void ofApp::keyReleased(int key){}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){}
