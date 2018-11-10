#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "Model.h"
#include "Shader.h"
#include "ObjLoader.h"

namespace GAME{
	class Primitive : public Model {

	public:
		Primitive(GLenum _drawMode, std::vector<Vec3> &_vertices, std::vector<Vec3> &_normals, std::vector<Vec2> &_uvs);
		Primitive(std::string _filePath);
		virtual ~Primitive();

		Primitive(const Primitive&) = delete;
		Primitive(Primitive&&) = delete;
		Primitive& operator = (const Primitive&) = delete;
		Primitive& operator = (Primitive&&) = delete;

		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Render(const Matrix4& projectionMatrix, const Matrix4& viewMatrix, const Matrix3& normalMatrix)const;
		virtual void Update(const float deltaTime);

	private:

		Shader* shader;
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
#endif PRIMITIVE_H