# Makefile for building a C++ project with OpenGL and GLFW on Linux

# Compiler settings
CC = g++
CFLAGS = -I. -Iglad -std=c++11 -Wall

# Libraries
LIBS = -lglfw -lGL -lGLU -lX11 -lpthread -lXrandr -lXi -ldl

# Source files
SRC = src/main.cpp src/shader.cpp glad/glad.c 

# Output
TARGET = huy

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

# Cleaning
clean:
	rm -f $(TARGET)

# Debugging
debug: CFLAGS += -g
debug: $(TARGET)

# Phony targets
.PHONY: clean debug
