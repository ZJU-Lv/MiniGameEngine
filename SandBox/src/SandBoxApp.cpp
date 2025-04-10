#include "MGE.h"

//#include "imgui.h"

class ExampleLayer : public MGE::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (MGE::Input::IsKeyPressed(MGE_KEY_TAB))
			MGE_TRACE("Tab key is pressed (poll)!");
	}

	/*virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}*/

	void OnEvent(MGE::Event& event) override
	{
		if (event.GetEventType() == MGE::EventType::KeyPressed)
		{
			MGE::KeyPressedEvent& e = (MGE::KeyPressedEvent&)event;
			if (e.GetKeyCode() == MGE_KEY_TAB)
				MGE_TRACE("Tab key is pressed (event)!");
			MGE_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class SandBox : public MGE::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
	}

	~SandBox()
	{

	}
};

MGE::Application* MGE::createApplication()
{
	return new SandBox();
}