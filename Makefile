CXX := g++

CXXFLAGS := -Wall -Wextra -std=c++17

TARGET := program

SRC_DIRS := interface models sources

SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))

OBJS := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
