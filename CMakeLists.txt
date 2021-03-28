cmake_minimum_required(VERSION 3.15)

project(testFit)

add_subdirectory(extern/DingXuefeng/cmake-cuda-CI-github-actions)
add_library(Fit::Fit-lib ALIAS Fit-lib)

INITIALIZE_CUDA()

add_library(myFun STATIC newfunctions.cu)
target_link_libraries(myFun PUBLIC Fit::Fit-lib)
target_include_directories(myFun PUBLIC ${PROJECT_SOURCE_DIR})
set_target_properties(myFun PROPERTIES 
	    CUDA_SEPARABLE_COMPILATION ON
	    CUDA_ARCHITECTURES 60)

add_library(run STATIC run.cu)
target_link_libraries(run PUBLIC myFun)
set_target_properties(run PROPERTIES 
	    CUDA_SEPARABLE_COMPILATION ON
	    CUDA_ARCHITECTURES 60)

add_executable(testFit main.cc)
target_link_libraries(testFit PRIVATE run Fit::Fit-lib)

# test
enable_testing()
add_subdirectory(tests)
