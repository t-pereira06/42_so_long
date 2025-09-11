cmake_minimum_required(VERSION 3.10)
project(so_long C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

option(COVERAGE "Enable coverage flags" ON)

# ---- Include headers ----
include_directories(include libft)

# ---- Library with core game code (NO so_long.c) ----
file(GLOB SO_LONG_SOURCES CONFIGURE_DEPENDS mandatory/*.c)
list(REMOVE_ITEM SO_LONG_SOURCES ${CMAKE_SOURCE_DIR}/mandatory/so_long.c)

add_library(so_long ${SO_LONG_SOURCES})

# ---- Game executable (with so_long.c) ----
add_executable(so_long_game mandatory/so_long.c)
target_link_directories(so_long_game PRIVATE ${CMAKE_SOURCE_DIR}/minilibx-linux)
target_link_libraries(so_long_game
    PRIVATE
        so_long
        ${CMAKE_SOURCE_DIR}/libft/libft.a
        mlx
        X11
        Xext
        m
)

# ---- GoogleTest ----
enable_testing()
find_package(GTest REQUIRED)

# ---- Tests executable ----
file(GLOB TEST_SOURCES CONFIGURE_DEPENDS tests/*.cpp)

add_executable(test_suite ${TEST_SOURCES})
target_link_directories(test_suite PRIVATE ${CMAKE_SOURCE_DIR}/minilibx-linux)
target_link_libraries(test_suite
    PRIVATE
        so_long
        ${CMAKE_SOURCE_DIR}/libft/libft.a
        GTest::gtest
        GTest::gtest_main
        pthread
        mlx
        X11
        Xext
        m
)

# ---- Coverage flags (apply AFTER targets are defined) ----
if(COVERAGE)
  foreach(tgt IN ITEMS so_long so_long_game test_suite)
    target_compile_options(${tgt} PRIVATE -O0 -g --coverage)
    target_link_options(${tgt} PRIVATE --coverage)
  endforeach()
endif()


add_test(NAME test_suite COMMAND test_suite)
