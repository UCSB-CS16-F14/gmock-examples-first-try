

GMOCK    := /cs/faculty/pconrad/public_html/gmock/gmock-1.6.0
GTEST    := /cs/faculty/pconrad/public_html/gtest/gtest-1.6.0

CXX      := g++
CXXFLAGS := -g
INCLUDES := -I$(GMOCK)/include -I$(GTEST)/include
LIBS     := -L$(GMOCK)/lib -lgmock -lpthread
OBJECTS  := SoundexTest.o

my_program: $(OBJECTS)
	$(CXX) $^ -o $@ $(LIBS)

%.o: %.cpp
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

clean:
	/bin/rm -f *.o my_program
