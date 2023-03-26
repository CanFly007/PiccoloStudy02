
set(ENGINE_ROOT_DIR "${PICCOLO_ROOT_DIR}/engine")
set(THIRD_PARTY_DIR "${ENGINE_ROOT_DIR}/3rdparty")
set(ENGINE_ASSET_DIR "/asset")

set(DEPLOY_CONFIG_DIR "configs/deployment")
set(DEVELOP_CONFIG_DIR "configs/development")

option(ENABLE_PHYSICS_DEBUG_RENDERER "Enable Physics Debug Renderer" OFF)

# only support physics debug render at windows platform
if(NOT WIN32)
  if(ENABLE_PHYSICS_DEBUG_RENDERER)
    message(WARNING "Disable Physics Debug Renderer")
    set(ENABLE_PHYSICS_DEBUG_RENDERER OFF CACHE BOOL "" FORCE)
  endif()
endif()





if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC") #在本机是相等的，这个宏没有介绍但也是系统宏
    message(WARNING "=======here is start Project set")
    add_compile_options("/MP")
    set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT PiccoloEditor) #在指定区域内设置属性 目前是PiccoloEditor没找到。找到的话，就是设置启动项为PiccoloEditor工程
endif()



























add_subdirectory(source/runtime)
add_subdirectory(source/editor)



set(CODEGEN_TARGET "PiccoloPreCompile")
include(source/precompile/precompile.cmake) #载入并运行cmake代码
set_target_properties("${CODEGEN_TARGET}" PROPERTIES FOLDER "Engine")

add_dependencies(PiccoloRuntime "${CODEGEN_TARGET}") #先生成PiccoloRuntime的依赖CODEGEN_TARGET，再生成PiccoloRuntime

#message(WARNING "++++++++ engine finish +++++++++++++++++++")