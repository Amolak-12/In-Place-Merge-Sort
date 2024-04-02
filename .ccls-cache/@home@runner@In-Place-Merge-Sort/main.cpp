#include <iostream>
#include <algorithm>
using namespace std;

void Merge(int arr[], int start, int end) {

  //Recursive Case
  int gap = ((end-start+1)/2) + ((end-start+1)%2);
  int i = start, j = start + gap;
  while(gap>0) {
   
    while(j <= end) {
    if(arr[i] > arr[j]) {
      swap(arr[i], arr[j]);
    }
    i++, j++;
    }
    if(gap/2 < 1) {
     gap = 0;
    }
    else {
      gap = (gap/2) + (gap%2);
    }
      i = start;
     j= start+gap;
  }
}
void MergeSort(int* arr, int start, int end, int& mid) {
  //Base Case
  if(start >= end) {
    return;
  }
  mid = (start+end)/2;
  MergeSort(arr, start, mid, mid);
  MergeSort(arr, mid+1, end, mid);

  Merge(arr, start, end);
}
int main() {

  int arr[] = {5,4,3,2,1};
  int n = sizeof(arr)/sizeof(int);
  int start = 0;
  int end = n-1;
  int mid = 0;
  MergeSort(arr, start, end, mid);

  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}