cmake_minimum_required(VERSION 2.6)
if(COMMAND cmake_policy)
  cmake_policy(VERSION 2.6)
endif(COMMAND cmake_policy)

project(matlab-itk-import)

find_package(ITK REQUIRED)

set(MATLAB_FUNCTION_NAME itkimport)
configure_file(${matlab-itk-import_SOURCE_DIR}/source/matlab_itk_import.cpp
  ${matlab-itk-import_BINARY_DIR}/source/matlab_itk_import.cpp)

add_subdirectory(source)
