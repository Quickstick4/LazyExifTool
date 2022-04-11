//Wiping Exif data module
//Written by Gregory Keenan
//This will remove all Exif data from the photo (i.e. nuke it)

#include <iostream>
#include <string>
#include "Headers/additionalMethods.hpp"

//written for MacOS
#include <unistd.h>

void totalWipeExifData()
{

	std::cout << "\x1b[41m\n";
	std::cout << "\x1b[37m Data Nuke Mode\n\n\n"; //endl right now as this is all that happens in this function right now. 
	std::cout << "Are you sure? \n - THIS WILL APPLY TO ALL PICTURE TYPE FILES IN THE CURRENT FOLDER AND SUB-FOLDERS YOU ARE CURRENTLY IN -\n \n";
	std::cout << "Type YES or n: ";

	std::string input;

	std::cin >> input;

	if(!input.compare("YES"))
	{
		std::cout << "\x1b[0m\n";
		std::cout << "Command being sent to exitool: exiftool -all:all= -r ./ \n";
		execl("/usr/local/bin/exiftool", "exiftool", "-all:all=", "-r" , "./", NULL);
		
	}
	else if (!input.compare("N") || !input.compare("n"))
	{
		std::cout << "\x1b[0m\n";
		std::cout << "Exiting Nuke mode\n";
		std::cout << std::endl;  
		main();
	}
	else 
	{
		std::cout << "\x1b[0m";
		std::cout << "You must type \"YES\" exactly to nuke or \"N/n\" - not taking chances here";
		std::cout << std::endl;  
	}
}