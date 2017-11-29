cmake_minimum_required(VERSION 3.8)
project(Ex3)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES Player.cpp Player.h Board.cpp Board.h HumanPlayer.cpp HumanPlayer.h AIPlayer.cpp AIPlayer.h GameManager.cpp GameManager.h RegularGameManager.cpp RegularGameManager.h GameLogic.cpp GameLogic.h RegularGameLogic.cpp RegularGameLogic.h)

set(TEST_FILES tests/test_something.cpp tests/test_something.cpp)

add_executable(Ex3_Test ${SOURCE_FILES} ${TEST_FILES} tests/main_test.cpp)
add_executable(Ex3_Game ${SOURCE_FILES} main.cpp )
