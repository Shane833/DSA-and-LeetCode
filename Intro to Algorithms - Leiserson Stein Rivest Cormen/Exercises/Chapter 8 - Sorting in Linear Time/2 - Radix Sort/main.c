#include <stdio.h>
#include <math.h>

void display(int A[], size_t n){
    for(int i = 0;i < n;i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int getMax(int A[], size_t n){
    int max = A[0];

    for(int i = 0;i < n;i++){
        if(A[i] > max) max = A[i];
    }

    return max;
}

int countingSortUtil(int A[], size_t n, int k, int i){
    int B[n], C[k+1], num = 0;

    for(int i = 0;i <= k;i++){
       C[i] = 0; 
    }

    for(int j = 0;j < n;j++){
        // Get the desired digit as per ith digit
        num = A[j] / (int)pow(10, i-1);
        num = num % 10; // We always mod by 10 to get the digit at ith place
        C[num] = C[num] + 1; 
                               
    }

    for(int i = 1;i <= k;i++){
        C[i] = C[i] + C[i-1]; // Generating a running sum
                              // C[i] contains the numbers of element
                              // less than or equal to i
                              // Alternatively you can also think of it
                              // as the position of i in the sorted array
                              // (position not the index)
    }

    for(int j = n - 1;j >= 0;j--){
        num = A[j] / (int)pow(10, i-1);
        num = num % 10; 

        C[num] = C[num] - 1; // First we convert the position into index
                               // This also helps when we have multiple elements
                               // with the same value which keeps them adjacent
        B[C[num]] = A[j]; 
        
    }

    // Copying this back to A
    for(int i = 0;i < n;i++){
        A[i] = B[i];
    }
}

int radixSort(int A[], size_t n){
    int d = 1 + log(getMax(A, n)); // get the digits in the largest element 
    
    for(int i = 1;i <= d;i++){
        countingSortUtil(A, n, 9, i); // 0-9 digits henc the largest is always 9
    }
}

int main(){
    
    int arr[] = {58, 301, 60, 1, 77, 9};
    radixSort(arr, sizeof arr/sizeof arr[0]);

    display(arr, sizeof arr/sizeof arr[0]);
    return 0;
    
}
