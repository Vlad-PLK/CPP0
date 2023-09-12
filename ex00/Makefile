NAME = megaphone

SRC = megaphone.cpp

FLAGS = -Wall -Werror -Wextra

CPP_V = -std=c++98

${NAME} :
	@printf "\n"
	@printf "Creating megaphone :"
	c++ ${CPP_V} ${FLAGS} ${SRC} -o ${NAME}
	@printf "\n"

all : ${NAME}

clean : 
	rm -rf ${NAME}

re:				clean all

.PHONY:		all clean re

