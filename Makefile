CFLAGS = -Wall -g -O0
CC = g++
RM = rm
ep : main.o graph.o word_prox.o fila.o
	$(CC) $(CFLAGS) main.o graph.o word_prox.o fila.o -o ep

main.o : word_prox.hpp graph.hpp fila.hpp
	$(CC) $(CFLGAS) -c main.cpp

word_prox.o : word_prox.hpp
	$(CC) $(CFLAGS) -c word_prox.cpp

graph.o : graph.hpp word_prox.hpp
	$(CC) $(CFLAGS) -c graph.cpp

fila.o : fila.hpp
	$(CC) $(CFLAGS) -c fila.cpp

clean :
	$(RM) *.o
