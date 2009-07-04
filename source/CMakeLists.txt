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
if(MSYS)
message(STATUS "Warning: assuming have GNUMEX/MinGW as the backend.")
  set(WINDOWS_SYSTEM_LIB_DIRS "C:/WINDOWS/SYSTEM32" CACHE PATH "Path to MS Windows system libraries.")
  set(MINGW_DIR "C:/MinGW" CACHE PATH "Path to MinGW installation directory.")
  link_directories(
    ${WINDOWS_SYSTEM_LIB_DIRS}
    ${MINGW_DIR}/lib
    )
  # the mex compiler only links in user's static libs, by default, so we add the
  # dll's needed by ITK's gdcm here via the gnumex interface
  # tested against gnumex-2.01
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} GM_ADD_LIBS='-llibmx -llibmex -llibmat -lsnmpapi -lrpcrt4 -lws2_32 -lcomcl32 -lwsock32 -lgdi32 ' ")
  set(ENV{GM_ADD_LIBS} "-llibmx -llibmex -llibmat -lsnmpapi -lrpcrt4 -lws2_32 -lcomcl32 -lwsock32 -lgdi32")
endif(MSYS)

add_library(${MATLAB_FUNCTION_NAME} SHARED
  ${matlab-itk-import_BINARY_DIR}/source/main_gateway.cpp 
  MainPipeline.cpp)
target_link_libraries(${MATLAB_FUNCTION_NAME}
  ITKCommon
  ITKIO
  )
if(MSYS)
  target_link_libraries(${MATLAB_FUNCTION_NAME} stdc++)
endif(MSYS)
install(TARGETS ${MATLAB_FUNCTION_NAME}
  DESTINATION ${CMAKE_INSTALL_PREFIX})

add_library(${SLICECOUNT_FUNCTION_NAME} SHARED
  ${matlab-itk-import_BINARY_DIR}/source/slicecount_gateway.cpp 
  SliceCountPipeline.cpp)
target_link_libraries(${SLICECOUNT_FUNCTION_NAME}
  ITKCommon
  ITKIO
  )
if(MSYS)
  target_link_libraries(${SLICECOUNT_FUNCTION_NAME} stdc++)
endif(MSYS)
install(TARGETS ${SLICECOUNT_FUNCTION_NAME}
  DESTINATION ${CMAKE_INSTALL_PREFIX})
