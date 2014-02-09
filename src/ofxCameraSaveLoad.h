#include "ofMain.h"

#define USE_DEVELOP_BRANCH

bool ofxSaveCamera(ofCamera &cam, string savePath);
bool ofxLoadCamera(ofCamera &cam, string loadPath);
bool ofxSaveCamera(ofEasyCam &cam, string savePath);
bool ofxLoadCamera(ofEasyCam &cam, string loadPath);
bool ofxSaveCamera(ofNode &node, string savePath);
bool ofxLoadCamera(ofNode &node, string loadPath);