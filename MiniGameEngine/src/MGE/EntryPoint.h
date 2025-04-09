#pragma once

#ifdef MGE_PLATFORM_WINDOWS

extern MGE::Application* MGE::createApplication();

int main(int argc, char** argv)
{
	MGE::Log::Init();
	MGE_CORE_WARN("Initialized Log!");
	MGE_INFO("Hello!");

	auto app = MGE::createApplication();
	app->Run();
	delete app;

	return 0;
}

#endif