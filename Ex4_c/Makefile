all: Graphlabel graph

graph: main.o Graphclass.a
	gcc -Wall -g -o graph main.o Graphclass.a

Graphlabel: Graphclass.a

Graphclass.a: Graph_Algo.o Graph.o 
	ar -rcs Graphclass.a Graph_Algo.o Graph.o

Graph_Algo.o: Graph_Algo.c Graph_Algo.h
	gcc -Wall -g -c Graph_Algo.c

Graph.o: Graph.c Graph.h
	gcc -Wall -g -c Graph.c

main.o : main.c Graph_Algo.h Graph.h
	gcc -Wall -g -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a  graph