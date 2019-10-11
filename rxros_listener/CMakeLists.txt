cmake_minimum_required(VERSION 2.8.3)
project(rxros_listener)

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
    rxros
    std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(listener src/rxros_listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener ${catkin_EXPORTED_TARGETS})

install(
  TARGETS 
    listener
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)
