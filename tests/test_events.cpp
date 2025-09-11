#include <gtest/gtest.h>

extern "C" {
    // avoid C++ keyword clash in libft (param named `new`)
    #define new dont_use_new
    #include "../libft/libft.h"
    #undef new

    #include "../includes/so_long.h"

    // Fake key codes (adjust to your real values)
	#define ESC 65307
	#define W   119
	#define A   97
	#define S   115
	#define D   100

    int handle_moves(int keysys, t_stack *stack);
    void player_moves(t_stack *stack, char move);
}

// ---- Global flags for test verification ----
static char last_move = '\0';
static bool free_called = false;

extern "C" void player_moves(t_stack *stack, char move) {
    last_move = move;
}

TEST(HandleMovesTest, WKeyCallsPlayerMoves) {
    t_stack dummy{};
    last_move = '\0';
    handle_moves(W, &dummy);
    EXPECT_EQ(last_move, 'W');
}

TEST(HandleMovesTest, AKeyCallsPlayerMoves) {
    t_stack dummy{};
    last_move = '\0';
    handle_moves(A, &dummy);
    EXPECT_EQ(last_move, 'A');
}

TEST(HandleMovesTest, SKeyCallsPlayerMoves) {
    t_stack dummy{};
    last_move = '\0';
    handle_moves(S, &dummy);
    EXPECT_EQ(last_move, 'S');
}

TEST(HandleMovesTest, DKeyCallsPlayerMoves) {
    t_stack dummy{};
    last_move = '\0';
    handle_moves(D, &dummy);
    EXPECT_EQ(last_move, 'D');
}

TEST(HandleMovesTest, OtherKeyDoesNothing) {
    t_stack dummy{};
    last_move = '\0';
    int ret = handle_moves(999, &dummy); // some irrelevant key
    EXPECT_EQ(ret, 0);
    EXPECT_EQ(last_move, '\0'); // player_moves not called
}
