#include "DynamicSceneBuilder.h"
using namespace GAME;


DynamicSceneBuilder::DynamicSceneBuilder()
{
}

string DynamicSceneBuilder::BuildDynamicScene() {
	string fileChoice;
	std::cout << "What file do you want to load(Options are Blue.txt, Red.txt, or Green.txt)" << std::endl;//Get user input
	cin >> fileChoice; 

	//Make sure they actually type  in a correct file
	if (fileChoice == "Red.txt"|| fileChoice == "Blue.txt" || fileChoice == "Green.txt") {
		return fileChoice;
	}
	else {
		throw std::string("That's not a file that can be used");
	}
}


DynamicSceneBuilder::~DynamicSceneBuilder()
{
}
