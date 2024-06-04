#include "Deque.h"
#include <gtest/gtest.h>

TEST(basic, creation) { Deque<int> q; }

TEST(basic, pushpo_back) {
  Deque<int> q;
  q.push_back(1);
  q.push_back(2);
  q.push_back(3);
  q.push_back(4);
  EXPECT_EQ(q.pop_back(), 4);
  EXPECT_EQ(q.pop_back(), 3);
  EXPECT_EQ(q.pop_back(), 2);
  EXPECT_EQ(q.pop_back(), 1);
}

TEST(big, pushpo_back) {
  Deque<int> q;

  for (int i = 0; i < 1024; i++) {
    q.push_back(i);
  }

  for (int i = 1023; i >= 0; i--) {
    EXPECT_EQ(q.pop_back(), i);
  }
}

TEST(basic, pushpo_front) {
  Deque<int> q;
  q.push_front(1);
  q.push_front(2);
  q.push_front(3);
  q.push_front(4);
  EXPECT_EQ(q.pop_front(), 4);
  EXPECT_EQ(q.pop_front(), 3);
  EXPECT_EQ(q.pop_front(), 2);
  EXPECT_EQ(q.pop_front(), 1);
}

TEST(big, pushpo_front) {
  Deque<int> q;

  for (int i = 0; i < 1024; i++) {
    q.push_front(i);
  }

  for (int i = 1023; i >= 0; i--) {
    EXPECT_EQ(q.pop_front(), i);
  }
}

TEST(basic, queue) {
  Deque<int> q;
  q.push_back(1);
  q.push_back(2);
  q.push_back(3);
  q.push_back(4);

  EXPECT_EQ(q.size(), 4);

  EXPECT_EQ(q.pop_front(), 1);
  EXPECT_EQ(q.pop_front(), 2);
  EXPECT_EQ(q.pop_front(), 3);
  EXPECT_EQ(q.pop_front(), 4);
}

TEST(basic, queue_rev) {
  Deque<int> q;
  q.push_front(1);
  q.push_front(2);
  q.push_front(3);
  q.push_front(4);

  EXPECT_EQ(q.size(), 4);

  EXPECT_EQ(q.pop_back(), 1);
  EXPECT_EQ(q.pop_back(), 2);
  EXPECT_EQ(q.pop_back(), 3);
  EXPECT_EQ(q.pop_back(), 4);
}

TEST(big, queue) {
  Deque<int> q;

  for (int i = 0; i < 1024; i++) {
    q.push_back(i);
  }

  EXPECT_EQ(q.size(), 1024);

  for (int i = 0; i < 1024; i++) {
    EXPECT_EQ(q.pop_front(), i);
  }
}

TEST(big, queue_rev) {
  Deque<int> q;

  for (int i = 0; i < 1024; i++) {
    q.push_front(i);
  }

  EXPECT_EQ(q.size(), 1024);

  for (int i = 0; i < 1024; i++) {
    EXPECT_EQ(q.pop_back(), i);
  }
}

TEST(big, double) {
  Deque<int> q;

  for (int i = 0; i < 1024; i++) {
    q.push_front(i);
    q.push_back(i);
  }

  EXPECT_EQ(q.size(), 2048);

  for (int i = 1023; i >= 0; i--) {
    EXPECT_EQ(q.pop_front(), i);
    EXPECT_EQ(q.pop_back(), i);
  }
}

TEST(big, double_front_read) {
  Deque<int> q;

  for (int i = 0; i < 1024; i++) {
    q.push_front(i);
    q.push_back(i);
  }

  EXPECT_EQ(q.size(), 2048);

  for (int i = 1023; i >= 0; i--) {
    EXPECT_EQ(q.pop_front(), i);
  }

  for (int i = 0; i < 1024; i++) {
    EXPECT_EQ(q.pop_front(), i);
  }
}

TEST(mem, stringer_stacky) {
  Deque<std::string> q;

  std::string exs[4] = {"aaa", "bbb", "rrr", "ggg"};

  for (int i = 0; i < 1024; i++) {
    q.push_front(exs[i % 4]);
    q.push_back(exs[i % 4]);
  }

  EXPECT_EQ(q.size(), 2048);

  for (int i = 1023; i >= 0; i--) {
    EXPECT_EQ(q.pop_front(), exs[i % 4]);
    EXPECT_EQ(q.pop_back(), exs[i % 4]);
  }
}


