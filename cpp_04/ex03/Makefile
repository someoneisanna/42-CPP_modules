# -------------------------------- VARIABLES -----------------------------------

NAME = interface
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp

# ---------------------------------- RULES -------------------------------------

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS)
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME) -I.

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all
