#include "gtest/gtest.h"
#include "executor.h"
#include "executor2.h"
#include "newfunctions.h"

TEST (NewMyTest, FirstTest) { 
    EXPECT_EQ (145, calculate());
}

TEST (NewMyTest, SecondTest) { 
    const my_functor &op = my_functor(4);
    EXPECT_EQ (85, calculate2(op));
}
