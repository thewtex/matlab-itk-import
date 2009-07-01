cmake_minimum_required(VERSION 2.6)
if(COMMAND cmake_policy)
  cmake_policy(VERSION 2.6)
endif(COMMAND cmake_policy)

project(matlab-itk-import)

find_package(ITK REQUIRED)
if(${ITK_BUILD_SHARED} STREQUAL "ON")
  # prevent linking with different libstdc++
  message(SEND_ERROR "Please compile ITK with BUILD_SHARED_LIBS set to OFF.
  Note that on the amd64 \(x86_64\) platform, ITK will need to be built with
  Position Independent Code, e.g. the -fPIC switch for gcc, because we will be
  building a shared library.  It is also recommended to use the same compiler
  that is specified in your mexopts.* file.")
endif(${ITK_BUILD_SHARED} STREQUAL "ON")

set(MATLAB_FUNCTION_NAME itkimport)

add_subdirectory(source)
