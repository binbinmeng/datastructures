cmake_minimum_required(VERSION 3.14)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)


find_package(spdlog)
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

add_executable(algorithms main.cpp binarytree.cpp binarytree.h ndarray.cpp ndarray.h backtracking.cpp backtracking.h linkedlist.cpp linkedlist.h avltree.cpp avltree.h graph.cpp graph.h hashtable.cpp hashtable.h arraystack.cpp arraystack.h liststack.cpp liststack.h arrayqueue.cpp arrayqueue.h)

target_link_libraries(algorithms spdlog ${llvm_libs})