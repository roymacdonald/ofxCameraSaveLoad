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
0073 onwards

Known issues
------------
Works, yet there are a few parameter that cant be saved because there are no accessors implemented in the core.
This are:
bool ofCamera::forceAspectRatio
float ofCamera::aspectRatio
bool ofEasyCam::bAutoDistance

Version history
------------

### Version 0.1 (Date):
First version.


