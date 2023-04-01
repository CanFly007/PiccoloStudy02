#include <filesystem>
#include <iostream>
#include <string>
#include <thread>
#include <unordered_map>

 #include "runtime/engine.h"

#include "editor/include/editor.h"


#define PICCOLO_XSTR(s) PICCOLO_STR(s)
#define PICCOLO_STR(s) #s

int main(int argc, char** argv)
{
	std::filesystem::path executable_path(argv[0]); //argv[0]: D:\202303\PiccoloStudy02\build\engine\source\editor\Debug\PiccoloEditor.exe
	std::filesystem::path config_file_path = executable_path.parent_path() / "PiccoloEditor.ini"; //D:\\202303\\PiccoloStudy02\\build\\engine\\source\\editor\\Debug\\PiccoloEditor.ini

	Piccolo::PiccoloEngine* engine = new Piccolo::PiccoloEngine();
	engine->startEngine(config_file_path.generic_string()); //D:/202303/PiccoloStudy02/build/engine/source/editor/Debug/PiccoloEditor.ini

	// engine->initialize();

	// Piccolo::PiccoloEditor* editor = new Piccolo::PiccoloEditor();
	// editor->initialize(engine);
	// editor->run();
	// editor->clear();

	// engine->clear();
	// engine->shutdownEngine();

	//std::cout << config_file_path.generic_string() << std::endl;
	//std::cout << argv[0] << std::endl;
	std::cout << "hello engine" << std::endl;
	return 0;
}
