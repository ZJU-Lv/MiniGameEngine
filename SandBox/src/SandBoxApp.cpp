#include "MGE.h"

class ExampleLayer : public MGE::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		MGE_INFO("ExampleLayer::Update");
	}

	void OnEvent(MGE::Event& event) override
	{
		MGE_TRACE("{0}", event.ToString());
	}

};

class SandBox : public MGE::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new MGE::ImGuiLayer());
	}

	~SandBox()
	{

	}
};

MGE::Application* MGE::createApplication()
{
	return new SandBox();
}