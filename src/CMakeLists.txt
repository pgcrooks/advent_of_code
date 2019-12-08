configure_file(aoc_config.h.in aoc_config.h)

add_executable(advent_of_code
    main.cpp
    module.cpp)

target_include_directories(advent_of_code PUBLIC
                           "${PROJECT_BINARY_DIR}/src"
                           )
