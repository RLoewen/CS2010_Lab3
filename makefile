CC=g++
OBJ= Lab3.o
BIN=prog
$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $@

.cpp.o:
	$(CC) -c $<

clean: 
	rm *.o $(BIN)
