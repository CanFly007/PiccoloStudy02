#include "runtime/function/global/global_context.h"
#include "runtime/engine.h"

#include <iostream>

namespace Piccolo
{
	RuntimeGlobalContext g_runtime_global_context;
	
	void RuntimeGlobalContext::startSystems(const std::string& config_file_path)
	{
		std::cout << config_file_path << std::endl;

		//m_logger_system = std::make_shared<LogSystem>();
		//TODO...CONTINUE
	}
}