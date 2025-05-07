#pragma once

#include "MGE/Core/Layer.h"

#include "MGE/Events/ApplicationEvent.h"
#include "MGE/Events/KeyEvent.h"
#include "MGE/Events/MouseEvent.h"

namespace MGE {

	class MGE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};

}