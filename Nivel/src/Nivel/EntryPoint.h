#pragma once

#ifdef	NV_PLATFORM_WINDOWS

extern Nivel::Application* Nivel::CreateApplication();

int main(int argc, char** argv) 
{
	auto app = Nivel::CreateApplication();
	app->Run();
	delete app;
}

#endif