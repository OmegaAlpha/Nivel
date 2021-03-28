#include <Nivel.h>

class Sandbox : public Nivel::Application {
public:
	Sandbox() 
	{

	}

	~Sandbox()
	{

	}

};


Nivel::Application* Nivel::CreateApplication() {
	return new Sandbox();
}
