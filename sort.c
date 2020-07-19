#include "util.h"

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
