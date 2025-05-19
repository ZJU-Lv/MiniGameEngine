#pragma once

#ifdef MGE_PLATFORM_WINDOWS

extern MGE::Application* MGE::createApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	MGE::Log::Init();

	MGE_PROFILE_BEGIN_SESSION("Startup", "HazelProfile-Startup.json");
	auto app = MGE::createApplication({ argc, argv });
	MGE_PROFILE_END_SESSION();

	MGE_PROFILE_BEGIN_SESSION("Runtime", "HazelProfile-Runtime.json");
	app->Run();
	MGE_PROFILE_END_SESSION();

	MGE_PROFILE_BEGIN_SESSION("Shutdown", "HazelProfile-Shutdown.json");
	delete app;
	MGE_PROFILE_END_SESSION();

	return 0;
}

#endif