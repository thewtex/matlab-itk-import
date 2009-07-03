# setup MATLAB_FUNCTION_NAME
configure_file(${matlab-itk-import_SOURCE_DIR}/source/main_gateway.cpp
  ${matlab-itk-import_BINARY_DIR}/source/main_gateway.cpp)
configure_file(${matlab-itk-import_SOURCE_DIR}/source/main_matlab_function_doc.m
  ${matlab-itk-import_BINARY_DIR}/source/${MATLAB_FUNCTION_NAME}.m)
install(FILES ${matlab-itk-import_BINARY_DIR}/source/${MATLAB_FUNCTION_NAME}.m 
  DESTINATION ${CMAKE_INSTALL_PREFIX})

# setup SLICECOUNT_FUNCTION_NAME
configure_file(${matlab-itk-import_SOURCE_DIR}/source/slicecount_gateway.cpp
  ${matlab-itk-import_BINARY_DIR}/source/slicecount_gateway.cpp)
configure_file(${matlab-itk-import_SOURCE_DIR}/source/slicecount_function_doc.m
  ${matlab-itk-import_BINARY_DIR}/source/${SLICECOUNT_FUNCTION_NAME}.m)
install(FILES ${matlab-itk-import_BINARY_DIR}/source/${SLICECOUNT_FUNCTION_NAME}.m 
  DESTINATION ${CMAKE_INSTALL_PREFIX})

include_directories(${matlab-itk-import_SOURCE_DIR}/source
  ${ITK_INCLUDE_DIRS}
  )
link_directories(${ITK_LIBRARY_DIRS})

add_library(${MATLAB_FUNCTION_NAME} SHARED
  ${matlab-itk-import_BINARY_DIR}/source/main_gateway.cpp 
  MainPipeline.cpp)
target_link_libraries(${MATLAB_FUNCTION_NAME}
  ITKCommon
  ITKIO
  )
install(TARGETS ${MATLAB_FUNCTION_NAME}
  DESTINATION ${CMAKE_INSTALL_PREFIX})

add_library(${SLICECOUNT_FUNCTION_NAME} SHARED
  ${matlab-itk-import_BINARY_DIR}/source/slicecount_gateway.cpp 
  SliceCountPipeline.cpp)
target_link_libraries(${SLICECOUNT_FUNCTION_NAME}
  ITKCommon
  ITKIO
  )
install(TARGETS ${SLICECOUNT_FUNCTION_NAME}
  DESTINATION ${CMAKE_INSTALL_PREFIX})
