cmake_minimum_required(VERSION 3.15)

project(testFit)

add_subdirectory(extern/DingXuefeng/cmake-cuda-CI-github-actions)
add_library(Fit::Fit-lib ALIAS Fit-lib)
if(DEVICE STREQUAL CUDA)
  enable_language(CUDA)
  set(CMAKE_CUDA_SEPARABLE_COMPILATION ON) # effective when created
else()
  file(GLOB_RECURSE CUDA_FILES *.cu)
  set_source_files_properties(${CUDA_FILES} PROPERTIES LANGUAGE CXX)
  add_compile_options(-x c++)
endif()

add_library(myFun STATIC newfunctions.cu)
target_link_libraries(myFun PUBLIC Fit::Fit-lib)
target_include_directories(myFun PUBLIC ${PROJECT_SOURCE_DIR})

add_library(run STATIC run.cu)
target_link_libraries(run PUBLIC myFun)

add_executable(testFit main.cc)
target_link_libraries(testFit PRIVATE run Fit::Fit-lib)

# test
enable_testing()
add_subdirectory(tests)
