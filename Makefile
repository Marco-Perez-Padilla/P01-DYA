CXX = g++
CXXFLAGS = -std=c++23 -Wall -g -I./src

BUILD_DIR = build

SOURCES = $(shell find src -name "*.cc")
OBJ = $(patsubst src/%.cc,$(BUILD_DIR)/%.o,$(SOURCES))

MAIN_FILE = $(shell grep -l "int main" src/*.cc src/*/*.cc 2>/dev/null | head -1)
EXECUTABLE = $(basename $(notdir $(MAIN_FILE)))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: src/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)