cmake_minimum_required(VERSION 3.0.0)
project(teleop VERSION 0.1.0)

set(SOURCE src/teleop.cpp src src/example_teleop.cpp)

add_executable(teleop ${SOURCE})