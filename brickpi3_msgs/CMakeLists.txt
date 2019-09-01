cmake_minimum_required(VERSION 2.8.3)
project(brickpi3_msgs)

find_package(catkin REQUIRED
  COMPONENTS
    geometry_msgs
    message_generation
    std_msgs
)

add_message_files(
  FILES
    Accelerometer.msg
    Color.msg
    Contact.msg
    Gyro.msg
    JointCommand.msg
    Light.msg
    Range.msg
)

generate_messages(
  DEPENDENCIES
    geometry_msgs
    std_msgs
)

catkin_package(
  CATKIN_DEPENDS
    geometry_msgs
    message_runtime
    std_msgs
)
