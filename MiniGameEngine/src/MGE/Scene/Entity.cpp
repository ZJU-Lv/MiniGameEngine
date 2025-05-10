#include "precompiled.h"
#include "Entity.h"

namespace MGE {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}