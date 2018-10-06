ofxCameraSaveLoad
=====================================

Introduction
------------
Simple openFrameworks addon that lets you save and load all the parameters of any ofCamera, ofEasyCam or ofNode object.

Usage
-----
The API of this addon is extremelly simple and it just consists of a few functions.
First, remember to include this addon either in the .h or .cpp file in which you wish to use it.
`#include "ofxCameraSaveLoad.h"`

Then for saving call
	
	bool ofxSaveCamera(const ofCamera &cam, string savePath);
	bool ofxSaveCamera(const ofEasyCam &cam, string savePath);
	bool ofxSaveCamera(const ofNode &node, string savePath);
	
Where you pass the camera or ofNode object that you want to save, and the directory where it is going to be saved

Loading is quite much the same.

    bool ofxLoadCamera(ofEasyCam &cam, string loadPath);
    bool ofxLoadCamera(ofCamera &cam, string loadPath);
    bool ofxLoadCamera(ofNode &node, string loadPath);






Licence
-------
Read the `license.md` file.

Installation
------------
If you download the zip, unzip and put in the `openFrameworks/addons/` folder.
For cloning, in terminal run:

    cd <your/openframeworks/folder>/addons
    git clone git@github.com:roymacdonald/ofxCameraSaveLoad.git

Dependencies
------------
None

Compatibility
------------
* v1  
	0073  
	0072 should also work (not tested).

* v2   
	version 0.9.8 onwards.
	Automatically supports v0.10 as well (and GLM) through preprocessor macro.


Known issues
------------
none for current version.



Version history
------------

### Version 1 (~2013):
First version.
### Version 2 (4/7/2017):
Updated for OF v0.9.8    

* Simplified the whole loading and saving mechanism. 
* Old saved files should still work.
* Updated example
* Support for OF v0.10 (unreleased yet)
* Supports GLM on v0.10 

### Version 3 (6/10/2018):
Updated for openFrameworks v0.10

