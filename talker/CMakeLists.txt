cmake_minimum_required(VERSION 2.8.3)
project(talker)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

find_package(catkin REQUIRED COMPONENTS
  rxros
  std_msgs
)

catkin_package(
   CATKIN_DEPENDS 
     rxros std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

link_directories(${catkin_LIBRARY_DIRS})

add_executable(talker 
  src/talker.cpp
)

add_dependencies(talker ${catkin_EXPORTED_TARGETS})

target_link_libraries(talker ${catkin_LIBRARIES})


install(
  TARGETS 
    talker
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)
