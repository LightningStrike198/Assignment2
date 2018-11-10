#pragma once
#include "Scene0.h"
#include "SceneGraph.h"
#include "Trackball.h"
//#include "Window.h"

namespace GAME {


class DynamicScene : public Scene0
{
public:
	explicit DynamicScene(Window& windowRef, string _filename);//Needs a string as well for file initialization
	~DynamicScene();

	DynamicScene(const DynamicScene&) = delete;
	DynamicScene(DynamicScene &&) = delete;
	DynamicScene& operator=(const DynamicScene &) = delete;
	DynamicScene& operator=(DynamicScene &&) = delete;

	SceneGraph sceneObjects;

	bool OnCreate();
	void OnDestroy();
	void Update(const float deltaTime);
	void Render() const;
	void HandleEvents(const SDL_Event &SDLEvent);
	void OnResize(const int, const int);

	

private:
	Vec3 lightPos;
	Trackball *trackball;
	string filename;

};
}
