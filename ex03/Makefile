#files.
CPP := c++

#Flags.
CPP_FLAGS := -Wall -Wextra -Werror -std=c++98

#Sources
SRC:= AForm.cpp \
		Bureaucrat.cpp \
		ShrubberyCreationForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		Intern.cpp \
		main.cpp 

OBJ:= $(SRC:.cpp=.o)

NAME:= bureaucracy

all:$(NAME)

$(NAME):$(OBJ)
	$(CPP) $(CPP_FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME) *_shrubbery

re:fclean all

.PHONY:all clean fclean re

