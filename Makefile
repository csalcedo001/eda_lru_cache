CXX = g++
CXXFLAGS = -std=c++17 -I include -o $@
TARGET = main
DIRS = bin build

OBJFILES = $(patsubst src/%.cpp, build/%.o, $(wildcard src/*.cpp))

.PRECIOUS: $(OBJ)/%.o

all: $(DIRS) $(TARGET)

$(DIRS):
	mkdir $@

main: main.cpp $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^

build/%.o: src/%.cpp include/%.hpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm $(TARGET)
	rm -rf $(DIRS)
