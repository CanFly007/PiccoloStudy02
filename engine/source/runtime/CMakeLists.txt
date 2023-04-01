

set(TARGET_NAME PiccoloRuntime)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(JSON_INCLUDE ${THIRD_PARTY_DIR}/json11)

add_library(json11 ${JSON_INCLUDE}/json11.cpp) #json11.cpp编译成库，导入到runtime这个工程
set_target_properties(json11 PROPERTIES FOLDER "ThirdParty/json11")



#文件操作命令，递归遍历所有文件
file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE SOURCE_FILES "*.cpp")

#用于生成IDE工程里的源码分组
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${HEADER_FILES} ${SOURCE_FILES})












#生成PiccoloRuntime的dll文件
add_library(${TARGET_NAME} ${HEADER_FILES} ${SOURCE_FILES})

set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17)
set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "Engine")

# being a cross-platform target, we enforce standards conformance on MSVC
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/WX->")

















#奇怪的是：这是runtime的CMakeList，但可以影响PiccoloRuntime和PiccoloEditor两个工程
target_include_directories(
  ${TARGET_NAME} 
  PUBLIC $<BUILD_INTERFACE:${ENGINE_ROOT_DIR}/source>
  $<INSTALL_INTERFACE:include/${TARGET_NAME}-${PROJECT_VERSION}>
)  #engine/source





target_include_directories(
  ${TARGET_NAME} 
  PUBLIC $<BUILD_INTERFACE:${ENGINE_ROOT_DIR}/source/runtime>
  $<INSTALL_INTERFACE:include/${TARGET_NAME}-${PROJECT_VERSION}>
) #engine/source/runtime