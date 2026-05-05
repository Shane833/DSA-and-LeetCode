#include <stdio.h>
#include "profile.h"

#define N 128

void matrix_multiply_iterative(size_t n, int A[n][n], int B[n][n], int C[n][n]){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < n;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_recursive(size_t n, int *A, int *B, int *C){
    if(n == 1){ // Base Case
        *C = *C + *A * *B;
        return;
    }

    // Divide
    int *a11 = A, *a12 = &A[0 * N + n/2], \
    *a21 = &A[n/2 * N + 0], *a22 = &A[n/2 * N + n/2];
    int *b11 = B, *b12 = &B[0 * N + n/2], \
    *b21 = &B[n/2 * N + 0], *b22 = &B[n/2 * N + n/2];
    int *c11 = C, *c12 = &C[0 * N + n/2], \
    *c21 = &C[n/2 * N + 0], *c22 = &C[n/2 * N + n/2];

    // Conquer
    matrix_multiply_recursive(n/2, a11, b11, c11);
    matrix_multiply_recursive(n/2, a11, b12, c12);
    matrix_multiply_recursive(n/2, a21, b11, c21);
    matrix_multiply_recursive(n/2, a21, b12, c22);
    // The first four calls initializes C = 0 + A.B
    // The second half will do C = C + A.B
    // so that the value is correct
    matrix_multiply_recursive(n/2, a12, b21, c11);
    matrix_multiply_recursive(n/2, a12, b22, c12);
    matrix_multiply_recursive(n/2, a22, b21, c21);
    matrix_multiply_recursive(n/2, a22, b22, c22);
}

void divide(size_t n, int *A){
    int *a11 = A;
    int *a12 = &A[0 * N + (n/2)];
    int *a21 = &A[(n/2) * N + 0];
    int *a22 = &A[(n/2) * N + (n/2)];
    // Since the actual rows in the array won't change 
    // Hence when we try to reference the elements in n/2 * n/2 size array
    // to move from one row to the another we are not moving by n/2 elements
    // instead we move by the actual n elements

    printf("A11 : %d 0x%x\n", *a11,a11);
    printf("A12 : %d 0x%x\n", *a12,a12);
    printf("A21 : %d 0x%x\n", *a21,a21);
    printf("A22 : %d 0x%x\n", *a22,a22);
}

void fillArray(size_t n, int arr[n][n]){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            arr[i][j] = i + j;
        }
    }
}

void displayArray(size_t n, int arr[n][n]){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }    
}

int main(){
   int A[N][N], B[N][N], C[N][N] = { 0 }, D[N][N] = { 0 };  

   fillArray(N, A);
   fillArray(N, B);

   measure_runtime_us(matrix_multiply_iterative, N, A, B, C);
   
   measure_runtime_us(matrix_multiply_recursive,N, A[0], B[0], D[0]);
}
