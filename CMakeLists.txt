cmake_minimum_required(VERSION 3.10)
project(src)

set(CMAKE_CXX_STANDARD 14)

#find_package(spdlog)
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
     src/linkedlist.cpp
     src/binarytree.cpp
     src/sort.cpp)
 set(INCULDE_FILES
     include/linkedlist.h
     include/binarytree.h
     include/sort.h)
add_executable(algorithms main.cpp ${SRC_FILES} ${INCLUDE_FILES})

#target_link_libraries(algorithms spdlog)# ${llvm_libs})
