/*#include <iostream>
#include <fstream>
#include <map>
#include <string>*/
#include "FileReader.h"
#include "BCubeObject.h"
#include "RCubeObject.h"
#include "GCubeObject.h"

namespace GAME {

	


class SceneGraph
{
private:
	FileReader fileReader;
public:
	std::map<int, Object> sceneGraph;

	void createGraphDatafromFile(string filename);

	SceneGraph();
	~SceneGraph();
};
}
