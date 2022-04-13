# LazyExifTool
Simple C++ program as I keep forgetting ExifTool comands.

Only sets:

* Camera Make
* Camera Model
* Lens

Or removes all Exif data (not required for image)

These are the only settings I currently wish to change as it fixes the scanner data being used with 35mm film scans or if I share the photos.

You must have the ExifTool program installed from here: https://exiftool.org/

N.B. If you have stumbled here by accident, please note:
* This is just a simple program to enable my lazyness
* Only fully supports MacOS at present, works in Linux in certain (most) configs
* Assumes Exiftool is installed at /usr/local/bin/