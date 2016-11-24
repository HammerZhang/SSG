# collect sources into the variable MATH_SOURCES with
# having to explicitly list each header and source file
FILE (GLOB MAIN_SOURCES "*.h" "*.cpp")
# another ways
#SET(MAIN_SOURCES "*.h" "*.cpp")
# 发现目录下的所有源代码
#AUX_SOURCE_DIRECTORY(./ MAIN_SOURCES)


#MESSAGE(STATUS ${CMAKE_CURRENT_SOURCE_DIR})

# include directory
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES("../../module/")


ADD_EXECUTABLE(sample_1 main.cpp FileSearch.cpp)
# SET(EXECUTABLE_OUTPUT_PATH ${ROOT_BINARY_DIR}/bin)
SET_TARGET_PROPERTIES(sample_1
					PROPERTIES
					RUNTIME_OUTPUT_DIRECTORY_DEBUG ${ROOT_BINARY_DIR}/bin
					RUNTIME_OUTPUT_DIRECTORY_RELEASE ${ROOT_BINARY_DIR}/bin
					DEBUG_POSTFIX d)

# 添加依赖库
#ADD_DEPENDENCIES(sample_1 xxx)

# add opencv
TARGET_LINK_LIBRARIES(sample_1 ${OpenCV_LIBS})
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

# source group
SOURCE_GROUP("" FILES ${MAIN_SOURCES})

# add logic to INSTALL.VCPROJ to copy main.exe to destination directory
INSTALL(TARGETS sample_1 RUNTIME DESTINATION ${EXECUTABLE_OUTPUT_PATH})