cmake_minimum_required(VERSION 3.29.6)
project(DSAProject2TriviaGame)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/bridges-cxx-3.4.1-x86_64-linux-gnu)

find_package(CURL REQUIRED)


add_executable(DSAProject2TriviaGame src/main.cpp
)

target_link_libraries(DSAProject2TriviaGame PRIVATE CURL::libcurl)