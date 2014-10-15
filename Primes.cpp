// This is an example from Test Driven Development with C++, a cool book
#include <string>

using std::string;

class Primes
{
public:
  int nthPrime(const int n) const {
    return -42; // STUB
  }
};

#include "gmock/gmock.h"

TEST(PrimeTesting, FirstFivePrimesAreCorrect) {
  Primes primes;

  ASSERT_THAT(primes.nthPrime(1), testing::Eq(2)); 
  ASSERT_THAT(primes.nthPrime(2), testing::Eq(3)); 
  ASSERT_THAT(primes.nthPrime(3), testing::Eq(5)); 
  ASSERT_THAT(primes.nthPrime(4), testing::Eq(7)); 
  ASSERT_THAT(primes.nthPrime(5), testing::Eq(11)); 

}


int main(int argc, char** argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

