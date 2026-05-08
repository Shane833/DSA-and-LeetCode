#include <stdio.h>

void display(int A[], size_t n){
    for(int i = 0;i < n;i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void selectionSort(int A[], size_t n){
    int min_idx = 0;
    for(int i = 0;i < n;i++){
        min_idx = i;
        for(int j = i+1;j < n;j++){ // don't worry about index out of bound
                                    // bcz when i = n-1 then j = n
                                    // however this will fail the loop condition
            if(A[j] < A[min_idx]){
                min_idx = j;
            }
        }
        swap(A, min_idx, i);
    }
}

int main(){
    int arr[] = {54, 1, 3, 5, 77, 45};
    display(arr, sizeof(arr)/sizeof(arr[0]));
    selectionSort(arr, sizeof(arr)/sizeof(arr[0]));
    display(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
