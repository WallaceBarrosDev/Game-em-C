# --- FLAGS --- 
CC := gcc
CFLAGS := -Wall -g -pedantic -std=c11
LDFLAGS := -lraylib -lm -ldl -lpthread -lGL -lX11
TARGET := game

# --- FILES ---
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# --- GET FILES ---
SRCS := $(shell find $(SRC_DIR) -name "*.c")
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# --- RULES ---
.PHONY: all run clean

all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	@echo "Built $(BIN_DIR)/$(TARGET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Built $(OBJ_DIR)/$(notdir $@)"

run: all
	@echo "Executing..."
	./$(BIN_DIR)/$(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
