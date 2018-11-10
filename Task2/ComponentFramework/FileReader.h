#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "VMath.h"

using namespace std;
using namespace MATH;

class FileReader
{
private:
	ifstream fileReader;
	float x, y, z; //Variables to be put into the Vec3 of the map
public:
	std::map<std::string, Vec3> fileInfo; //Map that stores the file's data
	

	void getFileInfo(string filename); //Function that will get file data and put it in the map

	FileReader();
	~FileReader();
};

