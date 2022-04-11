#include <iostream>
#include <string>
#include "Headers/additionalMethods.hpp"

//written for MacOS
#include <unistd.h>

//Written by Gregory Keenan to run a simple program to set the exif data for pictures
//It uses exiftool which must be downloaded seperatly. Using Exiftool directly is more 
//simple and effective, but this program is because I will forget the exiftool commands

void introText()
{
	std::cout << "Program to reset Exif Data in picture files" << "\n";
	std::cout << "Written by Gregory Keenan as I will forget the Exif commands" << "\n";
	std::cout << "Please ensure you are in the folder of the pictures you wish to edit" << "\n";
}

void writeExifDatatoAll(std::string *camera, std::string *model, std::string *lens)
{

	//exiftool command I'm making a program for because my memory is rubbish: 
	// exiftool -Make="Olympus" -Model="µ[mju]-i" -Lens="35mm" *.jpg
	//This will write the inputed details to all files in the folder
	
	//std::cout << "Camera Data Passed " << *camera << "\n";
	std::string CombinedOutput;
	std::string CameraArg, ModelArg, LensArg;

	CombinedOutput = "exiftool -Make=\"" + *camera + "\" -Model=\"" + *model + "\" -Lens=\"" + *lens + "\" ./";
	CameraArg = "-Make="+ *camera;
	ModelArg = "-Model="+ *model;
	LensArg=  "-Lens=" + *lens;

	std::cout << "Command being passed to exiftool: " << CombinedOutput << "\n";

	//This is apprently a poor way of calling commands in C++ due to several issues.
	//TODO invistgate if this is correct vs myth
	//std::system(CombinedOutput.c_str());

	execl("/usr/local/bin/exiftool", "exiftool", CameraArg.c_str(), ModelArg.c_str(), LensArg.c_str(), "./", NULL);
	

}

void inputDetails()
{

	std::string camera, model, lens, yn;

	std::cout << "--------------" << "\n";

	std::cout << "Please enter the Camera Make: ";
	std::cin >> camera; 

	std::cout << "Please enter the Camera Model: ";
	std::cin >> model;

	std::cout << "Please enter the Lens used: ";
	std::cin >> lens;

/* 		--MAC OS Specific--
Foreground colour: "\x1b[30m"
Background colour: "\x1b[40m"
Foreground and background: "\x1b[30:40m"
Reset all colour back to normal: "\x1b[0m"
+---------+------------+------------+
|  color  | foreground | background |
|         |    code    |    code    |
+---------+------------+------------+
| black   |     30     |     40     |
| red     |     31     |     41     |
| green   |     32     |     42     |
| yellow  |     33     |     43     |
| blue    |     34     |     44     |
| magenta |     35     |     45     |
| cyan    |     36     |     46     |
| white   |     37     |     47     |
+---------+------------+------------+
*/
	std::cout << "\x1b[31m" << "You have entered: " << "\n" << "\x1b[47m" << "Camera: " << camera << " Model: " << model << " Lens: " << lens << " \x1b[0m \n";

	//std::cout << "\x1b[0m"; //reset text colour to normal
	std::cout << "Is this correct? (Y/N)" << "\n";

	std::cin >> yn;
	
	if(!yn.compare("Y") || !yn.compare("y"))
	{
		std::cout << "Yes\n";
		writeExifDatatoAll(&camera, &model, &lens);

	}
	else if (!yn.compare("N") || !yn.compare("n"))
	{
		std::cout << "No\n";
		inputDetails();
	}

	else
	{
		std::cout << "Please use correct formating: \"Y/y/N/n\" \n";
		inputDetails();
	}

}

int main()
{
	introText();

	std::string input;
	std::cout << "What do you want to do? \n" << "1) Update 35mm Exif data \n" << "2) NUKE/Remove all Exif data \n" << "Please enter your choice: ";
	std::cin >> input;

	if(!input.compare("1"))
	{
		inputDetails();
	} 
	else if (!input.compare("2"))
	{
		totalWipeExifData();
	} else {
		std::cout << "Invalid choice - exiting program" << std::endl;
	}

	return 0;
}