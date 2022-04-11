#LazyExif: exif-program.cpp wipe.cpp
#	g++ -o LazyExif exif-program.cpp wipe.cpp

LazyExif: exif-program.o wipe.o
	g++ -o LazyExif exif-program.o wipe.o

exif-program.o: exif-program.cpp Headers/additionalMethods.hpp
	g++ -c exif-program.cpp

wipe.o: wipe.cpp Headers/additionalMethods.hpp
	g++ -c wipe.cpp