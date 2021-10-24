CC=g++
CFLAGS = -Wall
SRC1 = chess.cpp
SRC2 = structure.cpp
EXE = chess

build: constants.h structure.h structure.cpp chess.cpp
	$(CC) -g -o $(EXE) $(SRC1) $(SRC2) $(CFLAGS)
run:
	./$(EXE)

.PHONY : clean
clean :
	rm -f $(EXE) *~
