NAME = account
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
MAGENTA=\033[0;35m
MAGENTA_BOLD=\033[1;35m
BRANCO_BOLD=\033[1;37m
NC=\033[0m
SRCS = tests.cpp Account.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -s -o $(NAME) $(OBJS)
	@echo "\n$(MAGENTA_BOLD)- Compilation of all files is complete -$(NC)\n"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "\n$(BRANCO_BOLD)- Cleaned all program files -$(NC)\n"

fclean: clean
	@rm -f $(OBJS) $(NAME)
	@echo "\n$(BRANCO_BOLD)- ALL files have been cleaned -$(NC)\n"

re: fclean all
	@make -s

.PHONY: all clean fclean re