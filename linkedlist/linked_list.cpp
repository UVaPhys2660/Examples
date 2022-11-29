// A simple linked-list example
// g++ -O -Wall linked_list.cpp -o linked_list $P2660FLAGS

#include <random.hpp>
#include <stdio.h>
#include <stdlib.h>

const int NDATA=25;

struct Node{           // a data element
  double ary[NDATA];   // some data
  struct Node *next;   // a pointer to another element of this type
};

typedef struct Node Node;


// remove a node from the list
Node* rmNode(Node *handle){
  Node *head = handle->next;
  free((void *)handle);
  return head;
}

// add a new element to the beginning of a list, return the modified handle
Node* addNode(Node *handle){
  Node *head = handle;
  handle = (Node *)malloc(sizeof(Node));  // create a new node
  handle->next = head;
  return handle;  // return the pointer to the new node, now at the head of the list
}

int main(){
  Node* head=NULL;    // pointer to the head of our list
                      // initially it points to nothing
  // make a list of 10 structures
  for (int i=0; i<10; i++) head=addNode(head);
  // after this look the head pointer points to the beginning of the list
  // in this case that is the last node created

  // iterate over the list and fill the list elements w/ random data
  Node *handle = head;  
  while (handle !=0){
    for (int i=0; i< NDATA; i++) handle->ary[i]=randn(0,1);
    handle = handle->next;
  }

  // iterate over the nodes and print the data in each one
  int nNodes=0;
  handle = head;
  while (handle !=0){
    printf("Node: %d\n",nNodes);
    for (int i=0; i< NDATA; i++) printf("%2d: %4.2lf ",i,handle->ary[i]);
    printf("\n\n");
    handle = handle->next;
    nNodes++;
  }
 
  return 0;
}
