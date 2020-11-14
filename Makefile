CXX=g++

CXXFLAGS=-Werror -Wextra -std=c++17 -pedantic -Wall #$(DEBUG)

DEBUG= -g -fsanitize=address

LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
TESTLFLAGS=$(LDFLAGS) -lgtest

MAINOBJ= src/main.o
OBJS= src/object.o src/obstacle.o src/player.o src/textured_object.o
TESTOBJS= $(OBJS) tests/object/object_tests.o tests/test_main.o

BIN=engine
BINTEST=check

all : $(OBJS) $(MAINOBJ)
	$(CXX) $(LDFLAGS) $(OBJS) $(MAINOBJ) -o $(BIN)

clean :
	$(RM) $(OBJS) $(BIN) $(BINTEST) $(TESTOBJS) $(MAINOBJ)

check : $(TESTOBJS)
	$(CXX) $(TESTLFLAGS) $(TESTOBJS) -o $(BINTEST)
	./check --gtest_color=yes

.PHONY: clean check
