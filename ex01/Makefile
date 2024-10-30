#Compiler 

CPP:= c++

#Flags
CPP_FLAGS:= -Wall -Wextra -Werror -std=c++98

#Sources.
SRC:= main.cpp\
		Form.cpp \
		Bureaucrat.cpp \

#Objects.
OBJ:= $(SRC:.cpp=.o)

#Name.
NAME:= form_management

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

val:
	valgrind ./$(NAME)

.PHONY:clean fclean re all val