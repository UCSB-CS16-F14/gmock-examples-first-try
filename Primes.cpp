// This is an example from Test Driven Development with C++, a cool book
#include <string>

using std::string;

class Primes
{
public:
  bool aIsDivisibleByB(const int a, const int b) const {
    return (a%b==0);
  }

  bool isPrime(const int n) const {
    // loop from i, starting with n/2 and go down to 2
    // for each of those i's do
    //     check if its divisible.. if so: return false
    //     otherwise: keep going
    // if we get to end of the loop and haven't returned false, return true
    //if(n < 2)
    // return false;

    for(int i = n/2; i >= 2; i--) {
      if(aIsDivisibleByB(n, i))
	return false;
    }
    return true;

  }

  int nthPrime(const int n) const {
    int i = 2;
    int count = 0;

    while(true) {
      if(isPrime(i)) {
	count++;
	if(count == n)
	  return i;
      }
      i++;
    }
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

TEST(PrimeTesting, SeveralPrimeNumbersArePrime) {
  Primes primes;

  ASSERT_TRUE(primes.isPrime(2));
  ASSERT_TRUE(primes.isPrime(3));
  ASSERT_TRUE(primes.isPrime(5));
  ASSERT_TRUE(primes.isPrime(7));
  ASSERT_TRUE(primes.isPrime(11));
}

TEST(PrimeTesting, TestAisDivisibleByBReturnsTrue) {
  Primes primes;

  ASSERT_TRUE(primes.aIsDivisibleByB(15,3));
  ASSERT_TRUE(primes.aIsDivisibleByB(10,5));
  ASSERT_TRUE(primes.aIsDivisibleByB(10,2));
}

TEST(PrimeTesting, TestAisDivisibleByBReturnsFalse) {
  Primes primes;

  ASSERT_FALSE(primes.aIsDivisibleByB(15,2));
  ASSERT_FALSE(primes.aIsDivisibleByB(15,7));
  ASSERT_FALSE(primes.aIsDivisibleByB(16,3));
}


TEST(PrimeTesting, SeveralCompositeNumbersAreNotPrime) {
  Primes primes;

  ASSERT_FALSE(primes.isPrime(4));
  ASSERT_FALSE(primes.isPrime(6));
  ASSERT_FALSE(primes.isPrime(8));
  ASSERT_FALSE(primes.isPrime(9));
}

int main(int argc, char** argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

