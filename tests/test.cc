#include "gtest/gtest.h"
#include "executor.h"
#include "run.h"

TEST (NewMyTest, FirstTest) { 
    EXPECT_EQ (145, calculate());
}

TEST (NewMyTest, SecondTest) { 
    EXPECT_EQ (85, run());
}
