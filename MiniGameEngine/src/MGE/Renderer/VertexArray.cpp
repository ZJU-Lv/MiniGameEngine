#include "precompiled.h"
#include "VertexArray.h"
#include "MGE/Core/Log.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace MGE {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    MGE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return std::make_shared<OpenGLVertexArray>();
		}

		MGE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}