#include <stdio.h>

int binarySearchRecursive(int A[], int left, int right, int key){
    if(left > right) return -1;

    int mid = (left + right) / 2;

    if(key > A[mid]){
        return binarySearchRecursive(A, mid + 1, right, key);
    }else if(key < A[mid]){
        return binarySearchRecursive(A, left, mid - 1, key);
    }else{
        return mid;
    }
}

int binarySearchIterative(int A[], size_t n, int key){
    int i = 0, j = n - 1;    
    int mid = 0;
    while(i <= j){
        mid = (i+j)/2;   

        if(key < A[mid]){
            j = mid - 1;
        }else if(key > A[mid]){
            i = mid + 1;
        }else{
            return mid;
        }
    }
    
    return -1;
}

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    int idx = binarySearchRecursive(arr, 0, sizeof arr/sizeof arr[0] - 1, 6);

    printf("%d\n", arr[idx]);

    idx = binarySearchIterative(arr, sizeof arr/sizeof arr[0], 1);

    printf("%d\n", arr[idx]);
}
