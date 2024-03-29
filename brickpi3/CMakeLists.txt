cmake_minimum_required(VERSION 2.8.3)
project(brickpi3)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

find_package(catkin REQUIRED
  COMPONENTS
    brickpi3_msgs
    geometry_msgs
    nav_msgs
    rxros
    sensor_msgs
    std_msgs
    tf
)

catkin_package(
  CATKIN_DEPENDS
    brickpi3_msgs
    geometry_msgs
    nav_msgs
    rxros
    sensor_msgs
    std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(brickpi3
  src/BrickPi3.cpp
  src/BrickPi3Color.cpp
  src/BrickPi3Motor.cpp
  src/BrickPi3Ros.cpp
  src/BrickPi3Touch.cpp
  src/BrickPi3Ultrasonic.cpp
)

add_executable(brickpi3_rxros
  src/BrickPi3.cpp
  src/BrickPi3Ros_rx.cpp
)

add_executable(brickpi3_joint_states_publisher
  src/BrickPi3JointStatesPublisher.cpp
)

add_executable(brickpi3_joint_states_publisher_rxros
  src/BrickPi3JointStatesPublisher_rx.cpp
)

add_executable(brickpi3_odom_publisher
  src/BrickPi3OdomPublisher.cpp
)

add_executable(brickpi3_odom_publisher_rxros
  src/BrickPi3OdomPublisher_rx.cpp
)

add_executable(brickpi3_base_controller
  src/BrickPi3BaseController.cpp
)

add_executable(brickpi3_base_controller_rxros
  src/BrickPi3BaseController_rx.cpp
)

add_dependencies(brickpi3 ${catkin_EXPORTED_TARGETS})
add_dependencies(brickpi3_rxros ${catkin_EXPORTED_TARGETS})
add_dependencies(brickpi3_joint_states_publisher ${catkin_EXPORTED_TARGETS})
add_dependencies(brickpi3_joint_states_publisher_rxros ${catkin_EXPORTED_TARGETS})
add_dependencies(brickpi3_odom_publisher ${catkin_EXPORTED_TARGETS})
add_dependencies(brickpi3_odom_publisher_rxros ${catkin_EXPORTED_TARGETS})
add_dependencies(brickpi3_base_controller ${catkin_EXPORTED_TARGETS})
add_dependencies(brickpi3_base_controller_rxros ${catkin_EXPORTED_TARGETS})

target_link_libraries(brickpi3 ${catkin_LIBRARIES})
target_link_libraries(brickpi3_rxros ${catkin_LIBRARIES})
target_link_libraries(brickpi3_joint_states_publisher ${catkin_LIBRARIES})
target_link_libraries(brickpi3_joint_states_publisher_rxros ${catkin_LIBRARIES})
target_link_libraries(brickpi3_odom_publisher ${catkin_LIBRARIES})
target_link_libraries(brickpi3_odom_publisher_rxros ${catkin_LIBRARIES})
target_link_libraries(brickpi3_base_controller ${catkin_LIBRARIES})
target_link_libraries(brickpi3_base_controller_rxros ${catkin_LIBRARIES})

install(
  TARGETS
    brickpi3
    brickpi3_base_controller
    brickpi3_base_controller_rxros
    brickpi3_joint_states_publisher
    brickpi3_joint_states_publisher_rxros
    brickpi3_odom_publisher
    brickpi3_odom_publisher_rxros
    brickpi3_rxros
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION})
