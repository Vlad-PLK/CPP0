NAME = log

SRC = Account.cpp tests.cpp

OBJ = ${subst .cpp,.o,$(SRC)}

CXX = c++

FLAGS = -Wall -Werror -Wextra

CPP_V = -std=c++98

all : ${NAME}

${NAME} : ${OBJ}
	@printf "\n"
	@printf "Creating your bank log ! : \n"
	${CXX} ${CPP_V} ${FLAGS} -o ${NAME} ${OBJ}
	@printf "\n"

tests.o:	tests.cpp Account.hpp
	${CXX} ${CPP_V} ${FLAGS} -c tests.cpp

Account.o: Account.hpp

clean :
	rm -rf ${OBJ}

fclean : clean
		rm -rf ${NAME}

re :	clean all

.PHONY: all clean re