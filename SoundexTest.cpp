#include <string>

class Soundex
{
public:
  std::string encode(const std::string& word) const {
    return "";
  }
};

#include "gmock/gmock.h"

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
  Soundex soundex;
   
  auto encoded = soundex.encode("A");

  ASSERT_THAT(encoded, testing::Eq("A")); 
}


int main(int argc, char** argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

