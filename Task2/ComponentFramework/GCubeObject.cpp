#include "GCubeObject.h"
using namespace GAME;


GCubeObject::GCubeObject()
{
}

GCubeObject::GCubeObject(Vec3 _screenCoords)
{
	screenCoords = _screenCoords;
	model = new GCubeModel();
	model->OnCreate();
	model->SetPos(screenCoords);
	model->SetVel(Vec3(0, 0, 0));
}

//Object needs its own Render function, otherwise it won't work in DynamicScene
void GCubeObject::Render(const Matrix4& projectionMatrix, const Matrix4& viewMatrix, const Matrix3& normalMatrix) const {
	model->Render(projectionMatrix, viewMatrix, normalMatrix);
}

void GCubeObject::SetLightPos(const Vec3& vec3) {
	model->SetLightPos(vec3);
}

void GCubeObject::Update(const float deltatime) {
	model->Update(deltatime);
}




void GCubeObject::OnDestroy() {
	delete model;
	model = nullptr;
}

GCubeObject::~GCubeObject()
{
	OnDestroy();
}
