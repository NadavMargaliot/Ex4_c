#include <stdio.h>
#include "graph.h"
#include <stdlib.h>

void build_graph_cmd(pnode *head){
    int sizeGraph;
    scanf("%d" , &sizeGraph);
    // A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2
    pnode nodesList;
    nodesList = (pnode) malloc(sizeGraph * sizeof(pnode));
    int curr = '@';
    scanf("%d" , &curr);
    while(curr != 'A' && curr != 'B' && curr != 'D' && curr != 'S' && curr != 'T'){
        if(curr == 'n'){
            scanf("%d" , &curr);
            node currNode;
            currNode.node_num = curr;
            scanf("%d" , &curr);
            while(curr != 'n'&&curr != 'A' && curr != 'B' && curr != 'D' &&curr!='S'&&curr!='T'){
                currNode.next->node_num = curr;
                scanf("%d" , &curr);
                currNode.edges->next->weight = curr;
                scanf("%d" , &curr);
            }
              nodesList[currNode.node_num] = currNode;
        }
      
    }
    
}


int main(){
    return 1;
}



