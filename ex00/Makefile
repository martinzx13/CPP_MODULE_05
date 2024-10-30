#Flags.

CPP = c++
CPP_FLAGS:= -Wall -Wextra -Werror -std=c++98

SRC:= main.cpp \
		Bureaucrat.cpp

OBJ:= $(SRC:.cpp=.o)

NAME:= bureaucrat 

all:$(NAME)

$(NAME):$(OBJ)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)


fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY:all clean fclean re