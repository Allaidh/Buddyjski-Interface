CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -MMD -MP

TARGET := program.exe

SRC_DIRS := interface models sources

SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run