#include <MGE.h>
#include <MGE/Core/EntryPoint.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "EditorLayer.h"

namespace MGE {
	class MGEEditor : public Application
	{
	public:
		MGEEditor(ApplicationCommandLineArgs args)
			: Application("MGE Editor", args)
		{
			PushLayer(new EditorLayer());
		}

		~MGEEditor()
		{

		}
	};

	MGE::Application* createApplication(ApplicationCommandLineArgs args)
	{
		return new MGEEditor(args);
	}
}