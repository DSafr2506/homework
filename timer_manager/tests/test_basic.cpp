#include <gtest/gtest.h>
#include "library.hpp"


TEST(EventSchedulerTest, Basic) {
    template_library::EventScheduler es;
    es.add_event(5, "Backup");
    es.add_event(2, "Update");
    es.add_event(10, "Restart");
    EXPECT_EQ(es.process_next(), "Update");
    EXPECT_EQ(es.process_next(), "Backup");
    EXPECT_EQ(es.process_next(), "Restart");
}

TEST(EventSchedulerTest, DuplicateTimes) {
    template_library::EventScheduler es;
    es.add_event(5, "Backup");
    es.add_event(5, "Update"); // Перезапись
    EXPECT_EQ(es.process_next(), "Update");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}