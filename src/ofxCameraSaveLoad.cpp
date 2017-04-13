#include "ofxCameraSaveLoad.h"

#ifdef USE_GLM
typedef glm::vec3 v3 ;
typedef glm::vec2 v2;
typedef glm::quat qq;
#else
typedef ofVec3f v3;
typedef ofVec2f v2;
typedef ofQuaternion qq;
#endif
//----------------------------------------
template<class T>
T readValue(const string& valueName, ofBuffer& buffer, T val){
	for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
		if (!it->empty()) {
			if ((string)(*it) == valueName) {
				it++;
				if (it != end) {
					istringstream iss;
					iss.str((string)(*it));
					iss >> val;
#ifdef PRINT_DEBUG
					cout << "readValue " << valueName << " : " << *it << endl;
#endif
					return val;
				}
			}
		}
	}
	return val;
}
//----------------------------------------
template<class T>
void writeValue(const string& valueName, const T& val, ofBuffer& buffer){
	buffer.append(valueName + "\n"+ ofToString(val) + "\n");
	
#ifdef PRINT_DEBUG
	cout << "writeValue " << valueName << " : "+ ofToString(val) <<endl;
#endif
}
//----------------------------------------
static bool saveBuffer(const string& savePath, ofBuffer& buffer){
	if(ofBufferToFile(savePath, buffer)){
		ofLogNotice("[ofxCameraSaveLoad] : File " + savePath + " saved successfully!");
		return true;
	}else{
		ofLogWarning("[ofxCameraSaveLoad] : File " + savePath + " failed to save!");
		return false;
	}
}
//----------------------------------------
static bool loadBuffer(const string& loadPath, ofBuffer& buffer){
	ofFile file(loadPath);
	if(!file.exists()){
		ofLogError("[ofxCameraSaveLoad] : File " + loadPath + " is missing!");
		return false;
	}
	buffer = ofBufferFromFile(loadPath);
	if(buffer.size() == 0){
		ofLogNotice("[ofxCameraSaveLoad] : File " + loadPath + " is empty!");
		return false;
	}
	return true;
}
//----------------------------------------
static void saveOfNode(const ofNode &node, ofBuffer& buffer){
	buffer.append("--------------ofNode parameters--------------\n");
	writeValue<v3>("position", node.getPosition(), buffer);
	writeValue<v3>("scale",node.getScale(), buffer);
	writeValue<qq>("orientation", node.getOrientationQuat(),buffer);
}
//----------------------------------------
static void loadOfNode(ofNode &node, ofBuffer& buffer){
	node.setPosition(readValue<v3>("position", buffer, node.getPosition()));
	node.setScale(readValue<v3>("scale",buffer, node.getScale()));
	node.setOrientation(readValue<qq>("orientation", buffer, node.getOrientationQuat()));
}
//----------------------------------------
static void saveOfCam(const ofCamera &cam, ofBuffer& buffer){
	saveOfNode(cam, buffer);
	buffer.append("--------------ofCamera parameters--------------\n");
	writeValue<float>("fov",cam.getFov(),buffer);
	writeValue<float>("near", cam.getNearClip(),buffer);
	writeValue<float>("far", cam.getFarClip(),buffer);
	writeValue<v2>("lensOffset", cam.getLensOffset(),buffer);
	writeValue<bool>("forceAspectRatio", cam.getForceAspectRatio(),buffer);
	writeValue<float>("aspectRatio", cam.getAspectRatio(),buffer);
	writeValue<bool>("isOrtho",cam.getOrtho(),buffer);
	writeValue<bool>("vFlip", cam.isVFlipped(), buffer);
}
//----------------------------------------
static void loadOfCam(ofCamera &cam, ofBuffer& buffer){
	loadOfNode(cam, buffer);
	cam.setFov(readValue<float>("fov", buffer, cam.getFov()));
	cam.setNearClip(readValue<float>("near",buffer, cam.getNearClip()));
	cam.setFarClip(readValue<float>("far",buffer,cam.getFarClip()));
	cam.setLensOffset(readValue<v2>("lensOffset",buffer, cam.getLensOffset()));
	cam.setForceAspectRatio(readValue<bool>("forceAspectRatio",buffer, cam.getForceAspectRatio()));
	float aspectRatio = readValue<float>("aspectRatio",buffer, cam.getAspectRatio());
	readValue<bool>("isOrtho",buffer, cam.getOrtho())?cam.enableOrtho():cam.disableOrtho();
	cam.setVFlip(readValue<bool>("vFlip", buffer, cam.isVFlipped()));
	if(cam.getForceAspectRatio()){
		cam.setAspectRatio(aspectRatio);
	}
}
//----------------------------------------
#ifdef V010
static void saveEasyCam( const ofEasyCam &cam,  ofBuffer& buffer){
#else
static void saveEasyCam(  ofEasyCam &cam,  ofBuffer& buffer){
#endif
	saveOfCam(cam, buffer);
	buffer.append("--------------ofEasyCam parameters--------------\n");
	writeValue<v3>("target", cam.getTarget().getPosition(),buffer);
	writeValue<bool>("bEnableMouseMiddleButton", cam.getMouseMiddleButtonEnabled(), buffer);
	writeValue<bool>("bMouseInputEnabled", cam.getMouseInputEnabled(), buffer);
	writeValue<float>("drag", cam.getDrag(), buffer);
	writeValue<char>("doTranslationKey", cam.getTranslationKey(), buffer);
#ifdef V010
	writeValue<bool>("relativeYAxis", cam.getRelativeYAxis(), buffer);
	writeValue<bool>("doInertia", cam.getInertiaEnabled(), buffer);
	writeValue<v3>("upAxis", cam.getUpAxis(),buffer);
	writeValue<ofRectangle>("controlArea", cam.getControlArea(), buffer);
#endif
}
//----------------------------------------
static void loadEasyCam(ofEasyCam & cam, ofBuffer& buffer){

	cam.setAutoDistance(false);
	cam.setTarget(readValue<v3>("target",buffer,cam.getTarget().getPosition()));
	loadOfCam(cam, buffer);
	cam.setDrag(readValue<float>("drag",buffer,cam.getDrag()));
	readValue<bool>("bEnableMouseMiddleButton",buffer,cam.getMouseMiddleButtonEnabled())?cam.enableMouseMiddleButton():cam.disableMouseMiddleButton();
	readValue<bool>("bMouseInputEnabled",buffer,cam.getMouseInputEnabled())?cam.enableMouseInput():cam.disableMouseInput();
	cam.setTranslationKey(readValue<char>("doTranslationKey",buffer,cam.getTranslationKey()));
#ifdef V010
	cam.setRelativeYAxis(readValue<bool>("relativeYAxis", buffer, cam.getRelativeYAxis()));
	readValue<bool>("doInertia", buffer, cam.getInertiaEnabled())?cam.enableInertia():cam.disableInertia();
	cam.setUpAxis(readValue<v3>("upAxis", buffer, cam.getUpAxis()));
	cam.setControlArea(readValue<ofRectangle>("controlArea", buffer, cam.getControlArea()));
#endif
}
//----------------------------------------
bool ofxSaveCamera(const ofNode &node, string savePath){
	ofBuffer buffer;
	saveOfNode(node, buffer);
	return saveBuffer(savePath, buffer);
}
//----------------------------------------
bool ofxLoadCamera(ofNode &node, string loadPath){
	ofBuffer buffer;
	if (loadBuffer(loadPath, buffer)) {
		loadOfNode(node, buffer);
		return true;
	}
	return false;
}
//----------------------------------------
bool ofxSaveCamera(const ofCamera &cam, string savePath){
	ofBuffer buffer;
	saveOfCam(cam, buffer);
	return saveBuffer(savePath, buffer);
}
//----------------------------------------
bool ofxLoadCamera(ofCamera & cam, string loadPath){
	ofBuffer buffer;
	if (loadBuffer(loadPath, buffer)) {
		loadOfCam(cam, buffer);
		return true;
	}
	return false;
}
//----------------------------------------
#ifdef V010
bool ofxSaveCamera(const ofEasyCam & cam, string savePath){
#else
bool ofxSaveCamera(ofEasyCam & cam, string savePath){
#endif
	ofBuffer buffer;
	saveEasyCam(cam, buffer);
	return saveBuffer(savePath, buffer);
}
//----------------------------------------
bool ofxLoadCamera(ofEasyCam & cam, string loadPath){
	ofBuffer buffer;
	if (loadBuffer(loadPath, buffer)) {
		loadEasyCam(cam, buffer);
		return true;
	}
	return false;
}

