#pragma once

#include <memory>

#include "spdlog/spdlog.h"
#include "Core.h"

namespace Nivel 
{
	class NIVEL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}


// Core log macros
#define NV_CORE_INFO(...)	::Nivel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NV_CORE_WARN(...)	::Nivel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NV_CORE_ERROR(...)	::Nivel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NV_CORE_FATAL(...)	::Nivel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Cient log macros
#define NV_TRACE(...)	    ::Nivel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NV_INFO(...)	    ::Nivel::Log::GetClientLogger()->info(__VA_ARGS__)
#define NV_WARN(...)	    ::Nivel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NV_ERROR(...)	    ::Nivel::Log::GetClientLogger()->error(__VA_ARGS__)
#define NV_FATAL(...)	    ::Nivel::Log::GetClientLogger()->fatal(__VA_ARGS__)
