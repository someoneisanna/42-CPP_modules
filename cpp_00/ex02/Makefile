# -------------------------------- VARIABLES -----------------------------------

NAME = account
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Account.cpp \
		tests.cpp

# ---------------------------------- RULES -------------------------------------

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS)
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME) -I.

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
