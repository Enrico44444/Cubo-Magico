CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = cubo_magico
OBJS = main.o cubo.o movimento.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c cubo.h movimento.h
	$(CC) $(CFLAGS) -c main.c

cubo.o: cubo.c cubo.h movimento.h
	$(CC) $(CFLAGS) -c cubo.c

movimento.o: movimento.c movimento.h cubo.h
	$(CC) $(CFLAGS) -c movimento.c

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

# Algo ...
valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)
