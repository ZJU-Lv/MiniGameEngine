#include "Core.h"

namespace MGE {
	class MGE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* createApplication();
}
