#include "RCubeObject.h"
using namespace GAME;


RCubeObject::RCubeObject()
{
}

RCubeObject::RCubeObject(Vec3 _screenCoords)
{
	screenCoords = _screenCoords;
	model = new RCubeModel();
	model->OnCreate();
	model->SetPos(screenCoords);
}

//Object needs its own Render function, otherwise it won't work in DynamicScene
void RCubeObject::Render(const Matrix4& projectionMatrix, const Matrix4& viewMatrix, const Matrix3& normalMatrix) const {
	model->Render(projectionMatrix, viewMatrix, normalMatrix);
}

void RCubeObject::SetLightPos(const Vec3& vec3) {
	model->SetLightPos(vec3);
}

void RCubeObject::Update(const float deltatime) {
	model->Update(deltatime);
}



void RCubeObject::OnDestroy() {
	delete model;
	model = nullptr;
}

RCubeObject::~RCubeObject()
{
	OnDestroy();
}
