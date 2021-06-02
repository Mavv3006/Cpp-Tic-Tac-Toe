project(lib)

set(HEADER_FILES Minimax.h Util.h TicTacToe.h)

set(SOURCE_FILES Minimax.cpp TicTacToe.cpp)

add_library(lib STATIC ${SOURCE_FILES} ${HEADER_FILES})