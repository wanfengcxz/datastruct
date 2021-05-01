//
// Created by 晚风吹行舟 on 2021/5/1.
//
#include "gtest/gtest.h"
#include "problem.cpp"


class Queue2STest : public ::testing::Test {
protected:
    Queue2S queue;

protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {
        queue.push(1);
        queue.push(2);
        queue.push(3);
    }
};


TEST_F(Queue2STest, queue) {
    int e = 0;
    ASSERT_EQ(queue.empty(),false);
    ASSERT_EQ(queue.pop(e),true);
    ASSERT_EQ(e,1);
    ASSERT_EQ(queue.push(4),true);
    ASSERT_EQ(queue.pop(e), true);
    ASSERT_EQ(e,2);
    ASSERT_EQ(queue.pop(e), true);
    ASSERT_EQ(e,3);
    ASSERT_EQ(queue.pop(e), true);
    ASSERT_EQ(queue.pop(e), false);
    ASSERT_EQ(queue.empty(),true);
}
