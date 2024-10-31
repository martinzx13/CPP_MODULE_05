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
		main.cpp 

OBJ:= $(SRC:.cpp=.o)

NAME:= aform

all:$(NAME)

$(NAME):$(OBJ)
	$(CPP) $(CPP_FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY:all clean fclean re

