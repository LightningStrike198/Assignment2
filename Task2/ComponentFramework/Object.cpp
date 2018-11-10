#include "Object.h"
using namespace GAME;


Object::Object()
{
}

Object::Object(Vec3 _screenCoords) {
	screenCoords = _screenCoords;
}

void Object::Render(const Matrix4& projectionMatrix, const Matrix4& viewMatrix, const Matrix3& normalMatrix) const{

}

void Object::SetLightPos(const Vec3& vec3) {

}

void Object::Update(const float deltatime) {

}

Object::~Object()
{
}
