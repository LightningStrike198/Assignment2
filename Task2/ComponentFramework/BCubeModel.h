#pragma once
#include "Model0.h"
#include "Shader.h"
#include "ObjLoader.h"
#include "Mesh.h"

namespace GAME {


class BCubeModel : public Model0
{
public:
	BCubeModel(const BCubeModel&) = delete;
	BCubeModel(BCubeModel&&) = delete;
	BCubeModel& operator = (const BCubeModel&) = delete;
	BCubeModel& operator = (BCubeModel&&) = delete;

	bool OnCreate();
	void Render(const Matrix4& projectionMatrix, const Matrix4& viewMatrix, const Matrix3& normalMatrix) const;

	BCubeModel();
	~BCubeModel();

private:

	Shader * shader;
	GLuint vbo;
	GLuint vao;
	GLint verticiesID;
	GLint normalsID;
	GLint uvCoordsID;

	GLint projectionMatrixID;
	GLint modelViewMatrixID;
	GLint normalMatrixID;
	GLint lightPosID;
	Vec3 lightPos;
};
}
