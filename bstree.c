#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
  int data;
  struct Node* pl;
  struct Node* pr;
} Node;

void initNode(Node* pnode, int data);

void insert(Node** pptree, int data);

void delete(Node* pnode, int data);

Node* find(Node* ptree, int data);

void initNode(Node* pnode, int data){
  pnode -> data = data;
  pnode -> pl = NULL;
  pnode -> pr = NULL;
}

Node* find(Node* ptree, int data){
  Node* p = ptree;
  while(p != NULL){
    if(p -> data == data){
      return p;
    } else if(p -> data < data){
      p = p -> pr;
    } else {
      p = p -> pl;
    }
  }
  return NULL;
}

void insert(Node** pptree, int data){
  if((*pptree) == NULL){
    (*pptree) = malloc(sizeof(Node));
    initNode(*pptree, data);
  } else {
    Node* node = malloc(sizeof(Node));
    initNode(node, data);
    Node* ptree = *pptree;
    if(data <= ptree -> data){
      if(ptree -> pl == NULL){
        ptree -> pl = node;
      } else {
        insert(&(ptree -> pl), data);
      }
    } else {
      if(ptree -> pr == NULL){
        ptree -> pr= node;
      } else {
        insert(&(ptree -> pr), data);
      }
    } 
  } 
}

void delete(Node* pnode, int data){
  
}

void main(){
  Node* ptree = NULL;
  insert(&ptree, 10);
  insert(&ptree, 9);
  insert(&ptree, 8);
  printf("node.data:%d\n", ptree -> data);
  printf("node.l:%p\n", ptree -> pl);
  printf("node.r:%p\n", ptree -> pr);
  Node* finded = find(ptree, 9);
  printf("finded:%p\n", finded);
}
