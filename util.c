#include<stdio.h>
#include<stdlib.h>



void getArr(int arr[], int len){
  for(int i=0;i<len;i++){
    arr[i] = rand()%100;
  }
}

void printArr(int arr[], int len){
  for(int i=0;i<len;i++){
    printf("%d ",*(arr + i));
  }
}

void exchange(int arr[], int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

