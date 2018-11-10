#pragma once
#include "Model0.h"

namespace GAME {


class Object
{
public:
	Vec3 screenCoords;
	
	
	virtual void Render(const Matrix4& projectionMatrix, const Matrix4& viewMatrix, const Matrix3& normalMatrix) const;
	virtual void SetLightPos(const Vec3& vec3);
	virtual void Update(const float deltatime);

	Object();
	Object(Vec3 _screenCoords);
	~Object();
};
}
