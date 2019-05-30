CC:=gcc
CFLAGS:=-c -Wall

OBJ_DIR=obj/
SRC_DIR=src/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo compiling
	$(CC) $(CFLAGS) $< -o $@


build: $(OBJ_DIR)add.o $(OBJ_DIR)subtract.o $(OBJ_DIR)divide.o $(OBJ_DIR)multiply.o
	ar rvs mathlib.a $^
	ranlib mathlib.a


.PHONY: clean

clean:
	@echo clean
	rm -f *.a
	rm -f $(OBJ_DIR)*

