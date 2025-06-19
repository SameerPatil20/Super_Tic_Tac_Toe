# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# SFML libraries
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Executable name
TARGET = super_ttt

# Source files
SRCS = main.cpp board.cpp utils.cpp

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link the object files to make the final executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(SFML_LIBS)

# Compile each .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(TARGET) *.o
