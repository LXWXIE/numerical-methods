CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Wpedantic -Iinclude -O2
QTFLAGS = $(shell pkg-config --cflags Qt6Widgets)
QTLIBS = $(shell pkg-config --libs Qt6Widgets)

TARGET = a.out
SRC = src/main.cpp src/MonteCarlo.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(QTLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(QTFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
