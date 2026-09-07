#include <Petalume.h>

class Sandbox : public Petalume::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Petalume::Application* Petalume::CreateApplication()
{
	return new Sandbox();
}