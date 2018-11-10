#pragma once
#include "Object.h"
#include "RCubeModel.h"

namespace GAME{

class RCubeObject : public Object
{
public:
	RCubeModel *model;

	void Render(const Matrix4& projectionMatrix, const Matrix4& viewMatrix, const Matrix3& normalMatrix) const;
	void SetLightPos(const Vec3& vec3);
	void Update(const float deltaTime);
	void OnDestroy();

	RCubeObject();
	RCubeObject(Vec3 _screenCoords);
	~RCubeObject();
};
}
