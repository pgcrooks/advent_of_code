add_subdirectory(io)
add_subdirectory(intcode)
add_subdirectory(module)

configure_file(aoc_config.h.in aoc_config.h)

add_executable(advent_of_code main.cpp)

target_link_libraries(advent_of_code PUBLIC module
                                            io
                                            intcode)

target_include_directories(advent_of_code PUBLIC
                           "${PROJECT_BINARY_DIR}/src"
                           "${PROJECT_SOURCE_DIR}/src/module"
                           "${PROJECT_SOURCE_DIR}/src/io"
                           "${PROJECT_SOURCE_DIR}/src/intcode"
                           "${PROJECT_SOURCE_DIR}/thirdparty/cxxopts"
                           )
