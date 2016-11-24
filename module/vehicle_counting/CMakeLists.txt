
# the Vehicle Counting Library
project(VCLib)

FILE(GLOB_RECURSE analysis_header "package_analysis/*.h*")
FILE(GLOB_RECURSE analysis "package_analysis/*.c*")
FILE(GLOB_RECURSE bgs_header "package_bgs/*.h*")
FILE(GLOB_RECURSE bgs "package_bgs/*.c*")
FILE(GLOB_RECURSE tracking_header "package_tracking/*.h*")
FILE(GLOB_RECURSE tracking "package_tracking/*.c*")

SET(vehicle_counting_header ${analysis_header} ${bgs_header} ${tracking_header})
SET(vehicle_counting ${analysis} ${bgs} ${tracking})

#-------------------------------------------------------------
# project and output
#-------------------------------------------------------------
ADD_LIBRARY(Vehicle_counting SHARED ${vehicle_counting_header} ${vehicle_counting})
# SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
SET_TARGET_PROPERTIES(Vehicle_counting
					PROPERTIES
					# OUTPUT_NAME_DEBUG "TEST_DEBUG"
					# OUTPUT_NAME_RELEASE "TEST_RELEASE"
					RUNTIME_OUTPUT_DIRECTORY ${ROOT_BINARY_DIR}/bin
					LIBRARY_OUTPUT_DIRECTORY ${ROOT_BINARY_DIR}/lib
					RUNTIME_OUTPUT_DIRECTORY_DEBUG ${ROOT_BINARY_DIR}/bin
					LIBRARY_OUTPUT_DIRECTORY_DEBUG ${ROOT_BINARY_DIR}/lib
					ARCHIVE_OUTPUT_DIRECTORY ${ROOT_BINARY_DIR}/lib
					ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${ROOT_BINARY_DIR}/lib)
# 设置Vehicle_counting在debug模式下的后缀
SET_TARGET_PROPERTIES(Vehicle_counting PROPERTIES DEBUG_POSTFIX d)
# 全局设置
# SET(CMAKE_DEBUG_POSTFIX d)

#-------------------------------------------------------------
# include and lib
#-------------------------------------------------------------
TARGET_LINK_LIBRARIES(Vehicle_counting ${OpenCV_LIBS})
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

#-------------------------------------------------------------
# source group
#-------------------------------------------------------------
SOURCE_GROUP("Analysis" FILES ${analysis_header} ${analysis})
SOURCE_GROUP("Bgs" FILES ${bgs_header} ${bgs})
SOURCE_GROUP("Tracking" FILES ${tracking_header} ${tracking})


# INSTALL(TARGET Vehicle_counting 
		# RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin COMPONENT )
