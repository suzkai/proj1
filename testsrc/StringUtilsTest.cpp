#include <gtest/gtest.h>
#include "StringUtils.h"


// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }

TEST(StringUtilsTest, SliceTest){
    EXPECT_EQ(StringUtils::Slice("kai", 0, 3), "kai");
    EXPECT_EQ(StringUtils::Slice("kai", 0, 10), "kai");
    EXPECT_EQ(StringUtils::Slice("kai", 3, 3), "");
    EXPECT_EQ(StringUtils::Slice("kai", -3, 3), "kai");
    EXPECT_EQ(StringUtils::Slice("kai", 1, 2), "a");
}

TEST(StringUtilsTest, Capitalize){
    EXPECT_EQ(StringUtils::Capitalize("hello"), "Hello");
    EXPECT_EQ(StringUtils::Capitalize("HELLO"), "Hello");
    EXPECT_EQ(StringUtils::Capitalize("hELLo"), "Hello");
    EXPECT_EQ(StringUtils::Capitalize(""), "");
    EXPECT_EQ(StringUtils::Capitalize("h"), "H");
}

TEST(StringUtilsTest, Upper){
    EXPECT_EQ(StringUtils::Capitalize("hello"), "Hello");
    EXPECT_EQ(StringUtils::Capitalize("HELLO"), "Hello");
    EXPECT_EQ(StringUtils::Capitalize("hELLo"), "Hello");
    EXPECT_EQ(StringUtils::Capitalize(""), "");
    EXPECT_EQ(StringUtils::Capitalize("h"), "H");
}

TEST(StringUtilsTest, Lower){
    EXPECT_EQ(StringUtils::Lower("hello"), "hello");
    EXPECT_EQ(StringUtils::Lower("HELLO"), "hello");
    EXPECT_EQ(StringUtils::Lower("hELLo"), "hello");
    EXPECT_EQ(StringUtils::Lower(""), "");
    EXPECT_EQ(StringUtils::Lower("h"), "h");
}

TEST(StringUtilsTest, LStrip){
    EXPECT_EQ(StringUtils::LStrip("  hello"), "hello");
    EXPECT_EQ(StringUtils::LStrip("hello  "), "hello  ");
    EXPECT_EQ(StringUtils::LStrip("  hello  "), "hello  ");
    EXPECT_EQ(StringUtils::LStrip("hello"), "hello");
    EXPECT_EQ(StringUtils::LStrip(""), "");
}

TEST(StringUtilsTest, RStrip){
    EXPECT_EQ(StringUtils::RStrip("  hello"), "  hello");
    EXPECT_EQ(StringUtils::RStrip("hello  "), "hello");
    EXPECT_EQ(StringUtils::RStrip("  hello  "), "  hello");
    EXPECT_EQ(StringUtils::RStrip("hello"), "hello");
    EXPECT_EQ(StringUtils::RStrip(""), "");
}

TEST(StringUtilsTest, Strip){
    EXPECT_EQ(StringUtils::Strip("  hello"), "hello");
    EXPECT_EQ(StringUtils::Strip("hello  "), "hello");
    EXPECT_EQ(StringUtils::Strip("  hello  "), "hello");
    EXPECT_EQ(StringUtils::Strip("hello"), "hello");
    EXPECT_EQ(StringUtils::Strip(""), "");
}

TEST(StringUtilsTest, Center){
    EXPECT_EQ(StringUtils::Center("hello", 9, '-'), "--hello--");
    EXPECT_EQ(StringUtils::Center("hello", 10, '*'), "**hello***");
    EXPECT_EQ(StringUtils::Center("hello", 5), "hello");
    EXPECT_EQ(StringUtils::Center("hello", 4), "hello");
    EXPECT_EQ(StringUtils::Center("", 5, '0'), "00000");
}

TEST(StringUtilsTest, LJust){
    EXPECT_EQ(StringUtils::LJust("hello", 9), "hello    ");
    EXPECT_EQ(StringUtils::LJust("hello", 10), "hello     ");
    EXPECT_EQ(StringUtils::LJust("hello", 5), "hello");
    EXPECT_EQ(StringUtils::LJust("hello", 4), "hello");
    EXPECT_EQ(StringUtils::LJust("", 5), "     ");
}

TEST(StringUtilsTest, RJust){
    EXPECT_EQ(StringUtils::RJust("hello", 9), "    hello");
    EXPECT_EQ(StringUtils::RJust("hello", 10), "     hello");
    EXPECT_EQ(StringUtils::RJust("hello", 5), "hello");
    EXPECT_EQ(StringUtils::RJust("hello", 4), "hello");
    EXPECT_EQ(StringUtils::RJust("", 5), "     ");
}

TEST(StringUtilsTest, Replace){
    EXPECT_EQ(StringUtils::Replace("pls gtest work", " ", "_"), "pls_gtest_work");
    EXPECT_EQ(StringUtils::Replace("pls gtest work", "pls", "please"), "please gtest work");
    EXPECT_EQ(StringUtils::Replace("pls gtest work", "ecs", "wd;ianef"), "pls gtest work");
}

TEST(StringUtilsTest, Split){
    EXPECT_EQ(StringUtils::Split("pls gtest work", " "), (std::vector<std::string>{"pls", "gtest", "work"}));
    EXPECT_EQ(StringUtils::Split("pls gtest work", "t"), (std::vector<std::string>{"pls g", "es", " work"}));
    EXPECT_EQ(StringUtils::Split("pls gtest work", "AHAW"), (std::vector<std::string>{"pls gtest work"}));
}

TEST(StringUtilsTest, Join){
    std::vector<std::string> vec = {"pls", "gtest", "work"};
    EXPECT_EQ(StringUtils::Join(" ", vec), "pls gtest work");
    EXPECT_EQ(StringUtils::Join("", vec), "plsgtestwork");
    EXPECT_EQ(StringUtils::Join(".-.-.", vec), "pls.-.-.gtest.-.-.work");

}

TEST(StringUtilsTest, ExpandTabs){
    EXPECT_EQ(StringUtils::ExpandTabs("pls\tgtest\twork", 2), "pls  gtest  work");
    EXPECT_EQ(StringUtils::ExpandTabs("", 4), "");
}

TEST(StringUtilsTest, EditDistance){
    EXPECT_EQ(StringUtils::EditDistance("kitten", "sitting", false), 3);
    EXPECT_EQ(StringUtils::EditDistance("flaw", "lawn", false), 2);
    EXPECT_EQ(StringUtils::EditDistance("", "hello", false), 5);
    EXPECT_EQ(StringUtils::EditDistance("hello", "", false), 5);
    EXPECT_EQ(StringUtils::EditDistance("kai", "Kai", false), 1);
    EXPECT_EQ(StringUtils::EditDistance("kai", "Kai", true), 0);
}

// g++ -std=c++17 -I ./include/ -isystem /user/src/googletest/googletest/include -pthread /usr/lib/x86_64-linux-gnu/libgtest.a /usr/lib/x86_64-linux-gnu/libgtest_main.a testsrc/StringUtilsTest.cpp src/StringUtils.cpp -o StringUtilsTest