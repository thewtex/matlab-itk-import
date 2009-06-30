# setup MATLAB_FUNCTION_NAME
configure_file(${matlab-itk-import_SOURCE_DIR}/source/matlab_itk_import.cpp
  ${matlab-itk-import_BINARY_DIR}/source/matlab_itk_import.cpp)

add_library( ${MATLAB_FUNCTION_NAME} SHARED
  ${matlab-itk-import_BINARY_DIR}/source/matlab_itk_import.cpp )
