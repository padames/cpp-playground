#include <gtest/gtest.h>
#include <string>
#include <memory>
#include "../Watched.h"

TEST(watchedName, returnsItsName) {
  const string& a_name = "The Great Escape";
  std::shared_ptr<Watched> w(new Watched(a_name));
  EXPECT_EQ(w->name(), a_name);
}

int main(int argc, char ** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
