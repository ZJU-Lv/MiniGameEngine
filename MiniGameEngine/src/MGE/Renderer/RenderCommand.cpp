#include "precompiled.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace MGE {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}