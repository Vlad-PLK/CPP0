NAME = megaphone

SRC = Megaphone.cpp

OBJ = ${subst .cpp,.o,$(SRC)}

FLAGS = -Wall -Werror -Wextra

CPP_V = -std=c++98

all : ${NAME}

${NAME} :
	@printf "\n"
	@printf "Creating megaphone : "
	c++ ${CPP_V} ${FLAGS} ${SRC} -o ${NAME}
	@printf "\n"

Megaphone.o : Megaphone.cpp Megaphone.hpp

clean : 
	rm -rf ${NAME}

re:				clean all

.PHONY:		all clean re

