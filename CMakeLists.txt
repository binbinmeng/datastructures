cmake_minimum_required(VERSION 3.14)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)
set(INC_DIR ./thirdparty/spdlog/include)
set(LINK_DIR ./thirdparty/spdlog/build)

#add_library(spdlog archive.cpp zip.cpp lzma.cpp)

add_executable(algorithms main.cpp binarytree.cpp binarytree.h ndarray.cpp ndarray.h)

#target_link_libraries(algorithms spdlog)