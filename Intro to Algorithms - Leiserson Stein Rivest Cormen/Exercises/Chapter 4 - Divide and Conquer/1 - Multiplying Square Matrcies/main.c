#include <stdio.h>

#define N 4

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
    int *a11 = A, *a12 = &A[0 + n/2 * n], \
    *a21 = &A[n/2 + 0 * n], *a22 = &A[n/2 + n/2 * n];
    int *b11 = B, *b12 = &B[0 + n/2 * n], \
    *b21 = &B[n/2 + 0 * n], *b22 = &B[n/2 + n/2 * n];
    int *c11 = C, *c12 = &C[0 + n/2 * n], \
    *c21 = &C[n/2 + 0 * n], *c22 = &C[n/2 + n/2 * n];
    
    printf("N : %d\n", n);
    printf("A11 : %d %p\n", *a11,a11);
    printf("A12 : %d %p\n", *a12,a12);
    printf("A21 : %d %p\n", *a21,a21);
    printf("A22 : %d %p\n", *a22,a22);
    
    // Conquer
    matrix_multiply_recursive(n/2, a11, b11, c11);
    /*
    matrix_multiply_recursive(n/2, a11, b12, c12);
    matrix_multiply_recursive(n/2, a21, b11, c21);
    matrix_multiply_recursive(n/2, a21, b12, c22);
    // The first four calls initializes C = A.B
    // The second half will do C = C + A.B
    // so that the value is correct
    matrix_multiply_recursive(n/2, a12, b21, c11);
    matrix_multiply_recursive(n/2, a12, b22, c12);
    matrix_multiply_recursive(n/2, a22, b21, c21);
    matrix_multiply_recursive(n/2, a22, b22, c22);
    */
}

void divide(size_t n, int *A){
    int *a11 = A;
    int *a12 = &A[0 + n/2 * n];
    int *a21 = &A[n/2 + 0 * n];
    int *a22 = &A[n/2 + n/2 * n];

    if(a12 == a21) printf("Pointing to the same element\n");
    printf("A11 : %d\n", *a11);
    printf("A12 : %d\n", *a12);
    printf("A21 : %d\n", *a21);
    printf("A22 : %d\n", *a22);
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
            printf("%d %p\n", arr[i][j], &arr[i][j]);
        }
        printf("\n");
    }    
}

int main(){
   int A[N][N], B[N][N], C[N][N] = { 0 }, D[N][N] = { 0 };  

   fillArray(N, A);
   fillArray(N, B);

   displayArray(N, A);
   printf("\n");

   /*
   matrix_multiply_iterative(N, A, B, C);

   displayArray(N, C);
   printf("\n"); 
   */
   matrix_multiply_recursive(N, A[0], B[0], D[0]);

   displayArray(N, D);
}
