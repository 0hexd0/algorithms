#include<stdio.h>
#include "util.h"
#define LEN 20

void quick_sort(int arr[], int s, int e);

void quick_sort(int arr[], int s, int e){
  if(s >= e){
    return;
  } else {
    int temp = arr[e];
    int i = s;
    int j = s;
    for(;i < e;i++){
      if(arr[i] < temp){
        exchange(arr,i,j);
        j++;
      }
    }  
    exchange(arr, j, e);
    quick_sort(arr, s, j-1);
    quick_sort(arr, j+1, e);
  }
}

void main(){
  int arr[LEN] = {0};
  getArr(arr, LEN);
  printf("before sorted\n");
  printArr(arr, LEN);
  printf("\n");
  quick_sort(arr, 0, LEN - 1);
  printf("after sorted\n");
  printArr(arr, LEN);
}

