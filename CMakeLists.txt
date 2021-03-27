cmake_minimum_required(VERSION 3.15)

project(testFit)

### include utilities
include(FetchContent)

FetchContent_Declare(
  cmake-cuda 
  GIT_REPOSITORY https://github.com/DingXuefeng/cmake-cuda-CI-github-actions
  GIT_TAG        v1.1.1
  )
FetchContent_MakeAvailable(cmake-cuda)
add_library(Fit::Fit-lib ALIAS Fit-lib)
add_library(Fit::Fit-devicelib ALIAS Fit-devicelib)
if(NOT DEVICE STREQUAL CUDA)
  set_source_files_properties(newfunctions.cu PROPERTIES LANGUAGE CXX)
  add_compile_options(-x c++)
endif()

add_library(myFun STATIC newfunctions.cu)
target_link_libraries(myFun PUBLIC Fit::Fit-devicelib)
target_include_directories(myFun PUBLIC ${PROJECT_SOURCE_DIR})

add_executable(testFit main.cc)
target_link_libraries(testFit PRIVATE myFun Fit::Fit-lib)

# test
include(FetchContent)
FetchContent_Declare(
  googletest  
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.8.0
)
set(googletest_BUILD_TESTS OFF)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_subdirectory(tests)
