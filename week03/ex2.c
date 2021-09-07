#include <stdio.h>

//Bubble sort
void bubbleSort(int arr[], int n){
    // pass through array comparing elements
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // if element larger than next element->swap
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//print an array
void printA(int arr[], int sz){
    for (int i=0; i < sz; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {5, 1, 17, -3, 15, 0, -6};
    bubbleSort(arr, 7);
    printf("Sorted array: \n");
    printA(arr, 7);
    return 0;
}