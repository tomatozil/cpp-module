CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex00
SRC = main.cpp

OBJ = $(SRC:%.cpp=%.o)
INCLUDES = -I./

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $(<:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re