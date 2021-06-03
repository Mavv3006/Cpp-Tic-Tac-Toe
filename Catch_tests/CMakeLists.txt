add_executable(Catch_tests_run TicTacToeTest.cpp UtilTest.cpp MinimaxTest.cpp states.h)
target_link_libraries(Catch_tests_run lib)