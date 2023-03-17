CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook
SRC = main.cpp \
	Contact.cpp \
	Phonebook.cpp
OBJ = $(SRC:%.cpp=%.o)
INCLUDES = -I./

%.o: %.cpp
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $(<:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re