cmake_minimum_required(VERSION 2.6)
if(COMMAND cmake_policy)
  cmake_policy(VERSION 2.6)
endif(COMMAND cmake_policy)

project(matlab-itk-import)

find_package(ITK REQUIRED)

add_subdirectory(source)
