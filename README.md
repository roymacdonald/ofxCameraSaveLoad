ofxCameraSaveLoad
=====================================

Introduction
------------
Simple openFrameworks addon that lets yo save and load all the parameters of any ofCamera or ofEasyCam object.

Licence
-------
Read the `license.md` file.

Installation
------------
Just copy into the `openFrameworks/addons/` folder.

Dependencies
------------
None

Compatibility
------------
0073
probably 0072 should also work (not tested).
Yet I recommend using the latest develop version of openFrameworks.


Known issues
------------
When not using the latest version of OFs develop branch  there are to getter methods missing in ofCamera, so Is not possible to save the entire camera status.
this getters are for forceAspectRatio and aspectRatio. In this case you must comment this line from ofxCameraSaveLoad.h `#define USE_DEVELOP_BRANCH`



Version history
------------

### Version 0.1 (Date):
First version.


