#pragma once

#include <memory>
#include <string>

namespace Piccolo
{
	class LogSystem;

    class RuntimeGlobalContext
	{
	public:
		void startSystems(const std::string& config_file_path);
		void shutdownSystems();

	public:
		std::shared_ptr<LogSystem> m_logger_system;

	};

	extern RuntimeGlobalContext g_runtime_global_context;
}