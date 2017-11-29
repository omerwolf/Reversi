cmake_minimum_required(VERSION 3.8)
project(Ex3)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES source/Player.cpp include/Player.h source/Board.cpp include/Board.h source/HumanPlayer.cpp include/HumanPlayer.h source/AIPlayer.cpp include/AIPlayer.h source/GameManager.cpp include/GameManager.h source/RegularGameManager.cpp include/RegularGameManager.h source/GameLogic.cpp include/GameLogic.h source/RegularGameLogic.cpp include/RegularGameLogic.h)

set(TEST_FILES source/Player.cpp include/Player.h source/Board.cpp include/Board.h source/HumanPlayer.cpp include/HumanPlayer.h source/AIPlayer.cpp include/AIPlayer.h source/GameManager.cpp include/GameManager.h source/RegularGameManager.cpp include/RegularGameManager.h source/GameLogic.cpp include/GameLogic.h source/RegularGameLogic.cpp include/RegularGameLogic.h tests/main_test.cpp tests/test_Board.cpp tests/test_Board.h tests/test_AIPlayer.cpp tests/test_AIPlayer.h tests/test_HumanPlayer.cpp tests/test_HumanPlayer.h tests/test_RegularGameLogic.cpp tests/test_RegularGameLogic.h)

add_executable(Ex3_Test ${SOURCE_FILES} ${TEST_FILES} tests/main_test.cpp)
add_executable(Ex3_Game ${SOURCE_FILES} source/main.cpp)
target_link_libraries(Ex3_Test gtest gtest_main)
