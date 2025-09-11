#include <gtest/gtest.h>

extern "C" {
    // avoid C++ keyword clash in libft (param named `new`)
    #define new dont_use_new
    #include "../libft/libft.h"
    #undef new

    #include "../includes/so_long.h"
}

// count_char_in_line

TEST(CountCharInLineTest, ValidRectangularMap) {
    char *map[] = {
        (char*)"111",
        (char*)"101",
        (char*)"111",
        nullptr
    };
    EXPECT_EQ(count_char_in_line(map, 3, 3), 1);
}

TEST(CountCharInLineTest, ShortRowReturnsZero) {
    char *map[] = {
        (char*)"111",
        (char*)"10",   // too short
        (char*)"111",
        nullptr
    };
    EXPECT_EQ(count_char_in_line(map, 3, 3), 0);
}

TEST(CountCharInLineTest, LongRowReturnsZero) {
    char *map[] = {
        (char*)"111",
        (char*)"1001", // too long
        (char*)"111",
        nullptr
    };
    EXPECT_EQ(count_char_in_line(map, 3, 3), 0);
}

TEST(CountCharInLineTest, SingleRowAlwaysValid) {
    char *map[] = {
        (char*)"111",
        nullptr
    };
    EXPECT_EQ(count_char_in_line(map, 1, 3), 1);
}

TEST(CountCharInLineTest, ZeroRowsAlwaysValid) {
    EXPECT_EQ(count_char_in_line(nullptr, 0, 3), 1);
}

// surrounded_by_walls function
TEST(SurroundedByWallsTest, ValidMap) {
    char *map[] = {
        (char*)"1111",
        (char*)"1001",
        (char*)"1011",
        (char*)"1111",
        nullptr
    };
    EXPECT_EQ(surrounded_by_walls(map, 4, 4), 1);
}

TEST(SurroundedByWallsTest, TopRowHasGap) {
    char *map[] = {
        (char*)"1101",  // gap at position 2
        (char*)"1001",
        (char*)"1111",
        nullptr
    };
    EXPECT_EQ(surrounded_by_walls(map, 3, 4), 0);
}

TEST(SurroundedByWallsTest, BottomRowHasGap) {
    char *map[] = {
        (char*)"1111",
        (char*)"1001",
        (char*)"1101",  // gap at bottom
        nullptr
    };
    EXPECT_EQ(surrounded_by_walls(map, 3, 4), 0);
}

TEST(SurroundedByWallsTest, MiddleRowLeftNotWall) {
    char *map[] = {
        (char*)"1111",
        (char*)"0001",  // left side not wall
        (char*)"1111",
        nullptr
    };
    EXPECT_EQ(surrounded_by_walls(map, 3, 4), 0);
}

TEST(SurroundedByWallsTest, MiddleRowRightNotWall) {
    char *map[] = {
        (char*)"1111",
        (char*)"1000",  // right side not wall
        (char*)"1111",
        nullptr
    };
    EXPECT_EQ(surrounded_by_walls(map, 3, 4), 0);
}

TEST(SurroundedByWallsTest, Minimal3x3ValidMap) {
    char *map[] = {
        (char*)"111",
        (char*)"101",
        (char*)"111",
        nullptr
    };
    EXPECT_EQ(surrounded_by_walls(map, 3, 3), 1);
}

// check_map_size function
// ---- Helpers ----
static t_stack make_stack(char **lines, int rows, int cols) {
    t_stack s{};
    s.rows = rows;
    s.columns = cols;
    s.map_array = (char**)malloc(sizeof(char*) * rows);
    for (int i = 0; i < rows; i++) {
        s.map_array[i] = strdup(lines[i]);
    }
    return s;
}

// ---- Tests ----
TEST(CheckMapSizeTest, ValidMapDoesNotExit) {
    char *lines[] = {
        (char*)"111",
        (char*)"101",
        (char*)"111"
    };
    t_stack stack = make_stack(lines, 3, 3);

    EXPECT_NO_FATAL_FAILURE(check_map_size(&stack));

    free_map(&stack); // manual cleanup since no exit
}

TEST(CheckMapSizeTest, InvalidShapeExits) {
    char *lines[] = {
        (char*)"111",
        (char*)"10",   // shorter than 3
        (char*)"111"
    };
    t_stack stack = make_stack(lines, 3, 3);

	EXPECT_EXIT(check_map_size(&stack), ::testing::ExitedWithCode(1), "");
}

TEST(CheckMapSizeTest, NotSurroundedByWallsExits) {
    char *lines[] = {
        (char*)"111",
        (char*)"100",  // right wall missing
        (char*)"111"
    };
    t_stack stack = make_stack(lines, 3, 3);
	EXPECT_EXIT(check_map_size(&stack), ::testing::ExitedWithCode(1), "");
}
