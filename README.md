ofxCameraSaveLoad
=====================================

Introduction
------------
Simple openFrameworks addon that lets you save and load all the parameters of any ofCamera, ofEasyCam or ofNode object.

Licence
-------
Read the `license.md` file.

Installation
------------
If you download the zip, unzip and put in the `openFrameworks/addons/` folder.
For cloning 

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
Should support v0.10 as well.
To achieve such, in file `ofxCameraSaveLoad/src/ofxCameraSaveLoad.h` uncomment the line that says:

	`#define USE_GLM`


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
* Supports GLM. Which should provide support for OF v0.10


