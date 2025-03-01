#Saves/execute commands if a, b, c is newer than x
#e.g. x: a, b, c
#	do this

#changed program output name for being more lazy
LazyExif: exif-program.o wipe.o
	g++ -o lzexf exif-program.o wipe.o

exif-program.o: exif-program.cpp Headers/additionalMethods.hpp
	g++ -c exif-program.cpp

wipe.o: wipe.cpp Headers/additionalMethods.hpp
	g++ -c wipe.cpp