#include "MGE.h"

class SandBox : public MGE::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}
};

MGE::Application* MGE::createApplication()
{
	return new SandBox();
}