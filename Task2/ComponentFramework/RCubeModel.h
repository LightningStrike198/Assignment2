#include "Model0.h"
#include "Shader.h"
#include "ObjLoader.h"
#include "Mesh.h"

namespace GAME {


	class RCubeModel : public Model0
	{
	public:
		RCubeModel(const RCubeModel&) = delete;
		RCubeModel(RCubeModel&&) = delete;
		RCubeModel& operator = (const RCubeModel&) = delete;
		RCubeModel& operator = (RCubeModel&&) = delete;

		bool OnCreate();

		RCubeModel();
		~RCubeModel();

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
