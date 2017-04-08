#include "ofMain.h"

//#define USE_GLM //glm is being used in OF v0.10 onwards. 
//#define PRINT_DEBUG //uncomment this line to print the values as these are saved or loaded.

bool ofxSaveCamera(const ofCamera &cam, string savePath);
bool ofxLoadCamera(ofCamera &cam, string loadPath);
bool ofxSaveCamera(const ofEasyCam &cam, string savePath);
bool ofxLoadCamera(ofEasyCam &cam, string loadPath);
bool ofxSaveCamera(const ofNode &node, string savePath);
bool ofxLoadCamera(ofNode &node, string loadPath);