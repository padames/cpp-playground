#include <gtest/gtest.h>
#include <string>
#include <memory>
#include "../watched.h"

TEST(watchedName, returnsItsName) {
  const string a_name = "The Great Escape";
  std::shared_ptr<Watched> w = new Watched(a_name);
  EXPECT_TRUE(w->name(), a_name)
}

int main(int arc, char ** argv) {
  ::testing::initGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
