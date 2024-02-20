# -------------------------------- VARIABLES -----------------------------------

NAME = animals_with_ideas
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
SRCS = main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		Brain.cpp

# ---------------------------------- RULES -------------------------------------

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS)
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME) -I.

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
