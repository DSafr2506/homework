#include <gtest/gtest.h>
#include "library.hpp"

#include <gtest/gtest.h>

TEST(JosephusProblemTest, BasicCases) {
    // Пример из условия
    EXPECT_EQ(template_library::josephus_problem({1,2,3,4,5,6,7}, 3), 4);

    // K=1 (удаление по порядку)
    EXPECT_EQ(template_library::josephus_problem({1,2,3,4}, 1), 4);

    // K превышает размер массива
    EXPECT_EQ(template_library::josephus_problem({1,2,3}, 5), 2); // 5 mod 3 = 2 → порядок удаления: 2, 1 → остаётся 3
}

TEST(JosephusProblemTest, EdgeCases) {
    // Массив из одного элемента
    EXPECT_EQ(template_library::josephus_problem({42}, 10), 42);

    // K=2, чётный размер
    EXPECT_EQ(template_library::josephus_problem({1,2,3,4}, 2), 1); // Удаляются 2 → 4 → 3 → остаётся 1
}

TEST(JosephusProblemTest, SpecialCases) {
    // K=2, нечётный размер
    EXPECT_EQ(template_library::josephus_problem({1,2,3,4,5}, 2), 3);

    // Все элементы удаляются за один круг
    EXPECT_EQ(template_library::josephus_problem({1,2,3,4}, 4), 2); // Удаляются 4 → 1 → 3 → остаётся 2
}

TEST(JosephusProblemTest, LargeInput) {
    std::vector<int> big_array(1000);
    for (int i = 0; i < 1000; ++i) big_array[i] = i + 1;
    EXPECT_EQ(template_library::josephus_problem(big_array, 7), 674); // Проверка для большого N
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}