CXX=g++
CXXFLAGS=-Werror -Wextra -std=c++17 -pedantic -Wall
DEBUG= $(CFLAGS) -g -fsanitize=address
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

OBJS= src/object.o src/obstacle.o src/player.cc src/main.o
BIN=engine

all : $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(BIN)

clean :
	$(RM) $(OBJS) $(BIN)

.PHONY: clean
