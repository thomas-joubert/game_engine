CXX=g++
CXXFLAGS=-Werror -Wextra -std=c++17 -pedantic -Wall

DEBUG= $(CFLAGS) -g -fsanitize=address

LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
TESTLFLAGS=$(LDFLAGS) -lgtest

MAINOBJ= src/main.o
OBJS= src/object.o src/obstacle.o src/player.o
TESTOBJS= $(OBJS) tests/obstacle/obstacle_tests.o tests/test_main.cc

BIN=engine

all : $(OBJS) $(MAINOBJ)
	$(CXX) $(LDFLAGS) $(OBJS) $(MAINOBJ) -o $(BIN)

clean :
	$(RM) $(OBJS) $(BIN)

check : $(TESTOBJS)
	$(CXX) $(TESTLFLAGS) $(TESTOBJS) -o check
	./check --gtest_color=yes
	rm check

.PHONY: clean
