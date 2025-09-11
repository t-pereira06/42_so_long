#include <gtest/gtest.h>

extern "C" {
    int check_extension(char *arg);
	int check_args(int arg_count, char **args);
}

static char* make_cstr(const char* s) {
    char* c = (char*)malloc(strlen(s) + 1);
    strcpy(c, s);
    return c;
}

// check_extension function tests

TEST(TestArgs, ValidExtension) {
    char filename[] = "map.ber";
    EXPECT_EQ(check_extension(filename), 1);
}

TEST(TestArgs, ValidExtensionWithPath) {
    char filename[] = "levels/first_level.ber";
    EXPECT_EQ(check_extension(filename), 1);
}

TEST(TestArgs, WrongExtension) {
    char filename[] = "map.txt";
    EXPECT_EQ(check_extension(filename), 0);
}

TEST(TestArgs, NoExtension) {
    char filename[] = "map";
    EXPECT_EQ(check_extension(filename), 0);
}

TEST(TestArgs, DotButNoExtension) {
    char filename[] = "map.";
    EXPECT_EQ(check_extension(filename), 0);
}

TEST(TestArgs, MultipleDots) {
    char filename[] = "backup.map.ber";
    EXPECT_EQ(check_extension(filename), 1);
}

TEST(TestArgs, SimilarButWrong) {
    char filename[] = "map.beR"; // wrong case
    EXPECT_EQ(check_extension(filename), 0);
}

TEST(TestArgs, EmptyString) {
    char filename[] = "";
    EXPECT_EQ(check_extension(filename), 0);
}

// check_args function tests

TEST(CheckArgsTest, WrongArgCount) {
    char* argv[] = { (char*)"so_long" };
    EXPECT_EXIT(check_args(2, argv), ::testing::ExitedWithCode(1), "");
}

TEST(CheckArgsTest, InvalidExtension) {
    char* argv[] = { (char*)"so_long", make_cstr("level.txt") };
    EXPECT_EXIT(check_args(2, argv), ::testing::ExitedWithCode(1), "");
    free(argv[1]);
}

TEST(CheckArgsTest, InvalidFile) {
    char* argv[] = { (char*)"so_long", make_cstr("notfound.ber") };
    EXPECT_EXIT(check_args(2, argv), ::testing::ExitedWithCode(1), "");
    free(argv[1]);
}

TEST(CheckArgsTest, ValidFile) {
    // Create a temporary .ber file inside ./maps/mandatory/
    system("mkdir -p maps/mandatory && echo 'test' > maps/mandatory/test.ber");

    char* argv[] = { (char*)"so_long", make_cstr("test.ber") };
    EXPECT_EQ(check_args(2, argv), 1);

    free(argv[1]);
}

