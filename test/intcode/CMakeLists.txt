add_executable(test_intcode test_intcode.cpp)
target_link_libraries(test_intcode PRIVATE gtest_main
                                           intcode)

target_include_directories(test_intcode PUBLIC
    "${PROJECT_BINARY_DIR}/src"
    "${PROJECT_SOURCE_DIR}/src/intcode"
    )

add_test(test_advent test_intcode)
