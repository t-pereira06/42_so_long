#include <gtest/gtest.h>
#include <cstdlib>

extern "C" {
    // avoid C++ keyword clash in libft (param named `new`)
    #define new dont_use_new
    #include "../libft/libft.h"
    #undef new

    #include "../includes/so_long.h"

    void free_map(t_stack *stack);
}

TEST(FreeMapTest, FreesAllRows) {
    t_stack stack{};
    stack.rows = 3;

    // Allocate fake map
    stack.map_array = (char**)malloc(sizeof(char*) * stack.rows);
    for (int i = 0; i < stack.rows; i++) {
        stack.map_array[i] = (char*)malloc(10);
        strcpy(stack.map_array[i], "dummy");
    }

    // Should not crash
    EXPECT_NO_FATAL_FAILURE(free_map(&stack));
}

TEST(FreeMapTest, ZeroRows) {
    t_stack stack{};
    stack.rows = 0;
    stack.map_array = (char**)malloc(sizeof(char*) * 1); // outer array only

    EXPECT_NO_FATAL_FAILURE(free_map(&stack));
}

TEST(FreeMapTest, NullArray) {
    t_stack stack{};
    stack.rows = 3;
    stack.map_array = NULL;

    // This would segfault in current implementation,
    // but if you want to allow it, you'd need a NULL guard in free_map.
    // For now, we just EXPECT_DEATH to confirm it crashes.
    EXPECT_DEATH(free_map(&stack), ".*");
}
