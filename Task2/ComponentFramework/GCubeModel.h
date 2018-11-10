#include "Model0.h"
#include "Shader.h"

#include "ObjLoader.h"
#include "Mesh.h"

namespace GAME {


	class GCubeModel : public Model0
	{
	public:
		GCubeModel(const GCubeModel&) = delete;
		GCubeModel(GCubeModel&&) = delete;
		GCubeModel& operator = (const GCubeModel&) = delete;
		GCubeModel& operator = (GCubeModel&&) = delete;

		bool OnCreate();
		

		GCubeModel();
		~GCubeModel();

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


