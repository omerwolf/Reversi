cmake_minimum_required(VERSION 3.8)
project(Ex3)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES src/Client/source/Player.cpp Client/include/Player.h Client/source/Board.cpp Client/include/Board.h Client/source/HumanPlayer.cpp Client/include/HumanPlayer.h Client/source/AIPlayer.cpp Client/include/AIPlayer.h Client/source/GameManager.cpp Client/include/GameManager.h Client/source/RegularGameManager.cpp Client/include/RegularGameManager.h Client/source/GameLogic.cpp Client/include/GameLogic.h Client/source/RegularGameLogic.cpp Client/include/RegularGameLogic.h Client/source/RemotePlayerReciver.cpp Client/include/RemotePlayerReciver.h Server/Server.cpp Server/Server.h Client/source/ServerConnector.cpp Client/include/ServerConnector.h Client/source/RemotePlayerSender.cpp Client/include/RemotePlayerSender.h)
set(TEST_FILES Client/source/Player.cpp Client/include/Player.h Client/source/Board.cpp Client/include/Board.h Client/source/HumanPlayer.cpp Client/include/HumanPlayer.h Client/source/AIPlayer.cpp Client/include/AIPlayer.h Client/source/GameManager.cpp Client/include/GameManager.h Client/source/RegularGameManager.cpp Client/include/RegularGameManager.h Client/source/GameLogic.cpp Client/include/GameLogic.h Client/source/RegularGameLogic.cpp Client/include/RegularGameLogic.h tests/main_test.cpp tests/test_Board.cpp tests/test_Board.h tests/test_AIPlayer.cpp tests/test_AIPlayer.h tests/test_HumanPlayer.cpp tests/test_HumanPlayer.h tests/test_RegularGameLogic.cpp tests/test_RegularGameLogic.h Client/source/RemotePlayerReciver.cpp Client/include/RemotePlayerReciver.h Server/Server.cpp Server/Server.h Client/source/ServerConnector.cpp Client/include/ServerConnector.h Client/source/RemotePlayerSender.cpp Client/include/RemotePlayerSender.h)
set(SERVER_FILES src/Server/Server.cpp src/Server/Server.h)

add_executable(Ex3_Server ${SERVER_FILES} Server/mainServer.cpp )
add_executable(Ex3_Test ${SOURCE_FILES} ${TEST_FILES} tests/main_test.cpp)
add_executable(Ex3_Game ${SOURCE_FILES} Client/source/main.cpp)
target_link_libraries(Ex3_Test gtest gtest_main)