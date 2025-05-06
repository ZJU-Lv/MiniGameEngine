#pragma once

#include "MGE.h"

class Sandbox2D : public MGE::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(MGE::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(MGE::Event& e) override;
private:
	MGE::OrthographicCameraController m_CameraController;

	// Temp
	MGE::Ref<MGE::VertexArray> m_SquareVA;
	MGE::Ref<MGE::Shader> m_FlatColorShader;
	MGE::Ref<MGE::Framebuffer> m_Framebuffer;
	
	MGE::Ref<MGE::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};