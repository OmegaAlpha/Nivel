#pragma once

#include "Core.h"

namespace Nivel 
{

	class NIVEL_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


