#pragma once
#include "Object.h"
#include "GCubeModel.h"

namespace GAME{
class GCubeObject : public Object
{
public:
	GCubeModel *model;

	void Render(const Matrix4& projectionMatrix, const Matrix4& viewMatrix, const Matrix3& normalMatrix) const;
	void SetLightPos(const Vec3& vec3);
	void Update(const float deltaTime);
	void OnDestroy();

	GCubeObject();
	GCubeObject(Vec3 _screenCoords);
	~GCubeObject();
};
}
