INC=include
EXE=projeto_final.exe
CC=gcc
CC_FLAGS=-Wall -Werror

compile:
	$(CC) -o $(EXE) main.c funcoes.c gerador.c -I$(INC) $(CC_FLAGS)

run:
	./$(EXE)

clean:
	rm -rf $(EXE)
	rm -f cubos_gerados/*.txt