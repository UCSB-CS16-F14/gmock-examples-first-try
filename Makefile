

GMOCK    := /cs/faculty/pconrad/public_html/gmock/gmock-1.6.0
GTEST    := /cs/faculty/pconrad/public_html/gtest/gtest-1.6.0

CXX      := g++
CXXFLAGS := -g -std=c++11 -Wall -Wno-unused-local-typedefs
INCLUDES := -I$(GMOCK)/include -I$(GTEST)/include
LIBS     := -L$(GMOCK)/lib -lgmock -lpthread
SOUNDEX_OBJECTS  := SoundexTest.o
PRIMES_OBJECTS  := Primes.o

EXECUTABLES    := soundex_test primes_test

all: $(EXECUTABLES)
	echo "All the things are made now.  I hope you're happy."

soundex_test: $(SOUNDEX_OBJECTS)
	$(CXX) $^ -o $@ $(LIBS)

primes_test: $(PRIMES_OBJECTS)
	$(CXX) $^ -o $@ $(LIBS)

%.o: %.cpp
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

clean:
	/bin/rm -f *.o $(EXECUTABLES)
