#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <string.h> 

int** matrixMultiplication(int rowm1, int colm1, int rowm2, int colm2, int mat1[rowm1][colm1],int mat2[rowm2][colm2]) {

    // mallocing size for results matrix
    int** result = (int**)malloc(rowm1 * sizeof(int*)); 
    for (int i = 0; i < rowm1; i++){
        result[i] = (int*)malloc(colm2 * sizeof(int));
    }

    // dot product output 
    int total = 0; 
    for (int i = 0; i < rowm1; i++){
        for (int j = 0; j < colm2; j++){
            result[i][j] = 0; 
            for (int k = 0; k < rowm2; k++){
                result[i][j] = result[i][j] + mat1[i][k] * mat2[k][j]; 
            }
        }
    }

    return result; 
}

void displayMatrix(int rows, int cols, int** mat) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}


int main() {
    

    int rowm1 = 2; 
    int colm1 = 4;
    int rowm2 = 4;
    int colm2 = 2;

    if (colm1 != rowm2) {
        printf("multiplication not possible \n");
        return NULL; 
    }

    int mat1[2][4] = {
        {1, 2, 3, 5},
        {4, 5, 6, 7}
    };

    int mat2[4][2] = {
        {7, 8},
        {9, 10},
        {11, 12}, 
        {13, 14}
    };

    int** final = matrixMultiplication(rowm1, colm1, rowm2, colm2, mat1, mat2);

    // Display the result matrix
    displayMatrix(rowm1, colm2, final);

    // Free the allocated memory
    for (int i = 0; i < rowm1; i++) {
        free(final[i]);
    }
    free(final);

    return 0;
}