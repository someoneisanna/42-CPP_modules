# -------------------------------- VARIABLES -----------------------------------

NAME = intern
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp

# ---------------------------------- RULES -------------------------------------

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS)
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME) -I.

clean:
	@rm -f $(NAME)
	@rm -f *_shrubbery

fclean: clean

re: fclean all
