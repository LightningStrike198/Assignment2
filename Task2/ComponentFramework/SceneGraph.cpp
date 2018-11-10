#include "SceneGraph.h"
using namespace GAME;


enum ObjectChoices { RED_CUBE, BLUE_CUBE, GREEN_CUBE };
ObjectChoices convert(const std::string& string) {
	if (string == "Red") {
		return RED_CUBE;
	}
	else if (string == "Blue") {
		return BLUE_CUBE;
	}
	else if (string == "Green") {
		return GREEN_CUBE;
	}
}

SceneGraph::SceneGraph()
{
}

void SceneGraph::createGraphDatafromFile(string filename) {
	fileReader.getFileInfo(filename); //Use the filereader to get the data

	//Variables to be used in the loop
	auto it = fileReader.fileInfo.begin();
	int i = 1;
	Object sceneObject;

	for (auto aPair : fileReader.fileInfo) { //Create the loop that goes through the map from the file

		ObjectChoices objectType = convert(aPair.first); //Take the string from the file and turn it into an enum for the switch statement

		//Switch statement that creates an object based on what the file tells it
		switch (objectType) {
		case RED_CUBE:
			sceneObject = RCubeObject(aPair.second);
			break;
		case BLUE_CUBE:
			sceneObject = BCubeObject(aPair.second);
			break;
		case GREEN_CUBE:
			sceneObject = GCubeObject(aPair.second);
			break;
		}

		sceneGraph.insert(std::make_pair(i, sceneObject)); //Put the object into the map along with the key
		i++;

	}
}

SceneGraph::~SceneGraph()
{
}


