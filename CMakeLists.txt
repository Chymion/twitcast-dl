project(twitcast-dl)
cmake_minimum_required(VERSION 3.0)
set(EXECUTABLE_OUTPUT_PATH ./)

add_executable(${PROJECT_NAME} twitcast.cpp)
