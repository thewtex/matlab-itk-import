# setup MATLAB_FUNCTION_NAME
configure_file(${matlab-itk-import_SOURCE_DIR}/source/matlab_itk_import.cpp
  ${matlab-itk-import_BINARY_DIR}/source/matlab_itk_import.cpp)
configure_file(${matlab-itk-import_SOURCE_DIR}/source/matlab_function_doc.m
  ${matlab-itk-import_BINARY_DIR}/source/${MATLAB_FUNCTION_NAME}.m)

include_directories(${matlab-itk-import_SOURCE_DIR}/source
  ${ITK_INCLUDE_DIRS}
  )

link_directories(${ITK_LIBRARY_DIRS})

add_library(${MATLAB_FUNCTION_NAME} SHARED
  ${matlab-itk-import_BINARY_DIR}/source/matlab_itk_import.cpp 
  MainPipeline.cpp)
target_link_libraries(${MATLAB_FUNCTION_NAME}
  ITKCommon
  ITKIO
  )
