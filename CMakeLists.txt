cmake_minimum_required(VERSION 3.16.3)
project(DSAProject2TriviaGame)

set(CMAKE_CXX_STANDARD 14)

include_directories({CMAKE_CURRENT_SOURCE_DIR}/../libraries/bridges/include)
link_directories({CMAKE_CURRENT_SOURCE_DIR}/../libraries/bridges/lib)

include_directories({CMAKE_CURRENT_SOURCE_DIR}/../libraries/curl/include)
link_directories({CMAKE_CURRENT_SOURCE_DIR}/../libraries/curl/lib)

add_executable(DSAProject2TriviaGame src/main.cpp src/question.h
        src/sort.cpp
        src/question.cpp
        src/sort.h)
target_link_libraries(DSAProject2TriviaGame libcurl.lib)
