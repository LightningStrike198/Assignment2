#include "DynamicScene.h"
using namespace GAME;


DynamicScene::DynamicScene(class Window& windowRef, string _filename) : Scene0(windowRef)  {
	trackball = new Trackball();
	projectionMatrix.loadIdentity();
	viewMatrix.loadIdentity();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	filename = _filename;
}

bool DynamicScene::OnCreate() {
	OnResize(windowPtr->GetWidth(), windowPtr->GetHeight());
	lightPos = Vec3(10.0f, 3.0f, 10.0f);
	sceneObjects.createGraphDatafromFile(filename);//Create the scene graph
	return true;

}

void DynamicScene::HandleEvents(const SDL_Event& SDLEvent) {
	if (SDLEvent.type == SDL_EventType::SDL_MOUSEBUTTONDOWN) {
		trackball->OnLeftMouseDown(SDLEvent.button.x, SDLEvent.button.y);
	}
	if (SDLEvent.type == SDL_EventType::SDL_MOUSEMOTION &&
		SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
		trackball->OnMouseMove(SDLEvent.button.x, SDLEvent.button.y);
	}


}

void DynamicScene::Render() const {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	for (auto aPair : sceneObjects.sceneGraph) {//Create loop to cycle through map contents
		aPair.second.SetLightPos(viewMatrix * lightPos);
		aPair.second.Render(projectionMatrix, trackball->GetMatrix4() *  viewMatrix, trackball->GetMatrix3());
	}
	SDL_GL_SwapWindow(windowPtr->getSDLWindow());
}

void DynamicScene::Update(const float deltaTime) {
	for (auto aPair : sceneObjects.sceneGraph) {
		aPair.second.Update(deltaTime);
	}
}

void DynamicScene::OnDestroy() {
	/// Cleanup Assets
	if (trackball) delete trackball;
	trackball = nullptr;
}


void DynamicScene::OnResize(int w_, int h_) {
	windowPtr->SetWindowSize(w_, h_);
	glViewport(0, 0, windowPtr->GetWidth(), windowPtr->GetHeight());
	float aspect = float(windowPtr->GetWidth()) / float(windowPtr->GetHeight());

	projectionMatrix = MMath::perspective(45.0f, aspect, 1.0f, 100.0f);

	viewMatrix = MMath::lookAt(Vec3(0.0f, 0.0f, 10.0f),
		Vec3(0.0f, 0.0f, 0.0f),
		Vec3(0.0f, 1.0f, 0.0f));

}

DynamicScene::~DynamicScene()
{
}
