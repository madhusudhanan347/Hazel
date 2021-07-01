#include"hzpch.h"
#include "log.h"
#include"spdlog/sinks/stdout_color_sinks.h"


namespace Hazel {

	std::shared_ptr<spdlog::logger> log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> log::s_ClientLogger;

	void log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stderr_color_mt("HAZEL");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stderr_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);


	}

}