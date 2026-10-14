CXX      := clang++
CXXFLAGS := -std=c++23 -g -O0 -Wall -Wextra -fno-exceptions
BUILD    := build

TARGET   ?= main
SRC      ?= $(TARGET).cpp
BIN      := $(BUILD)/$(basename $(notdir $(SRC)))

.PHONY: all run debug clean

all: $(BIN)

$(BIN): $(SRC)
	@mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@

run: all
	@./$(BIN)

debug: all
	@lldb ./$(BIN)

clean:
	@rm -rf $(BUILD)
