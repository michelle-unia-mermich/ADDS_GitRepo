cmake_minimum_required(VERSION 3.5.0)
project(DocumentManager VERSION 0.1.0 LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 11)
add_executable(DocumentManager main.cpp Document.cpp DocumentManager.cpp)

