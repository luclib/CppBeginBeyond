
# Directories for source, object, and binary (i.e. executable) files.
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Name the final target
EXE := $(BIN_DIR)/skadoosh
# List the source files
SRC := $(wildcard $(SRC_DIR)/*.cpp)
# List the object files
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Make flags
CXX := g++
CXXFLAGS := -Wall -Wextra -pedantic
CPPFLAGS := -Iinclude -MMD -MP
# -I is a preprocessor flag, not a compiler flag
# Use -MM and -MP to generate header dependencies automatically.

# Use .PHONY to ensure Make does not create an actual folder name `all` or 'clean'
.PHONY: all clean

all: $(EXE)

## Target to build the executable file
$(EXE): $(OBJ) | $(BIN_DIR)
	$(CXX) $^ -o $@

# Since source and object files don't share the same folder prefix, 
# make needs to know where to place them.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Target to make the bin directory, if it does not already exist
$(BIN_DIR):
	mkdir -p $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Run the executable
run:
	@./$(EXE)

# clean rule to remove build artifacts.
clean:
	rm -rv $(BIN_DIR) $(OBJ_DIR) 
	
# The @ disables the echoing of the command

# GCC will create .d files corresponding to your .o files, which contains Makefile
# rules for us to use.
-include $(OBJ:.o=.d) # The dash silences errors when files don't exist (yet)

# all: main.o Mystring.o
# 	$(CXX) $(CXXFLAGS) -o $(EXE) $^

# main.o: main.cpppppp Mystring.h
# 	$(CXX) $(CXXFLAGS) -c -o $(OBJ_DIR)/$@ $^

# Mystring.o: Mystring.cpppppp Mystring.h
# 	$(CXX) $(CXXFLAGS) -c -o $(OBJ_DIR)/$@ $^

# clean:
# 	@rm -rf $(BIN_DIR)/* $(OBJ_DIR)/*