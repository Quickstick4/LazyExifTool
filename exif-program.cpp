#include <stdlib.h>

#include <iostream>
#include <string>

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
	
	std::cout << "Camera Data Passed " << *camera << "\n";
	std::string CombinedOutput;

	CombinedOutput = "exiftool -Make=\"" + *camera + "\" -Model=\"" + *model + "\" -Lens=\"" + *lens + "\" *.jpg";

	std::cout << "Command being passed to exiftool: " << CombinedOutput << "\n";

	system(CombinedOutput.c_str());


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

	std::cout << "You have entered:" << "\n" << "Camera: " << camera << " Model: " << model << " Lens: " << lens << "\n";

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
		std::cout << "Please use correct formating\n";
	}

}

int main()
{
	introText();
	inputDetails();

	



	//system("ls");



	return 0;
}