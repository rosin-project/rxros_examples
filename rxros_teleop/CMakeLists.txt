cmake_minimum_required(VERSION 2.8.3)
project(teleop)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

find_package(catkin REQUIRED COMPONENTS
  rxros
  std_msgs
  teleop_msgs
)

catkin_package(
  CATKIN_DEPENDS
    rxros
    std_msgs
    teleop_msgs
)

include_directories(${catkin_INCLUDE_DIRS})


add_executable(joystick_publisher       src/JoystickPublisher.cpp)
add_executable(joystick_publisher_rxros src/JoystickPublisher_rx.cpp)
add_executable(keyboard_publisher       src/KeyboardPublisher.cpp)
add_executable(keyboard_publisher_rxros src/KeyboardPublisher_rx.cpp)
add_executable(velocity_publisher       src/VelocityPublisher.cpp)
add_executable(velocity_publisher_rxros src/VelocityPublisher_rx.cpp)

add_dependencies(joystick_publisher       ${catkin_EXPORTED_TARGETS})
add_dependencies(joystick_publisher_rxros ${catkin_EXPORTED_TARGETS})
add_dependencies(keyboard_publisher       ${catkin_EXPORTED_TARGETS})
add_dependencies(keyboard_publisher_rxros ${catkin_EXPORTED_TARGETS})
add_dependencies(velocity_publisher       ${catkin_EXPORTED_TARGETS})
add_dependencies(velocity_publisher_rxros ${catkin_EXPORTED_TARGETS})

target_link_libraries(joystick_publisher       ${catkin_LIBRARIES})
target_link_libraries(joystick_publisher_rxros ${catkin_LIBRARIES})
target_link_libraries(keyboard_publisher       ${catkin_LIBRARIES})
target_link_libraries(keyboard_publisher_rxros ${catkin_LIBRARIES})
target_link_libraries(velocity_publisher       ${catkin_LIBRARIES})
target_link_libraries(velocity_publisher_rxros ${catkin_LIBRARIES})

install(
  TARGETS
    joystick_publisher
    joystick_publisher_rxros
    keyboard_publisher
    keyboard_publisher_rxros
    velocity_publisher
    velocity_publisher_rxros
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION})