TEST(mem, stringer_queue) {
  Deque<std::string> q;

  std::string exs[4] = {"aaa", "bbb", "rrr", "ggg"};

  for (int i = 0; i < 1024; i++) {
    q.push_front(exs[i % 4]);
    q.push_back(exs[i % 4]);
  }

  EXPECT_EQ(q.size(), 2048);

  for (int i = 1023; i >= 0; i--) {
    EXPECT_EQ(q.pop_front(), exs[i % 4]);
  }

  for (int i = 0; i < 1024; i++) {
    EXPECT_EQ(q.pop_front(), exs[i % 4]);
  }
}


TEST(mem, test_copy) {
  Deque<std::string> q;

  std::string exs[4] = {"aaa", "bbb", "rrr", "ggg"};

  for (int i = 0; i < 1024; i++) {
    q.push_front(exs[i % 4]);
    q.push_back(exs[i % 4]);
  }

  Deque<std::string> q2(q);
  
  Deque<std::string> q3;
  q3.push_back("123123321");
  q3 = q;

  EXPECT_EQ(q2.size(), 2048);
  EXPECT_EQ(q3.size(), 2048);

  for (int i = 1023; i >= 0; i--) {
    EXPECT_EQ(q2.pop_front(), exs[i % 4]);
    EXPECT_EQ(q3.pop_front(), exs[i % 4]);
  }

  for (int i = 0; i < 1024; i++) {
    EXPECT_EQ(q2.pop_front(), exs[i % 4]);
    EXPECT_EQ(q3.pop_front(), exs[i % 4]);
  }

  EXPECT_EQ(q.size(), 2048);
}

TEST(mem, test_move) {
  Deque<std::string> q;

  std::string exs[4] = {"aaa", "bbb", "rrr", "ggg"};

  for (int i = 0; i < 1024; i++) {
    q.push_front(exs[i % 4]);
    q.push_back(exs[i % 4]);
  }

  Deque<std::string> q2 = std::move(q);
  
  EXPECT_EQ(q2.size(), 2048);
  EXPECT_EQ(q.size(), 0);

  for (int i = 1023; i >= 0; i--) {
    EXPECT_EQ(q2.pop_front(), exs[i % 4]);
  }

  for (int i = 0; i < 1024; i++) {
    EXPECT_EQ(q2.pop_front(), exs[i % 4]);
  }
}

TEST(access, rand_access) {
  Deque<int> q;

  for (int i = 0; i < 1024; i++) {
    q.push_back(i);
  }

  EXPECT_EQ(q.size(), 1024);

  for (int i = 0; i < 1024; i++) {
    EXPECT_EQ(q[i], i);
  }
}


TEST(access, rand_access_rev) {
  Deque<int> q;

  for (int i = 0; i < 1024; i++) {
    q.push_front(i);
  }

  EXPECT_EQ(q.size(), 1024);

  for (int i = 0; i < 1024; i++) {
    int vvv = q[i];
    EXPECT_EQ(vvv, 1023 - i);
  }
}


TEST(access, iter) {
  Deque<int> q;

  for (int i = 0; i < 1024; i++) {
    q.push_back(i);
    q.push_front(i);
  }

  int step = -1;
  int cur = 1024;
  for(auto el: q) {
    cur += step;
    EXPECT_EQ(el, cur);
    if(cur == 0 && step == -1) {
      step = 1;
      cur = -1;
    }
  }
}


TEST(access, iter_step_over) {
  Deque<int> q;

  for (int i = 0; i < 1024; i++) {
    q.push_back(i);
  }

  int cur = 0;
  int step = 2;
  for(auto it = q.begin(); it != q.end(); it+=2) {
    EXPECT_EQ(*it, cur);
    cur += step;
  }
}

TEST(access, invalidate) {
  Deque<int> q;

  for (int i = 0; i < 1024; i++) {
    q.push_back(i);
  }

  auto it = q.begin();
  
  for (int i = 8000; i < 9024; i++) {
    q.push_front(i);
  }

  EXPECT_EQ(*it, 9023);
}

TEST(regression, onefront) {
  Deque<int> q;
  q.push_front(100);

  EXPECT_EQ(q[0], 100);
  
  for(auto e: q) {
    EXPECT_EQ(e, 100);
  }
}
