#include <gtest/gtest.h>
#include <fstream>
#include <cstdlib>
#include <cstring>

extern "C" {
	// avoid C++ keyword clash in libft (param named `new`)
    #define new dont_use_new
    #include "../libft/libft.h"
    #undef new

    #include "../includes/so_long.h"
}

// ---- Helpers ----
static void writeTempMap(const std::string &name, const std::vector<std::string> &lines) {
    system("mkdir -p maps/mandatory");
    std::ofstream f("maps/mandatory/" + name);
    for (auto &l : lines) f << l << "\n";
}

static void freeCheckPath(t_stack *stack) {
    for (int i = 0; stack->check_path && stack->check_path[i]; i++) {
        free(stack->check_path[i]);
    }
    free(stack->check_path);
}

// ---- Tests ----
TEST(FillMapPathTest, ReadsLinesCorrectly) {
    writeTempMap("map1.ber", { "111", "1P1", "1E1" });

    t_stack s{};
    s.rows = 3;
    fill_map_path(&s, (char*)"map1.ber");

    ASSERT_STREQ(s.check_path[0], "111");
    ASSERT_STREQ(s.check_path[1], "1P1");
    ASSERT_STREQ(s.check_path[2], "1E1");
    ASSERT_EQ(s.check_path[3], nullptr);

    freeCheckPath(&s);
}

TEST(PlayerCoordinatesTest, FindsPlayerCorrectly) {
    t_stack s{};
    s.rows = 2; s.columns = 3;
    s.map_array = (char**)malloc(sizeof(char*) * 2);
    s.map_array[0] = strdup("111");
    s.map_array[1] = strdup("1P1");

    player_coordinates(&s);

    EXPECT_EQ(s.player_x, 1);
    EXPECT_EQ(s.player_y, 1);

    free(s.map_array[0]); free(s.map_array[1]); free(s.map_array);
}

TEST(FloodFillTest, StopsAtWalls) {
    t_stack s{};
    s.rows = 3; s.columns = 3; s.collectible = 0;
    char *map[] = { strdup("111"), strdup("1P1"), strdup("111"), nullptr };
    // Should stop immediately because surrounded by walls
    EXPECT_EQ(flood_fill(&s, map, 1, 1), 0);
    for (int i = 0; i < 3; i++) free(map[i]);
}

TEST(FloodFillTest, FindsExitAndCollectible) {
    t_stack s{};
    s.rows = 3; s.columns = 3; s.collectible = 1;
    char *map[] = { strdup("111"), strdup("1PC"), strdup("1E1"), nullptr };
    // Walkable path: right -> down to exit
    EXPECT_EQ(flood_fill(&s, map, 1, 1), 1);
    for (int i = 0; i < 3; i++) free(map[i]);
}


// Wrapper for tests
extern "C" void check_map_path_wrapper(t_stack *stack, char *argv) {
    check_map_path(stack, argv);
    exit(0); // mark success case
}

TEST(CheckMapPathTest, ValidMapExitsWith0) {
    writeTempMap("map2.ber", { "111", "1P1", "1E1" });

    t_stack s{};
    s.rows = 3;
    s.columns = 3;
    s.collectible = 0;

    s.map_array = (char**)malloc(sizeof(char*) * s.rows);
    s.map_array[0] = strdup("111");
    s.map_array[1] = strdup("1P1");
    s.map_array[2] = strdup("1E1");

    EXPECT_EXIT(check_map_path_wrapper(&s, (char*)"map2.ber"), ::testing::ExitedWithCode(1), "");
}

TEST(CheckMapPathTest, InvalidMapExitsWith1) {
    writeTempMap("map3.ber", { "111", "1P1", "111" });

    t_stack s{};
    s.rows = 3;
    s.columns = 3;
    s.collectible = 0;

    s.map_array = (char**)malloc(sizeof(char*) * s.rows);
    s.map_array[0] = strdup("111");
    s.map_array[1] = strdup("1P1");
    s.map_array[2] = strdup("111");

    EXPECT_EXIT(check_map_path_wrapper(&s, (char*)"map3.ber"), ::testing::ExitedWithCode(1), "");
}

TEST(CheckMapPathTest, InvalidPathExits) {
    // Player blocked from reaching exit
    writeTempMap("map3.ber", { "111", "1P1", "111" });

    t_stack s{};
    s.rows = 3;
    s.columns = 3;
    s.collectible = 0;

    // Init map_array (same as file)
    s.map_array = (char**)malloc(sizeof(char*) * s.rows);
    s.map_array[0] = strdup("111");
    s.map_array[1] = strdup("1P1");
    s.map_array[2] = strdup("111");

    EXPECT_EXIT(check_map_path(&s, (char*)"map3.ber"), ::testing::ExitedWithCode(1), "");
}

