#include "engine.h"

// #include "runtime/core/base/macro.h"
// #include "runtime/core/meta/reflection/reflection_register.h"

// #include "runtime/function/global/global_context.h"

namespace Piccolo
{
	bool g_is_editor_mode{ false };
	std::unordered_set<std::string> g_editor_tick_component_types{};

	void PiccoloEngine::startEngine(const std::string& config_file_path)
	{
		//Reflection::TypeMetaRegister::metaRegister(); //��Ϊ�޷�������������ʱע��
		
		// g_runtime_global_context.startSystems(config_file_path);

		// LOG_INFO("engine start");
	}

	void PiccoloEngine::shutdownEngine()
	{

	}

	void PiccoloEngine::initialize() {}
	void PiccoloEngine::clear() {}
}