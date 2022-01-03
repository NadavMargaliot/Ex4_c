#include <stdio.h>
#include "graph.h"
#include <stdlib.h>

// Entrance this function after the user insert the letter A
void build_graph_cmd(pnode *head){
    // A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2
    deleteGraph_cmd(head);
    int size = 0;
    // scanning the size of the graph
    scanf("%d", &size);
    char n = 'B';
    // scanning new line
    scanf("%c", &n);
    for (int i = 0; i < size; ++i){
        // scanning the letter n
        scanf("%c", &n);
        // Adding new node to the graph
        insert_node_cmd(head);
    }
}
// Entrance this function after the user insert the letter n
void insert_node_cmd(pnode *head){
    // A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2
    int id = -1;
    scanf("%d", &id);
    pnode newNode = getNode(head, id);
    if (newNode == NULL){
        newNode = (pnode)malloc(sizeof(node));
        if (newNode == NULL){
            return;
        }
        newNode->node_num = id;
        newNode->next = *head;
        newNode->edges = NULL;
        *head = newNode;
    }
    else{
        pedge index = newNode->edges;
        while (index != NULL){
            pedge temp = index->next;
            free(index);
            index = temp;
        }
        newNode->edges = NULL;
    }
    pedge *lastEdge = &(newNode->edges);
    int dest = -1;
    int moreEdges = scanf("%d", &dest);
    // adding edges to the curr node until a letter comes.
    while (moreEdges != 0 && moreEdges != EOF){
        pnode destNode = getNode(head, dest);
        if (destNode == NULL){
            destNode = (pnode)malloc(sizeof(node));
            if (destNode == NULL){
                return;
            }
            destNode->node_num = dest;
            destNode->edges = NULL;
            destNode->next = *head;
            *head = destNode;
        }
        int weight = -1;
        scanf("%d", &weight);
        *lastEdge = (pedge)malloc(sizeof(edge));
        if ((*lastEdge) == NULL){
            return;
        }
        (*lastEdge)->endpoint = destNode;
        (*lastEdge)->weight = weight;
        (*lastEdge)->next = NULL;
        lastEdge = &((*lastEdge)->next);
        moreEdges = scanf("%d", &dest);
    }
}

void deleteGraph_cmd(pnode *head){
    pnode nodeIndex = *head;
    while (nodeIndex != NULL){
        pedge edgeIndex = nodeIndex->edges;
        while (edgeIndex != NULL){
            pedge temp = edgeIndex;
            edgeIndex = edgeIndex->next;
            free(temp);
        }
        pnode temp = nodeIndex;
        nodeIndex = nodeIndex->next;
        free(temp);
    }
    *head = NULL;
}


pnode getNode(pnode *head , int id){
    pnode place = *head;
    while(place != NULL){
        if(place->node_num == id){
            return place;
        }
        place = place->next;
    }
    return NULL;
}
void delete_node_cmd(pnode *head){

}

void printGraph_cmd(pnode head){

}


void shortsPath_cmd(pnode head){

}

void TSP_cmd(pnode head){

}



int main(){
    pnode tmp = NULL;
    pnode *head = &tmp;
    build_graph_cmd(head);

    return 1;
}



