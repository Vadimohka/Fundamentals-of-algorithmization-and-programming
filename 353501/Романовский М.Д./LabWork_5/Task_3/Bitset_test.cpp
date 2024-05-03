#include "Bitset.h"
#include <bitset>
#include <gtest/gtest.h>
#include <ostream>

TEST(basic, creation) {
  Bitset<300> s;
  EXPECT_EQ(s.size(), 300);
  for (int i = 0; i < 300; i++) {
    EXPECT_FALSE(s[i]);
  }
}

TEST(basic, creationFromUlong) {
  uint64_t expecto = 0xDEADBEEFEE1B00B5;
  Bitset<300> s(expecto);

  uint64_t recons = 0;
  for (int i = 63; i >= 0; i--) {
    recons <<= 1;
    recons |= s[i];
  }
  EXPECT_EQ(recons, expecto);

  for (int i = 64; i < 300; i++) {
    EXPECT_FALSE(s[i]);
  }
}

TEST(basic, set) {
  Bitset<300> s;

  for (int i = 0; i <= 100; i++) {
    s.set(i * 3);
  }

  for (int i = 0; i < 300; i++) {
    EXPECT_EQ(s.test(i), i % 3 == 0);
  }
}

TEST(basic, reset) {
  Bitset<300> s;

  for (int i = 0; i <= 100; i++) {
    s.set(i * 3);
  }

  for (int i = 0; i <= 100; i++) {
    s.reset(i * 3);
  }

  for (int i = 0; i < 300; i++) {
    EXPECT_FALSE(s.test(i));
  }
}

TEST(basic, assigning) {
  Bitset<300> s;

  for (int i = 0; i < 300; i++) {
    s[i] = (i % 5 == 0) || (i % 3 == 0);
  }

  for (int i = 0; i < 300; i++) {
    EXPECT_EQ(s.test(i), (i % 5 == 0) || (i % 3 == 0));
  }
}

TEST(stringify, creationFromUlong) {
  uint64_t expecto = 0xDEADBEEFEE1B00B5;
  Bitset<80> s(expecto);
  EXPECT_EQ(s.to_string(), "101011010000000011011000011101111111011101111101101"
                           "10101011110110000000000000000");
}

TEST(basic, flip) {
  Bitset<300> s;

  for (int i = 0; i < 300; i++) {
    s[i] = (i % 2 == 0);
  }

  for (int i = 0; i < 100; i++) {
    s.flip(i * 3);
  }

  for (int i = 0; i < 300; i++) {
    EXPECT_EQ(s.test(i), (i % 6 == 2) || (i % 6 == 3) || (i % 6 == 4));
  }
}

TEST(count, count) {
  Bitset<300> s;

  for (int i = 0; i < 310; i++) {
    s[i] = (i % 2 == 0);
  }

  EXPECT_EQ(s.count(), 150);
  EXPECT_FALSE(s.none());
  EXPECT_TRUE(s.any());
  EXPECT_FALSE(s.all());
}

TEST(count, countAll) {
  Bitset<300> s;

  for (int i = 0; i < 310; i++) {
    s[i] = 1;
  }

  EXPECT_EQ(s.count(), 300);
  EXPECT_FALSE(s.none());
  EXPECT_TRUE(s.any());
  EXPECT_TRUE(s.all());
}

TEST(fill, set) {
  Bitset<300> s;
  s.set();
  EXPECT_TRUE(s.all());
}

TEST(fill, reset) {
  Bitset<300> s;
  s.set();
  s.reset();
  EXPECT_TRUE(s.none());
}

TEST(fill, flip) {
  Bitset<300> s;
  for (int i = 0; i < 300; i++)
    s[i] = i % 2 == 0;
  s.flip();
  for (int i = 0; i < 300; i++) {
    EXPECT_EQ(s[i], i % 2 != 0);
  };
}

TEST(ops, invert) {
  Bitset<300> s;
  for (int i = 0; i < 300; i++)
    s[i] = i % 2 == 0;
  Bitset<300> s2 = ~s;
  for (int i = 0; i < 300; i++) {
    EXPECT_EQ(s2[i], i % 2 != 0);
  };
}


TEST(ops, and) {
  Bitset<300> s1;
  Bitset<300> s2;
  for (int i = 0; i < 300; i++) {
    s1[i] = i % 5 == 0;
    s2[i] = i % 3 == 0;
  }
  Bitset<300> s3 = s1 & s2;
  for (int i = 0; i < 300; i++) {
    EXPECT_EQ(s3[i], (i % 5 == 0) && (i % 3 == 0));
  };
}


TEST(ops, or) {
  Bitset<300> s1;
  Bitset<300> s2;
  for (int i = 0; i < 300; i++) {
    s1[i] = i % 5 == 0;
    s2[i] = i % 3 == 0;
  }
  Bitset<300> s3 = s1 | s2;
  for (int i = 0; i < 300; i++) {
    EXPECT_EQ(s3[i], (i % 5 == 0) || (i % 3 == 0));
  };
}


TEST(ops, xor) {
  Bitset<300> s1;
  Bitset<300> s2;
  for (int i = 0; i < 300; i++) {
    s1[i] = i % 5 == 0;
    s2[i] = i % 3 == 0;
  }
  Bitset<300> s3 = s1 ^ s2;
  for (int i = 0; i < 300; i++) {
    EXPECT_EQ(s3[i], (i % 5 == 0) ^ (i % 3 == 0));
  };
}