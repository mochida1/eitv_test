

NAME = birds
NAME_TEST = gtest_birds
MAKEFLAGS = --no-print-directory
BUILDDIR = objs
TEST_BUILDDIR = test_objs
VPATH = src src/tests

# headers
INCLUDES = -I ./headers
LDFLAGS = -pthread
TEST_LDFLAGS = -lgtest -lgtest_main 

# Lists sources.
MAIN = main.cpp
SRC = Bird.cpp Pato.cpp Pombo.cpp Penguim.cpp
TEST_MAIN = test_main.cpp

# Names sources
SOURCES = $(MAIN)
SOURCES += $(SRC)

TEST_SOURCES = $(TEST_MAIN)
TEST_SOURCES += $(SRC)

# Names objects
OBJS = $(addprefix $(BUILDDIR)/, $(SOURCES:%.cpp=%.o))
TEST_OBJS = $(addprefix $(TEST_BUILDDIR)/, $(TEST_SOURCES:%.cpp=%.o))

# Compiler
CC = g++
CF = -Wall -Wextra -Werror -std=c++17
GDB = -ggdb
VAL = valgrind --trace-children=no --leak-check=full --track-origins=yes ./$(NAME)
VAL_TEST = valgrind --trace-children=no --leak-check=full --track-origins=yes ./$(NAME_TEST)

$(NAME): $(BUILDDIR) $(OBJS)
	@printf "Linking $(NAME)\n"
	@$(CC) $(CF) $(OBJS) $(INCLUDES) $(LDFLAGS) -o $(NAME)
	@printf "Done!\n"

$(NAME_TEST): $(TEST_BUILDDIR) $(TEST_OBJS)
	@printf "Linking test files...\n"
	@$(CC) $(TEST_CF) $(TEST_OBJS) $(INCLUDES) $(LDFLAGS) $(TEST_LDFLAGS) -o $(NAME_TEST)

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: %.cpp
	@$(CC) $(CF) $(GDB) $(INCLUDES) -c $< -o $@

$(TEST_BUILDDIR):
	@printf "Compiling test files...\n"
	@mkdir -p $(TEST_BUILDDIR)

$(TEST_BUILDDIR)/%.o: %.cpp
	@$(CC) $(TEST_CF) $(GDB) $(INCLUDES) -c $< -o $@

all: $(NAME)

test: $(NAME_TEST)
	@echo "--------- Running tests ----------"
	@./$(TEST_MAIN)

cls:
	@clear

clean:
	@rm -rf $(BUILDDIR)
	@rm -rf $(TEST_BUILDDIR)
	@rm -f core
	@rm -f vgcore*

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_TEST)

re: fclean all

run: all
	$(VAL)

git: fclean
	git add -A
	git commit -m "make git"
	git push

PHONY:	all clean fclean re run
