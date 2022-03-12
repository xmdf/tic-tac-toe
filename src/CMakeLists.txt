
SET(ttt_header_files
        board.hpp
        tic_tac_toe.hpp
        )

SET(ttt_source_files
        board.cpp
        tic_tac_toe.cpp
        )

ADD_LIBRARY(ttt_lib SHARED
        "${ttt_source_files}"
        "${ttt_header_files}"
        )

SET_TARGET_PROPERTIES(ttt_lib PROPERTIES
        VERSION ${CMAKE_PROJECT_VERSION}
        SOVERSION 1
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

TARGET_INCLUDE_DIRECTORIES(ttt_lib PUBLIC
        "${CMAKE_BINARY_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}"
        )

ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main
        ttt_lib
        )