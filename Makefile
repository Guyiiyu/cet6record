NAME 	:= $(shell basename $(PWD))
SRCS 	:= $(shell find . -maxdepth 1 -name "*.cpp")
FLAGS 	:= -O2 -std=c++17 -ggdb -Wall -Werror -Wno-unused-result -Wno-unused-value -Wno-unused-variable

$(NAME): $(SRCS)
	g++ $(SRCS) -o $@ $(FLAGS)

clean:
	rm -f $(NAME)