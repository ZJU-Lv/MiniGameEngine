#pragma once

#ifdef MGE_PLATFORM_WINDOWS

extern MGE::Application* MGE::createApplication();

int main(int argc, char** argv)
{
	printf("Mini Game Engine Start!\n");
	auto app = MGE::createApplication();
	app->Run();
	delete app;

	return 0;
}

#endif