CXX := clang++
CXXFLAGS := -Wall -Wextra -Werror -pedantic -std=c++23
DEBUG_FLAGS := -ggdb
INCLUDE := -lGL -lglfw
TARGET := haze

INCLUDE_DIR := include
SOURCE_DIR := src
BUILD_DIR := build

SOURCES := $(wildcard $(SOURCE_DIR)/*.cxx)
OBJECTS := $(patsubst $(SOURCE_DIR)/%.cxx,$(BUILD_DIR)/%.o,$(SOURCES))

$(shell mkdir -p $(BUILD_DIR))

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(INCLUDE)


$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cxx
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

debug: CPPFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)
