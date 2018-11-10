#pragma once
#include "Object.h"
#include "BCubeModel.h"

namespace GAME{

class BCubeObject : public Object {

public:
	BCubeModel *model;

	void Render(const Matrix4& projectionMatrix, const Matrix4& viewMatrix, const Matrix3& normalMatrix) const;
	void SetLightPos(const Vec3& vec3);
	void Update(const float deltaTime);
	void OnDestroy();

	BCubeObject();
	BCubeObject(Vec3 _screenCoords);
	~BCubeObject();
};
}
