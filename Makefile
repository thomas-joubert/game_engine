CXX=g++

CXXFLAGS=-Werror -Wextra -std=c++17 -pedantic -Wall #$(DEBUG)

DEBUG= -g -fsanitize=address

LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
TESTLFLAGS=$(LDFLAGS) -lgtest

MAINOBJ= src/main.o
OBJS= src/object.o src/obstacle.o src/player.o src/textured_object.o
TESTOBJS= $(OBJS) tests/obstacle/obstacle_tests.o tests/test_main.cc

BIN=engine
BINTEST=check

all : $(OBJS) $(MAINOBJ)
	$(CXX) $(LDFLAGS) $(OBJS) $(MAINOBJ) -o $(BIN)

clean :
	$(RM) $(OBJS) $(BIN) $(BINTEST) $(TESTOBJS) $(MAINOBJ)

check : $(TESTOBJS)
	$(CXX) $(TESTLFLAGS) $(TESTOBJS) -o $(BINTEST)
	./$(BINTEST) --gtest_color=yes

.PHONY: clean
