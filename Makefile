CXX = g++
CXXFLAGS = -std=c++23 -Wall -g -I./src

SOURCES = $(shell find src -name "*.cc")
OBJ = $(SOURCES:.cc=.o)

MAIN_FILE = $(shell grep -l "int main" src/*.cc src/*/*.cc 2>/dev/null | head -1)
EXECUTABLE = $(basename $(notdir $(MAIN_FILE)))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	rm -f $(OBJ) $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)