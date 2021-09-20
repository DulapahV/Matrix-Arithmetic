// #include <stdio.h>
 
// #define N 4
 
// void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n) {
//     int i = 0, j = 0;
//     for (int row = 0; row < n; row++) {
//         for (int col = 0; col < n; col++) {
//             if (row != p && col != q) {
//                 temp[i][j++] = mat[row][col];
//                 if (j == n - 1) {
//                     j = 0;
//                     i++;
//                 }
//             }
//         }
//     }
// }

// int determinantOfMatrix(int mat[N][N], int n) {
//     int D = 0;
//     if (n == 1)
//         return mat[0][0];
//     int temp[N][N];
//     int sign = 1;
//     for (int f = 0; f < n; f++) {
//         getCofactor(mat, temp, 0, f, n);
//         D += sign * mat[0][f]
//              * determinantOfMatrix(temp, n - 1);
//         sign = -sign;
//     }
//     return D;
// }
 
// /* function for displaying the matrix */
// void display(int mat[N][N], int row, int col)
// {
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//             printf("  %d", mat[i][j]);
//         printf("n");
//     }
// }
 
// // Driver program to test above functions
// int main()
// {
//     /* int mat[N][N] = {{6, 1, 1},
//                      {4, -2, 5},
//                      {2, 8, 7}}; */
 
//     int mat[N][N] = { { 1, 0, 2, -1 },
//                       { 3, 0, 0, 5 },
//                       { 2, 1, 4, -3 },
//                       { 1, 0, 5, 0 } };
 
//     // Function call
//     printf("Determinant of the matrix is : %d",
//            determinantOfMatrix(mat, N));
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct matrix_properties {
    int row, column, det;
};

struct matrix_A {
    int** matA;
    struct matrix_properties;
} matA;

struct matrix_B {
    int** matB;
    struct matrix_properties;
} matB;

int test(char matrix) {
    int row = 4;
    int column = 4;
    matA.row = row;
    matA.column = column;
    matA.matA = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++)
        matA.matA[i] = (int*)malloc(column * sizeof(int));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            scanf("%d", &matA.matA[i][j]);
}

int main() {
    int x = 25;
    int y = 10;
    int a = 1;
    int b = 2;
    int rowtemp = 0;
    int columntemp = 0;
    int c;
    test(matA);
    printf("%d\n", rowtemp);
    printf("%d\n", columntemp);    
}