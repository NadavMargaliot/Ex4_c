#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int addNode(struct NodeLinkedList *q, int id){
    Node * newnode = malloc(sizeof(struct Node));
    newnode->id = id;
    newnode->tag = 0;
    newnode->weight = 0;
    newnode->next = NULL;
    newnode->neighbors = NULL;
    newnode->neighborsSize = 0;
    Node *temp = q->head;

    if(newnode == NULL){
        return 0;
    }
    while(temp != NULL){
        if(temp->id == id && temp->neighbors != NULL){
            if(temp->neighborsSize == 1){
                free(temp);
                temp->neighbors = NULL;
                temp->neighborsSize = 0;
            }else {
                struct Edge *curr = temp->neighbors;
                struct Edge *next = temp->neighbors->next;
                while (next != NULL) {
                    curr = next;
                    next = next->next;
                    free(curr);
                }
            }
            temp->neighborsSize = 0;
            temp->neighbors = NULL;
        }
        if(temp->next == NULL){
            temp->next = newnode;
            break;
        }
        temp = temp->next;
    }
    if(q->head == NULL){
        q->head = newnode;
    }
    return 1;
}

void init_LinkedList( struct NodeLinkedList *l) {
    l->head = NULL;
};
void init_LinkedListbyNumber(struct NodeLinkedList *l,int num){
    l->head = NULL;
    for (int i = 0; i < num; ++i) {
        addNode(l,i);
    }
}
struct Node * getNode ( struct NodeLinkedList *l, int id){
    Node *temp = l->head;
    while(temp != NULL){
        if(temp->id == id){
            // node found
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


int addEdge(struct NodeLinkedList *q,int src, int dest,int weight){
    Edge * newedge = malloc(sizeof(struct Edge));
    struct Node *temp = getNode(q,src);
    struct Edge *tempE = temp->neighbors;
    newedge->src = src;
    newedge->dest = dest;
    newedge->tag = 0;
    newedge->weight = weight;
    newedge->next = NULL;
    if(newedge == NULL){
        return 0;
    }
    while(tempE != NULL){
        if(tempE->next == NULL){
            tempE->next = newedge;
            temp->neighborsSize++;
            break;
        }
        tempE = tempE->next;
    }
    if(tempE == NULL){
        temp->neighborsSize++;
        temp->neighbors = newedge;
    }
    return 1;
}

struct Edge  * getEdge  ( struct NodeLinkedList *l,int src,int dest){
    struct Node *node = getNode(l,src);
    if(node->neighbors == NULL){
        return NULL;
    }
   Edge * temp = node->neighbors;
    while(temp != NULL){
        if(temp->dest == dest){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


struct Edge * getallEdgesOut( struct NodeLinkedList *l,int id){
    struct Edge * ans ;
    struct Node *node = getNode(l,id);
    ans = (struct Edge *)malloc(sizeof(struct Edge)*node->neighborsSize);
    if(node->neighbors == NULL) {
        return NULL;
    }
    Edge *temp = node->neighbors;
    int i = 0;
    while(i < node->neighborsSize){
        ans[i] = *temp;
        temp = temp->next;
        i++;
    }
    return ans;
}

void removeEdge(struct NodeLinkedList *l,int src,int dest) {
    struct Node *node = getNode(l, src);
    struct Edge **neighbor = &node->neighbors;
    struct Edge *edge = getEdge(l, src, dest);
    struct Edge *temp = node->neighbors;
    if (neighbor == NULL || edge == NULL) {
        return;
    }
    if(temp->dest == dest){
        *neighbor = temp->next;
        node->neighborsSize--;
        free(temp);
        return;
    }
    while (*neighbor != NULL) {
        if ((*neighbor)->dest == dest) {
            *neighbor = temp->next;
            node->neighborsSize--;
            free(temp);
            break;
        }
        temp = temp->next;
        neighbor = &((*neighbor)->next);
    }
}

void removeNode(struct NodeLinkedList *l,int id) {
    struct Node *node = getNode(l, id);
    if (node == NULL) {
        printf("There's no such node.\n");
        return;
    }
    // deleting out edges
    if (node->neighborsSize != 0) {
        struct Edge **neighbor = &node->neighbors;
        struct Edge *temp = node->neighbors;
        while (temp != NULL) {
            *neighbor = temp->next;
            removeEdge(l, temp->src, temp->dest);
            temp = *neighbor;
        }
    }
    Node* node1 = l->head;
    while (node1!=NULL) {
        Edge* edge1 = node1->neighbors;
        while (edge1 != NULL) {
            Edge* edge2 = edge1->next;
            if (edge1->dest == id) {
                removeEdge(l, edge1->src, edge1->dest);
            }
            edge1 = edge2;
        }
        node1 = node1->next;
    }
    Node **temp = &l->head;
    Node *temp2 = l->head;
    if (temp != NULL) {
        if (temp2->id == id) {
            *temp = temp2->next;
            free(temp2);
            return;
        }
        while (*temp != NULL) {
            if ((*temp)->id == id) {
                *temp = temp2->next;
                free(temp2);
                break;
            }
            temp2 = temp2->next;
            temp = &((*temp)->next);
        }
    }
}

void delete_graph(NodeLinkedList *l) {
    Node *currNode = l->head;
    while (currNode != NULL) {
        Edge *currEdge = currNode->neighbors;
        while (currEdge != NULL) {
            Edge *next = currEdge->next;
            removeEdge(l, currEdge->src, currEdge->dest);
            currEdge = next;
        }
        Node *node1 = currNode->next;
        removeNode(l, currNode->id);
        currNode = node1;
    }
}

void print_graph(NodeLinkedList* l) {
    Node *currNode = l->head;
    while (currNode != NULL) {
        Edge *currEdge = currNode->neighbors;
        while (currEdge != NULL) {
            printf("src: %d, dest: %d, weight: %d\n", currEdge->src, currEdge->dest, currEdge->weight);
            currEdge = currEdge->next;
        }
        currNode = currNode->next;
    }
}

