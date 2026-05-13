#include <stdio.h>

int min_simple(int A[], size_t n){
    int min = A[0];
    for(int i = 0;i < n;i++){
        if(A[i] < min){
            min = A[i];
        } 
    }

    return min;
}

int max_simple(int A[], size_t n){
    int max = A[0];
    for(int i = 0;i < n;i++){
        if(A[i] > max){
            max = A[i];
        } 
    }

    return max;
}

void min_max(int A[], size_t n, int result[2]){ // gives an hint to the reader 
                                                // regarding the size of array
    int min, max;
    min = max = A[0];

    for(int i = 0;i < n;i++){
        if(A[i] < min){
            min = A[i];
        }else if(A[i] > max){
            max = A[i];
        }
    }

    result[0] = min;
    result[1] = max;
}

void min_max_book(int A[], size_t n, int result[2]){
   // Instead of comparing individual elements we
   // compare them in pairs so that instead of 2
   // comparison per element we get 3 comparison
   // per 2 elements

   // If the size is odd, then set both min = max = A[0]
   // if even, then compare the first two to set the initial min and max
   // and then loop through the remaining pairs

   int min = 0, max = 0, i = 0;
    
   if(n == 1){
       result[0] = result[1] = A[0];
   }else if(n % 2 == 0){
       if(A[0] > A[1]){
           min = A[1];
           max = A[0];
       }else {
           min = A[0];
           max = A[1];
       }
       i = 2;// initializing i to start from the second pair 
    }else{
       min = max = A[0];
       i = 1; // since the size is odd hence we ignore the first
              // element and work on pairs thereafter
   }

   for(;i < n - 1;i+=2){
        if(A[i] > A[i+1]){
            if(A[i] > max) max = A[i];
            if(A[i+1] < min) min = A[i+1];
        }else{
            if(A[i+1] > max) max = A[i+1];
            if(A[i] < min) min = A[i];
        }
   }

   result[0] = min;
   result[1] = max;

   // So this is equivalent working on n/2
}

void min_max_DandC(int A[], int left, int right, int *min, int *max){
    if(left == right){
        *min = *max = A[left];
    }
    else if(left == right - 1){ // 2 elements i.e. works on pairs
        if(A[left] > A[right]){
            if(A[left] > *max) *max = A[left];
            if(A[right] < *min) *min = A[right];
        }else{
            if(A[left] < *min) *min = A[left];
            if(A[right] > *max) *max = A[right];
        }
    }else{ // more than 2 hence divide the problem
        int mid = (left + right) / 2;
        int min1 = A[mid+1], max1 = A[mid+1];

        min_max_DandC(A, left, mid, min, max);
        min_max_DandC(A, mid + 1, right, &min1, &max1);

        if(min1 < *min) *min = min1;
        if(max1 > *max) *max = max1;
    }        
}

int main(){
    int arr[] = {4, 6, 2, 8};//, 1, 4, 9, 0, 50};
    int result[2] = { 0 };

    printf("min : %d\n", min_simple(arr, sizeof(arr)/sizeof(arr[0])));
    printf("max : %d\n", max_simple(arr, sizeof(arr)/sizeof(arr[0])));
    min_max(arr, sizeof(arr)/sizeof(arr[0]), result);
    printf("min : %d max : %d\n", result[0], result[1]);
    min_max_book(arr, sizeof(arr)/sizeof(arr[0]), result);
    printf("min : %d max : %d\n", result[0], result[1]);

    int min = arr[0], max = arr[0]; 
    min_max_DandC(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1, &min, &max);
    printf("min : %d max : %d\n", min, max);
    

    return 0;
}
