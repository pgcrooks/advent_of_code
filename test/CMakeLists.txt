add_executable(test_module test_module.cpp)
target_link_libraries(test_module PRIVATE gtest_main
                                          module)

target_include_directories(test_module PUBLIC
    "${PROJECT_BINARY_DIR}/src"
    "${PROJECT_SOURCE_DIR}/src/module"
    )

add_test(test_advent test_module)
