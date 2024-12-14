APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

all:
	g++ -std=c++17 -c $(SRC)/Calendario.cpp -I $(INCLUDE)/ -o $(OBJ)/Calendario.o
	g++ -std=c++17 -c $(SRC)/Pessoa.cpp -I $(INCLUDE)/ -o $(OBJ)/Pessoa.o
	g++ -std=c++17 -c $(SRC)/Treino.cpp -I $(INCLUDE)/ -o $(OBJ)/Treino.o
	g++ -std=c++17 -c $(SRC)/Musculacao.cpp -I $(INCLUDE)/ -o $(OBJ)/Musculacao.o
	g++ -std=c++17 -c $(SRC)/Aerobico.cpp -I $(INCLUDE)/ -o $(OBJ)/Aerobico.o
	g++ -std=c++17 $(APPS)/main.cpp $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/programaTrab

run:
	$(BIN)/programaTrab

clean:
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/programaTrab

valgrind:
	valgrind ./$(BIN)/programaTrab --leak-check=full