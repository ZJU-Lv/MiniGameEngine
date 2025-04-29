#pragma once

#include <MGE.h>

class ExampleLayer : public MGE::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(MGE::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(MGE::Event& e) override;
private:
	MGE::ShaderLibrary m_ShaderLibrary;
	MGE::Ref<MGE::Shader> m_Shader;
	MGE::Ref<MGE::VertexArray> m_VertexArray;

	MGE::Ref<MGE::Shader> m_FlatColorShader;
	MGE::Ref<MGE::VertexArray> m_SquareVA;

	MGE::Ref<MGE::Texture2D> m_Texture, m_ChernoLogoTexture;

	MGE::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};
