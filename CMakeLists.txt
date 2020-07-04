cmake_minimum_required(VERSION 3.10)
project(src)

set(CMAKE_CXX_STANDARD 14)

find_package(spdlog)
#[[find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)
]]
include_directories (${CMAKE_SOURCE_DIR}/src)
include_directories (${CMAKE_SOURCE_DIR}/include)
set(SRC_FILES
     src/binarytree.cpp
     src/ndarray.cpp
     src/backtracking.cpp
     src/linkedlist.cpp
     src/avltree.cpp
     src/graph.cpp
     src/hashtable.cpp
     src/arraystack.cpp
     src/liststack.cpp
     src/arrayqueue.cpp)
 set(INCULDE_FILES
      src/binarytree.h
      src/ndarray.h
      src/backtracking.h
      src/linkedlist.h
      src/avltree.h
      src/graph.h
      src/hashtable.h
      src/arraystack.h
      src/liststack.h
      src/arrayqueue.h)
add_executable(algorithms main.cpp ${SRC_FILES} ${INCLUDE_FILES})

target_link_libraries(algorithms spdlog)# ${llvm_libs})
