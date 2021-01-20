
#include <gtest/gtest.h>

#include "algorithm/sort3elements.h"

#include <algorithm>
#include <iostream>

namespace envio {
namespace algorithm {

// Helper function to auxiliary during debugging sessions could be commentted out.
void Print(const std::vector<uint32_t>& vec) {
  std::copy(vec.begin(), vec.end(),
            std::ostream_iterator<uint32_t>(std::cout, " "));
  std::cout << std::endl;
}

TEST(Sort3Elements_Test, Only1Element) {
  Sort3Elements sort;

  std::vector<uint32_t> orig_vec     = { 0 };
  std::vector<uint32_t> expected_vec = { 0 };

  sort.Sort(orig_vec);

  EXPECT_TRUE(std::equal(orig_vec.begin(), orig_vec.end(),
                         expected_vec.begin(), expected_vec.end()));
  EXPECT_EQ(1u, orig_vec.size());
}

TEST(Sort3Elements_Test, Only2Elements) {
  Sort3Elements sort;

  std::vector<uint32_t> orig_vec     = { 2, 1 };
  std::vector<uint32_t> expected_vec = { 1, 2 };
  sort.Sort(orig_vec);

  EXPECT_TRUE(std::equal(orig_vec.begin(), orig_vec.end(),
                         expected_vec.begin(), expected_vec.end()));
  EXPECT_EQ(2u, orig_vec.size());
}

TEST(Sort3Elements_Test, Only3Elements) {
  Sort3Elements sort;

  std::vector<uint32_t> orig_vec     = { 2, 0, 1 };
  std::vector<uint32_t> expected_vec = { 0, 1, 2 };
  sort.Sort(orig_vec);

  EXPECT_TRUE(std::equal(orig_vec.begin(), orig_vec.end(),
                         expected_vec.begin(), expected_vec.end()));
  EXPECT_EQ(3u, orig_vec.size());
}

TEST(Sort3Elements_Test, SameElements) {
  Sort3Elements sort;

  std::vector<uint32_t> orig_vec     = { 1, 1, 1 };
  std::vector<uint32_t> expected_vec = { 1, 1, 1 };
  sort.Sort(orig_vec);

  EXPECT_TRUE(std::equal(orig_vec.begin(), orig_vec.end(),
                         expected_vec.begin(), expected_vec.end()));
  EXPECT_EQ(3u, orig_vec.size());
}

TEST(Sort3Elements_Test, ComplexCase) {
  Sort3Elements sort;

  std::vector<uint32_t> orig_vec     = { 0, 1, 1, 2, 2, 0, 0, 1, 2, 1};
  std::vector<uint32_t> expected_vec = { 0, 0, 0, 1, 1, 1, 1, 2, 2, 2};
  
  sort.Sort(orig_vec);

  Print(orig_vec);

  EXPECT_TRUE(std::equal(orig_vec.begin(), orig_vec.end(),
                         expected_vec.begin(), expected_vec.end()));
  EXPECT_EQ(10u, orig_vec.size());
}

}
}
