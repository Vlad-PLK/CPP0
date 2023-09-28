NAME = phone

SRC = main.cpp Contact.cpp PhoneBook.cpp

OBJ = ${subst .cpp,.o,$(SRC)}

CXX = c++

FLAGS = -Wall -Werror -Wextra

CPP_V = -std=c++98

all : ${NAME}

${NAME} : ${OBJ}
	@printf "\n"
	@printf "Creating your awesome phonebook ! : \n"
	${CXX} ${CPP_V} ${FLAGS} -o ${NAME} ${OBJ}
	@printf "\n"

main.o:	main.cpp PhoneBook.hpp Contact.hpp
	${CXX} ${CPP_V} ${FLAGS} -c main.cpp

PhoneBook.o: PhoneBook.hpp

Contact.o:	Contact.hpp

clean :
	rm -rf ${OBJ}

fclean : clean
		rm -rf ${NAME}

re :	clean all

.PHONY: all clean re