#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Petalume {

	class PETALUME_API  Log
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
#define PL_CORE_TRACE(...)    ::Petalume::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PL_CORE_INFO(...)     ::Petalume::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PL_CORE_WARN(...)     ::Petalume::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PL_CORE_ERROR(...)    ::Petalume::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PL_CORE_FATAL(...)    ::Petalume::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define PL_TRACE(...)	      ::Petalume::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PL_INFO(...)	      ::Petalume::Log::GetClientLogger()->info(__VA_ARGS__)
#define PL_WARN(...)	      ::Petalume::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PL_ERROR(...)	      ::Petalume::Log::GetClientLogger()->error(__VA_ARGS__)
#define PL_FATAL(...)	      ::Petalume::Log::GetClientLogger()->fatal(__VA_ARGS__)