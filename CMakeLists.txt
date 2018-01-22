cmake_minimum_required(VERSION 3.8)
project(Ex3)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES src/Client/source/Player.cpp src/Client/include/Player.h src/Client/source/Board.cpp src/Client/include/Board.h src/Client/source/HumanPlayer.cpp src/Client/include/HumanPlayer.h src/Client/source/AIPlayer.cpp src/Client/include/AIPlayer.h src/Client/source/GameManager.cpp src/Client/include/GameManager.h src/Client/source/RegularGameManager.cpp src/Client/include/RegularGameManager.h src/Client/source/GameLogic.cpp src/Client/include/GameLogic.h src/Client/source/RegularGameLogic.cpp src/Client/include/RegularGameLogic.h src/Client/source/RemotePlayerReciver.cpp src/Client/include/RemotePlayerReciver.h src/Client/source/ServerConnector.cpp src/Client/include/ServerConnector.h src/Client/source/RemotePlayerSender.cpp src/Client/include/RemotePlayerSender.h)
set(TEST_FILES src/Client/source/Player.cpp src/Client/include/Player.h src/Client/source/Board.cpp src/Client/include/Board.h src/Client/source/HumanPlayer.cpp src/Client/include/HumanPlayer.h src/Client/source/AIPlayer.cpp src/Client/include/AIPlayer.h src/Client/source/GameManager.cpp src/Client/include/GameManager.h src/Client/source/RegularGameManager.cpp src/Client/include/RegularGameManager.h src/Client/source/GameLogic.cpp src/Client/include/GameLogic.h src/Client/source/RegularGameLogic.cpp src/Client/include/RegularGameLogic.h src/tests/main_test.cpp src/tests/test_Board.cpp src/tests/test_Board.h src/tests/test_AIPlayer.cpp src/tests/test_AIPlayer.h src/tests/test_HumanPlayer.cpp src/tests/test_HumanPlayer.h src/tests/test_RegularGameLogic.cpp src/tests/test_RegularGameLogic.h src/Client/source/RemotePlayerReciver.cpp src/Client/include/RemotePlayerReciver.h src/Server/Server.cpp src/Server/Server.h src/Client/source/ServerConnector.cpp src/Client/include/ServerConnector.h src/Client/source/RemotePlayerSender.cpp src/Client/include/RemotePlayerSender.h)
set(SERVER_FILES src/Server/Server.cpp src/Server/Server.h src/Server/Command.h src/Server/StartCommand.cpp src/Server/StartCommand.h src/Server/GameRoom.cpp src/Server/CommandManager.cpp src/Server/CommandManager.h src/Server/GamesHandler.cpp src/Server/GamesHandler.h src/Server/ListCommand.cpp src/Server/ListCommand.h src/Server/JoinCommand.cpp src/Server/JoinCommand.h src/Server/CloseCommand.cpp src/Server/CloseCommand.h src/Server/Task.h src/Server/ThreadPool.cpp src/Server/ThreadPool.h)

add_executable(Ex3_Server ${SERVER_FILES} src/Server/mainServer.cpp )
add_executable(Ex3_Test ${SOURCE_FILES} ${TEST_FILES} src/tests/main_test.cpp)
add_executable(Ex3_Game ${SOURCE_FILES} src/Client/source/main.cpp)
target_link_libraries(Ex3_Test gtest gtest_main)