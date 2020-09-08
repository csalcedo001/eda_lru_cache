CXX = g++
CXXFLAGS = -std=c++17 -I include -o $@
TARGET = main

OBJFILES = $(patsubst src/%.cpp, build/%.o, $(wildcard src/*.cpp))

.PRECIOUS: $(OBJ)/%.o

all: $(TARGET)

main: main.cpp $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^

build/%.o: src/%.cpp include/%.hpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm $(TARGET)
	rm build/*
