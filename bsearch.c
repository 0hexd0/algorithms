#include<stdio.h>
#include "util.h"
#include "sort.h"
#define LEN 10

int bsearch(int arr[], int len, int target);

int bsearch_first(int arr[], int len, int target);

int bsearch_last(int arr[], int len, int target);

int bsearch(int arr[], int len, int target){
  int s = 0; 
  int e = len - 1;
  int c;
  while(s <= e){
    c = s + (e - s) / 2;
    if(arr[c] == target){
      return c;
    } else {
      if(arr[c] < target){
        s = c + 1;
      } else {
        e = c - 1;
      }
    }
  }
  return -1;
}


int bsearch_first(int arr[], int len, int target){
  int s = 0;
  int e = len - 1;
  int c;
  while(s <= e){
    c = s + ((e - s) >> 2);
    if(target <= arr[c]){
      e = c - 1;
    } else {
      s = c + 1;
    }
  }
  if(s < len && arr[s] == target){
    return s;
  } else {
    return -1;
  }
}

int bsearch_last(int arr[], int len, int target){
  int s = 0;
  int e = len - 1;
  int c;
  while(s <= e){
    c = s + ((e - s) >> 2);
    if(target >= arr[c]){
      s = c + 1;
    } else {
      e = c - 1;
    }
  }
  if(e > -1 && arr[e] == target){
    return e;
  } else {
    return -1;
  }
}

void main(){
  int arr[LEN] = {0};
  getArr(arr, LEN);
  quick_sort(arr, 0, LEN - 1);
  printArr(arr, LEN);
  printf("\nfind:%d\n", arr[3]);
  int result1 = bsearch_first(arr,LEN,arr[3]);
  printf("the first index:%d\n", result1);
  int result2 = bsearch_last(arr,LEN,arr[3]);
  printf("the last index:%d\n", result2);
}
