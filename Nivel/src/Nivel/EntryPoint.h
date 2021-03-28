#pragma once

#ifdef	NV_PLATFORM_WINDOWS

extern Nivel::Application* Nivel::CreateApplication();

int main(int argc, char** argv) 
{
	Nivel::Log::Init();
	NV_CORE_WARN("Initialized Log!");
	int a = 5;
	NV_INFO("Hello from Sandbox!, var={0}", a);

	auto app = Nivel::CreateApplication();
	app->Run();
	delete app;
}

#endif
