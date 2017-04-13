#include "ofMain.h"
#if OF_VERSION_MAJOR>0 || OF_VERSION_MINOR>9
#define V010
#define USE_GLM //glm is being used in OF v0.10 onwards.
#endif

//#define PRINT_DEBUG //uncomment this line to print the values as these are saved or loaded.

bool ofxSaveCamera(const ofCamera &cam, string savePath);
bool ofxLoadCamera(ofCamera &cam, string loadPath);
#ifdef V010
bool ofxSaveCamera(const ofEasyCam &cam, string savePath);
#else
bool ofxSaveCamera(ofEasyCam &cam, string savePath);
#endif
bool ofxLoadCamera(ofEasyCam &cam, string loadPath);
bool ofxSaveCamera(const ofNode &node, string savePath);
bool ofxLoadCamera(ofNode &node, string loadPath);
