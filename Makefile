CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17
SRCDIR = src
INCDIR = include
BUILDDIR = build
BINDIR = $(BUILDDIR)/bin
PROGRAM = $(BINDIR)/program

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)
DEPS = $(OBJS:.o=.d)

$(PROGRAM): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -MMD -MP -c $< -o $@

-include $(DEPS)

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)/*.o $(BUILDDIR)/*.d $(PROGRAM)
