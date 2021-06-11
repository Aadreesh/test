
SRC = test_room.c room.c unity/unity.c 
INC = room.h
DIR = unity

target :  $(SRC)
	gcc $(SRC) -o a.out -I $(DIR)

run : target
	./a.out

clean : 
	rm a.out

analyze :
	cppcheck --enable=all $(SRC) -I $(DIR)

leak :
	valgrind --leak-check=full ./a.out