cmake_minimum_required(VERSION 3.8.0)
project(FFMPEG)
set(CMAKE_CXX_STANDARD 20)
set(HOME F:\\C++Pro\\Git\\FFMPEG)
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)
message(STATUS "source path: ${CMAKE_CURRENT_SOURCE_DIR}")

 
#导入sdl2、ffmpeg头文件
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/source/include")
link_directories("F:/C++/FFMPEG-SHARE/lib")
link_directories("F:/C++/SDL2/lib/x64")
#搜索src目录下的源文件
include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
#生成可执行文件
add_executable(app main.cpp ${SRC_LIST})

target_link_libraries(app
SDL2
avformat
avutil
avcodec
avdevice
avfilter
)