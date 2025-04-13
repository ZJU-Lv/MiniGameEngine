#include "Core.h"

#include "Window.h"
#include "MGE/LayerStack.h"
#include "MGE/Events/Event.h"
#include "MGE/Events/ApplicationEvent.h"
#include "MGE/ImGui/ImGuiLayer.h"

#include "MGE/Renderer/Shader.h"
#include "MGE/Renderer/Buffer.h"

namespace MGE {
	class MGE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* createApplication();
}
