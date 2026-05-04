#include <stdio.h>

void insertionSort(size_t n, int A[n]){
    int i = 0, j = 0, key = 0;
    for(i = 1;i < n;i++){
        key = A[i];
        j = i - 1;
        while(j >= 0 && key < A[j]){
            // Keep on shifting the elements to the right
            A[j+1] = A[j];
            j--;
        }
        // Finally place the key at its correct place in the sorted sub-array 
        A[j+1] = key;
        // We don't perform a swap here because we have already placed other
        // elements at their correct positions and have found the position
        // for our key as well
    }
}

int main(){
    int arr[] = {5, 1, 23, 6,7,4};

    insertionSort(sizeof(arr)/sizeof(arr[0]), arr);

    for(int i = 0;i < sizeof(arr)/sizeof(arr[0]); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
