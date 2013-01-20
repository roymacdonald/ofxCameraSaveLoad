#include "ofxCameraSaveLoad.h"

//----------------------------------------
static bool saveOfCam(ofCamera &cam, string savePath){
    ofBuffer buffer;
    buffer.append("--------------ofCamera parameters--------------\n");
    buffer.append("transformMatrix\n" + ofToString(cam.getGlobalTransformMatrix()) + "\n" );
    buffer.append("fov\n" + ofToString(cam.getFov())+"\n");
    buffer.append("near\n" + ofToString(cam.getNearClip())+"\n");
    buffer.append("far\n" + ofToString(cam.getFarClip())+"\n");
    buffer.append("lensOffset\n" + ofToString(cam.getLensOffset())+"\n");
    //buffer.append("forceAspectRatio\n" + ofToString(cam.forceAspectRatio)+"\n");
    //buffer.append("aspectRatio\n" + ofToString(cam.aspectRatio) + "\n");
    buffer.append("isOrtho\n" + ofToString(cam.getOrtho()) + "\n");
    
    if(ofBufferToFile(savePath, buffer)){
        ofLogNotice("ofCamera saved successfully!");
        return true;
    }else{
        ofLogWarning("failed to save ofCamera!");
        return false;
    }

}
//----------------------------------------
static bool loadOfCam(ofCamera &cam, string loadPath){
    ofFile file(loadPath);
	
	if(!file.exists()){
		ofLogError("The file " + loadPath + " is missing");
        return false;
	}
	float aRatio;
    bool bForceAspect;
	ofBuffer buffer(file);  
	while (!buffer.isLastLine()) {
		string line = buffer.getNextLine();
        if (line == "transformMatrix") {
            string str =buffer.getNextLine() + "\n";
            str += buffer.getNextLine() + "\n";
            str += buffer.getNextLine() + "\n";
            str += buffer.getNextLine();
            
            ofMatrix4x4 m;
            istringstream iss;
            iss.str(str);
            iss >> m;
            cam.setTransformMatrix(m);
         }else if(line == "fov"){
            cam.setFov(ofToFloat(buffer.getNextLine()));
        }else if(line == "near"){
            cam.setNearClip(ofToFloat(buffer.getNextLine()));
        }else if(line == "far"){
            cam.setFarClip(ofToFloat(buffer.getNextLine()));
        }else if(line == "lensOffset"){
            vector<string> vals = ofSplitString(buffer.getNextLine(), ", ");
            if (vals.size()==2) {
                cam.setLensOffset(ofVec2f(ofToFloat(vals[0]), ofToFloat(vals[1])));
            }
        }else if(line == "forceAspectRatio"){
            bForceAspect = ofToBool(buffer.getNextLine());
            cam.setForceAspectRatio(bForceAspect);
        }else if(line == "aspectRatio"){
            aRatio = ofToFloat(buffer.getNextLine());
        }else if(line == "isOrtho"){
            if(ofToBool(buffer.getNextLine())){
                cam.enableOrtho();
            }else{
                cam.disableOrtho();
            }
        }
	}
    if (bForceAspect){
        cam.setAspectRatio(aRatio);
    }
    
    return true;

}
//----------------------------------------
bool ofxSaveCamera(ofCamera &cam, string savePath){
 return saveOfCam(cam, savePath);
}
//----------------------------------------
bool ofxLoadCamera(ofCamera & cam, string loadPath){
 return loadOfCam(cam, loadPath);
}
//----------------------------------------
bool ofxSaveCamera(ofEasyCam & cam, string savePath){
    
    if(saveOfCam((ofCamera &)cam, savePath)){
        ofBuffer buffer = ofBufferFromFile(savePath);
        
        buffer.append("--------------ofEasyCam parameters--------------\n");
        buffer.append("target\n" + ofToString(cam.getTarget().getPosition()) + "\n" );
        buffer.append("bEnableMouseMiddleButton\n" + ofToString(cam.getMouseMiddleButtonEnabled())+"\n");
        buffer.append("bMouseInputEnabled\n" + ofToString(cam.getMouseInputEnabled())+"\n");
//        buffer.append("bAutoDistance\n" + ofToString(cam.bAutoDistance)+"\n");
        buffer.append("drag\n" + ofToString(cam.getDrag())+"\n");
        buffer.append("doTranslationKey\n" + ofToString(cam.getTranslationKey())+"\n");
        
        if(ofBufferToFile(savePath, buffer)){
            ofLogNotice("ofEasyCam saved successfully!");
            return true;
        }else{
            ofLogWarning("failed to save ofEasyCam!");
            return false;
        }
    }else{
        return false;
    }
}
//----------------------------------------
bool ofxLoadCamera(ofEasyCam & cam, string loadPath){
    if(loadOfCam((ofCamera &)cam, loadPath)){
        ofBuffer buffer = ofBufferFromFile(loadPath);
        
        while (!buffer.isLastLine()) {
            string line = buffer.getNextLine();
            
            if (line == "target") {
                vector<string> vals = ofSplitString(buffer.getNextLine(), ", ");
                if (vals.size()==3) {
                    ofVec3f trgt (ofToFloat(vals[0]), ofToFloat(vals[1]), ofToFloat(vals[2]));
               //      cam.setTarget(trgt);
                }
            }
            else if(line == "drag"){
                cam.setDrag(ofToFloat(buffer.getNextLine()));
            }else if(line == "bEnableMouseMiddleButton"){
                if(ofToBool(buffer.getNextLine())){
                    cam.enableMouseMiddleButton();
                }else{
                    cam.disableMouseMiddleButton();
                }
            }else if(line == "bMouseInputEnabled"){
                if(ofToBool(buffer.getNextLine())){
                    cam.enableMouseInput();
                }else{
                    cam.disableMouseInput();
                }
            }else if(line == "bAutoDistance"){
               //cam.setAutoDistance(ofToBool(
                 buffer.getNextLine();//));
            }else if(line == "doTranslationKey"){
                cam.setTranslationKey(ofToChar(buffer.getNextLine()));
            }
        }
        return true;
    }else {
        return false;
    }
}

