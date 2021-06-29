#pragma once

#include<memory>

#include"core.h"
#include"spdlog/spdlog.h"

namespace Hazel {

	class HAZEL_API log
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

//Core log macros
#define HZ_CORE_TRACE(...)	::Hazel::log::GetCoreLogger()->trace(__VA_ARGS__)	
#define HZ_CORE_INFO(...)	::Hazel::log::GetCoreLogger()->info(__VA_ARGS__)	
#define HZ_CORE_WARN(...)	::Hazel::log::GetCoreLogger()->warn(__VA_ARGS__)	
#define HZ_CORE_ERROR(...)	::Hazel::log::GetCoreLogger()->error(__VA_ARGS__)	
#define HZ_CORE_FATAL(...)	::Hazel::log::GetCoreLogger()->fatal(__VA_ARGS__)	

//Client log macros
#define HZ_TRACE(...)	::Hazel::log::GetClientLogger()->trace(__VA_ARGS__)	
#define HZ_INFO(...)	::Hazel::log::GetClientLogger()->info(__VA_ARGS__)	
#define HZ_WARN(...)	::Hazel::log::GetClientLogger()->warn(__VA_ARGS__)	
#define HZ_ERROR(...)	::Hazel::log::GetClientLogger()->error(__VA_ARGS__)	
#define HZ_FATAL(...)	::Hazel::log::GetClientLogger()->fatal(__VA_ARGS__)	

