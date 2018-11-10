#include "BCubeObject.h"
using namespace GAME;


BCubeObject::BCubeObject()
{
}

BCubeObject::BCubeObject(Vec3 _screenCoords)
{
	screenCoords = _screenCoords;
	model = new BCubeModel();
	model->OnCreate();
	model->SetPos(screenCoords);
	model->SetVel(Vec3(0, 0, 0));
}

//Object needs its own Render function, otherwise it won't work in DynamicScene
void BCubeObject::Render(const Matrix4& projectionMatrix, const Matrix4& viewMatrix, const Matrix3& normalMatrix) const {
	model->Render(projectionMatrix, viewMatrix, normalMatrix);
}

void BCubeObject::SetLightPos(const Vec3& vec3) {
	model->SetLightPos(vec3);
}

void BCubeObject::Update(const float deltatime) {
	model->Update(deltatime);
}

void BCubeObject::OnDestroy() {
	delete model;
	model = nullptr;
}

BCubeObject::~BCubeObject()
{
	OnDestroy();
}
