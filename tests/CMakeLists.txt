
LIST(APPEND CMAKE_PREFIX_PATH "/Users/mattfalcone/home/root/")

FIND_PACKAGE(GTest REQUIRED)

ADD_EXECUTABLE(tic_tac_toe_tests tic_tac_toe_tests_main.cpp)
TARGET_LINK_LIBRARIES(tic_tac_toe_tests
        ttt_lib
        GTest::gtest_main
        )