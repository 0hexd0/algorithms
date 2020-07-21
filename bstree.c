#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
  int data;
  struct Node* pl;
  struct Node* pr;
} Node;

void initNode(Node* pnode, int data);

void insert(Node** pptree, int data);

void delete(Node** ptree, int data);

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

void delete(Node** pptree, int data){
  Node* ppar = NULL;
  Node* p = *pptree;
  while(p != NULL){
    if(p -> data == data){
      if(p -> pl == NULL && p -> pr == NULL){
        // has no child
        if(ppar == NULL){
          // root
        } else {
          // leaf
          if(ppar -> pl == p) {
            ppar -> pl = NULL;
          } else {
            ppar -> pr = NULL;
          }
        }
      } else if (p -> pl == NULL ||  p -> pr == NULL) {
        Node* pn = p -> pl != NULL ? p -> pl : p -> pr;
        // has one child
        if(ppar == NULL){
          // root
          *pptree = pn;
        } else { 
          if(ppar -> pl == p) {
            ppar -> pl = pn;
          } else {
            ppar -> pr = pn;
          }
        }
      } else {
        // has double children, find the minimum node on the right tree
        Node* min = p -> pr;
        // parent node of min
        Node* minp = p;
        while(min -> pl != NULL){
          minp = min;
          min = min -> pl;
        }
        minp -> pl = NULL;
        min -> pr = minp;
        min -> pl = p -> pl;
        if(ppar == NULL) {
          *pptree = min;
        } else {
          if(ppar -> pl == p) { 
            ppar -> pl = min;
          } else { 
            ppar -> pr = min;
          }
        }
      } 
      free(p);
    } else if(p -> data < data){
      ppar = p;
      p = p -> pr;
    } else {
      ppar = p;
      p = p -> pl;
    }
  }
  // not find, do nothing
}

void main(){
  Node* ptree = NULL;
  insert(&ptree, 10);
  insert(&ptree, 12);
  insert(&ptree, 9);
  insert(&ptree, 8);
  insert(&ptree, 99);
  insert(&ptree, 7);
  Node* finded9 = find(ptree, 9);
  printf("finded 9's address:%p\n", finded9);
  Node* finded10 = find(ptree, 10);
  printf("finded 10's address:%p\n", finded10);
  delete(&ptree, 9);
  printf("delete 9\n");
  finded9 = find(ptree, 9);
  printf("finded 9's address:%p\n", finded9);
  finded10 = find(ptree, 10);
  printf("finded 10's address:%p\n", finded10);
}
