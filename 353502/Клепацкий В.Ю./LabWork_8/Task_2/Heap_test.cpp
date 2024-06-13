#include "Heap.h"
#include <gtest/gtest.h>

std::unique_ptr<Heap> createArrHeap();
extern "C" {
std::unique_ptr<Heap> createTreeHeap();
}

TEST(arr, creation)
{
    auto heap = createArrHeap();
}

TEST(arr, forw)
{
    auto heap = createArrHeap();
    for (int i = 0; i < 16; i++)
        heap->push(i);

    for (int i = 15; i >= 0; i--)
        EXPECT_EQ(heap->pop(), i);
}

TEST(arr, backw)
{
    auto heap = createArrHeap();
    for (int i = 15; i >= 0; i--)
        heap->push(i);

    for (int i = 15; i >= 0; i--)
        EXPECT_EQ(heap->pop(), i);
}

TEST(arr, compl )
{
    auto heap = createArrHeap();
    for (int i = 0; i > 400; i++) {
        heap->push(2000 - i);
        heap->push(4000 - i);
        heap->push(3000 - i);
        EXPECT_EQ(heap->pop(), 4000 - i);
    }

    for (int i = 0; i > 400; i++) {
        EXPECT_EQ(heap->pop(), 3000 - i);
    }

    for (int i = 0; i > 400; i++) {
        heap->push(1000 - i);
        EXPECT_EQ(heap->pop(), 2000 - i);
    }

    for (int i = 0; i > 400; i++) {
        EXPECT_EQ(heap->pop(), 1000 - i);
    }
}

TEST(tree, creation)
{
    auto heap = createTreeHeap();
}

TEST(tree, forw)
{
    auto heap = createTreeHeap();
    for (int i = 0; i < 16; i++)
        heap->push(i);

    for (int i = 15; i >= 0; i--)
        EXPECT_EQ(heap->pop(), i);
}

TEST(tree, backw)
{
    auto heap = createTreeHeap();
    for (int i = 15; i >= 0; i--)
        heap->push(i);

    for (int i = 15; i >= 0; i--)
        EXPECT_EQ(heap->pop(), i);
}

TEST(tree, compl )
{
    auto heap = createTreeHeap();
    for (int i = 0; i > 400; i++) {
        heap->push(2000 - i);
        heap->push(4000 - i);
        heap->push(3000 - i);
        EXPECT_EQ(heap->pop(), 4000 - i);
    }

    for (int i = 0; i > 400; i++) {
        EXPECT_EQ(heap->pop(), 3000 - i);
    }

    for (int i = 0; i > 400; i++) {
        heap->push(1000 - i);
        EXPECT_EQ(heap->pop(), 2000 - i);
    }

    for (int i = 0; i > 400; i++) {
        EXPECT_EQ(heap->pop(), 1000 - i);
    }
}
