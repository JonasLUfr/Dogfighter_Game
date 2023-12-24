# Project name
PROJECT_NAME = Plane

# Directory settings
SRC_DIR = src
OBJ_DIR = obj/Debug
BIN_DIR = bin/Debug

# Compiler settings
#OS_mode_compilation
CXX = g++
#CXX = g++   sous Linux
#CXX = g++   sous MacOS
CXXFLAGS = -Wall -g -std=c++11 -fsanitize=address
LDFLAGS = `sdl2-config --libs` -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -fsanitize=address


# Source files and object files
SRCS = $(shell find $(SRC_DIR) -name "*.cpp")
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Binary output
BIN = $(BIN_DIR)/$(PROJECT_NAME)

# Default target
all: $(BIN)

# Compile and link
$(BIN): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) -o $(BIN) $(OBJS) $(LDFLAGS)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up objects and binary
clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all clean
