#include <gtest/gtest.h>
#include <algorithm>
#include "library.hpp"


TEST(AutoCompleteTest, Basic) {
    template_library::AutoComplete ac;
    ac.insert("apple");
    ac.insert("app");
    ac.insert("application");

    auto result = ac.suggest("ap");
    ASSERT_EQ(result.size(), 3);
    EXPECT_NE(std::find_if(result.begin(), result.end(), [](const auto &value) { return value == "app"; }),
              result.end());
    EXPECT_NE(std::find_if(result.begin(), result.end(), [](const auto &value) { return value == "apple"; }),
              result.end());
}

TEST(AutoCompleteTest, EmptyPrefix) {
    template_library::AutoComplete ac;
    ac.insert("test");
    EXPECT_EQ(ac.suggest("").size(), 1); // Все слова
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}