#include "RCubeModel.h"
#include "QuadSphere.h"

using namespace GAME;


RCubeModel::RCubeModel()
{
	OnCreate();
}

bool RCubeModel::OnCreate()
{
	ObjLoader obj("RCube.obj");

	meshes.push_back(new Mesh(GL_LINE_LOOP, obj.vertices, obj.normals, obj.uvCoords));

	/// Create a shader with attributes
	shader = new Shader("phongVert.glsl", "phongFrag.glsl", 3, 0, "vVertex", 1, "vNormal", 2, "texCoords");

	projectionMatrixID = glGetUniformLocation(shader->getProgram(), "projectionMatrix");
	modelViewMatrixID = glGetUniformLocation(shader->getProgram(), "modelViewMatrix");
	normalMatrixID = glGetUniformLocation(shader->getProgram(), "normalMatrix");
	lightPosID = glGetUniformLocation(shader->getProgram(), "lightPos");
	modelMatrix = MMath::translate(0.0f, 0.3f, 0.0f);
	return true;
}

RCubeModel::~RCubeModel()
{
}
