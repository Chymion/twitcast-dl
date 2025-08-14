cmake_minimum_required(VERSION 3.10)
project(twitcast-dl)
set(EXECUTABLE_OUTPUT_PATH ./)

add_executable(${PROJECT_NAME} twitcast.cpp)
