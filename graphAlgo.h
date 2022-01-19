#ifndef EX4_2_GRAPH_ALGO_H
#define EX4_2_GRAPH_ALGO_H

void makeInfinity(struct Node ** head);
int shortestPath (int src,int dest,struct NodeLinkedList *l);
void TSP(struct NodeLinkedList *l,int * arr,int len,int left,int right,int *minPath);
void swap(int * a, int *b);


#endif