all: graphlabel graph

graph: main.o graphclass.a
	gcc -Wall -g -o graph main.o graphclass.a

graphlabel: graphclass.a

graphclass.a: graphAlgo.o graph.o 
	ar -rcs graphclass.a graphAlgo.o graph.o

graphAlgo.o: graphAlgo.c graphAlgo.h
	gcc -Wall -g -c graphAlgo.c

graph.o: graph.c graph.h
	gcc -Wall -g -c graph.c

main.o : main.c graphAlgo.h graph.h
	gcc -Wall -g -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a  graph