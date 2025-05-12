#pragma once

#include "MGE/Core/Base.h"
#include "MGE/Core/Log.h"
#include "MGE/Scene/Scene.h"
#include "MGE/Scene/Entity.h"

namespace MGE {

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& scene);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};

}