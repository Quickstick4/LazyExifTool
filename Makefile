#Saves/execute commands if a, b, c is newer than x
#e.g. x: a, b, c
#	do this

LazyExif: exif-program.o wipe.o
	g++ -o LazyExif exif-program.o wipe.o

exif-program.o: exif-program.cpp Headers/additionalMethods.hpp
	g++ -c exif-program.cpp

wipe.o: wipe.cpp Headers/additionalMethods.hpp
	g++ -c wipe.cpp