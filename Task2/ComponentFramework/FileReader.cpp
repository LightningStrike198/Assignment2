#include "FileReader.h"



FileReader::FileReader()
{
}

void FileReader::getFileInfo(string filename) {
	fileReader.open(filename);
	string line;

	//Set the data in the file to the variables
	//Have to do the first line outside the loop, otherwise it gets skipped for some reason
	fileReader >> line;
	fileReader >> x;
	fileReader >> y;
	fileReader >> z;

	Vec3 vec(x, y, z); //Create a vector to put into the map
	fileInfo.insert(std::make_pair(line, vec));//Put the data into the map

	//Loop that gets each line of the file and puts the data into the map
	while (std::getline(fileReader, line)) {
		fileReader >> line;
		fileReader >> x;
		fileReader >> y;
		fileReader >> z;
		vec = Vec3(x, y, z);
		fileInfo.insert(std::make_pair(line, vec));
		
	}
}


FileReader::~FileReader()
{
}
