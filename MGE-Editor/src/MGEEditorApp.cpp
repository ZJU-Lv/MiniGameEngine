#include <MGE.h>
#include <MGE/Core/EntryPoint.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "EditorLayer.h"

namespace MGE {
	class MGEEditor : public Application
	{
	public:
		MGEEditor()
			: Application("MGE Editor")
		{
			PushLayer(new EditorLayer());
		}

		~MGEEditor()
		{

		}
	};

	MGE::Application* createApplication()
	{
		return new MGEEditor();
	}
}