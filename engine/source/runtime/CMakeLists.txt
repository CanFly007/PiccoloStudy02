

set(TARGET_NAME PiccoloRuntime)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(JSON_INCLUDE ${THIRD_PARTY_DIR}/json11)

add_library(json11 ${JSON_INCLUDE}/json11.cpp) #json11.cpp编译成库，导入到runtime这个工程
set_target_properties(json11 PROPERTIES FOLDER "ThirdParty/json11")



#文件操作命令，递归遍历所有文件
file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE SOURCE_FILES "*.cpp")