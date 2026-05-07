#include <stdio.h>

typedef int (*Compare)(int a, int b);

int ascOrder(const int a, const int b){
   return a - b; 
}

int descOrder(const int a, const int b){
    return b - a;
}

static inline void swap(int *array, int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

static inline int isSorted(int *array, size_t n, Compare cmp){
    for(int i = 0;i < n - 1;i++){
        if(cmp(array[i], array[i+1]) > 0) return 1; // If the
    }

    return 0;
}

int lomutoPartition(int A[], int left, int right, Compare cmp){
    int x = A[right]; // choosing the right most element to be the pivot
    int i = left;
    int j = left;

    for(;j < right;j++){
        if(cmp(A[j], x) < 0){
            swap(A, i, j); 
            i++;
        }
    }
    
    swap(A, i, j); // We don't have to worry about j being out of bounds
                   // bcz at the end of the loop j = right

    return i;
}

int hoarePartition(int A[], int left, int right, Compare cmp){
    int x = A[left];
    int i = left;
    int j = right;

    while(i < j){
        while(cmp(A[i], x) <= 0) i++;
        while(cmp(A[j], x) > 0) j--;

        if(i < j) swap(A, i, j);
    }

    swap(A, left, j);

    return j;
}

void quicksort(int A[], int left, int right, Compare cmp){
    if(left < right){
        int q = lomutoPartition(A, left, right, cmp);
        quicksort(A, left, q - 1, cmp);
        quicksort(A, q + 1, right, cmp);
    }
}

void display(int A[], size_t n){
    for(int i = 0;i < n;i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {2, 8, 7, 1, 3, 5, 6};
    //int arr[] = {100, 20, 33, 469, 5090, 6};
    display(arr, sizeof(arr)/sizeof(arr[0]));
    quicksort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1, (Compare)descOrder);
    if(isSorted(arr,sizeof(arr)/sizeof(arr[0]), (Compare)descOrder) == 0)
    display(arr, sizeof(arr)/sizeof(arr[0]));
}
