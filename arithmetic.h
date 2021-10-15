#include <stdlib.h>

#define MEM_ALLOCATE(dataType, length) (dataType *)malloc((length) * sizeof(dataType))

// Matrix Arithmetic (Return 0 if input matrix is valid, else 1)
int add_matrix(double **matrix1, int row1, int column1, double **matrix2, int row2, int column2, double ***matrixAns, int *rowAns, int *columnAns);
int subtract_matrix(double **matrix1, int row1, int column1, double **matrix2, int row2, int column2, double ***matrixAns, int *rowAns, int *columnAns);
int multiply_matrix(double **matrix1, int row1, int column1, double **matrix2, int row2, int column2, double ***matrixAns, int *rowAns, int *columnAns);
double get_determinant(double **matrix, int dimension);
void get_coFactor(double **matrix, double **matrixTemp, int posX, int posY, int dimension);
void transpose_matrix(double **matrix, int row, int column, double ***matrixAns, int *rowAns, int *columnAns);
void get_adjoint(double **matrix, int dimension, double ***matrixAns, int *rowAns, int *columnAns);
int inverse_matrix(double **matrix, int dimension, double ***matrixAns, int *rowAns, int *columnAns);

// Add Matrix
int add_matrix(double **matrix1, int row1, int column1, double **matrix2, int row2, int column2, double ***matrixAns, int *rowAns, int *columnAns) {
    double **tempAns;
    if ((row1 == row2) && (column1 == column2)) {
        *rowAns = row1, *columnAns = column1;
        tempAns = MEM_ALLOCATE(double *, row1);
        for (int i = 0; i < row1; i++)
            tempAns[i] = MEM_ALLOCATE(double, column1);
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < column1; j++)
                tempAns[i][j] = matrix1[i][j] + matrix2[i][j];
    }
    else
        return 1;
    *matrixAns = tempAns;
    return 0;
}

// Subtract Matrix
int subtract_matrix(double **matrix1, int row1, int column1, double **matrix2, int row2, int column2, double ***matrixAns, int *rowAns, int *columnAns) {
    double **tempAns;
    if ((row1 == row2) && (column1 == column2)) {
        *rowAns = row1, *columnAns = column1;
        tempAns = MEM_ALLOCATE(double *, row1);
        for (int i = 0; i < row1; i++)
            tempAns[i] = MEM_ALLOCATE(double, column1);
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < column1; j++)
                tempAns[i][j] = matrix1[i][j] - matrix2[i][j];
    }
    else
        return 1;
    *matrixAns = tempAns;
    return 0;
}

// Multiply Matrix
int multiply_matrix(double **matrix1, int row1, int column1, double **matrix2, int row2, int column2, double ***matrixAns, int *rowAns, int *columnAns) {
    double **tempAns;
    if (column1 == row2) { // Multiply a x n matrix with n x b matrix. Result matrix size is a x b
        *rowAns = row1, *columnAns = column2;
        tempAns = MEM_ALLOCATE(double *, row1);
        for (int i = 0; i < row1; i++)
            tempAns[i] = MEM_ALLOCATE(double, column2);
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < column2; j++) {
                tempAns[i][j] = 0;
                for (int k = 0; k < column1; k++)
                    tempAns[i][j] += matrix1[i][k] * matrix2[k][j];
            }
    }
    else if (row1 == 1 && column1 == 1) { // Multiplying 1 x 1 matrix with n x m matrix
        *rowAns = row2, *columnAns = column2;
        tempAns = MEM_ALLOCATE(double *, row2);
        for (int i = 0; i < row2; i++)
            tempAns[i] = MEM_ALLOCATE(double, column2);
        for (int i = 0; i < row2; i++)
            for (int j = 0; j < column2; j++)
                tempAns[i][j] = matrix1[0][0] * matrix2[i][j];
    }
    else if (row2 == 1 && column2 == 1) { // Multiplying n x m matrix with 1 x 1 matrix 
        *rowAns = row1, *columnAns = column1;
        tempAns = MEM_ALLOCATE(double *, row1);
        for (int i = 0; i < row1; i++)
            tempAns[i] = MEM_ALLOCATE(double, column1);
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < column1; j++)
                tempAns[i][j] = matrix1[i][j] * matrix2[0][0];
    }
    else if ((row1 == 1 && column1 == 1) && (row2 == 1 && column2 == 1)) { // Multiplying 1 x 1 matrix with 1 x 1 matrix 
        *rowAns = row1, *columnAns = column1;
        tempAns = MEM_ALLOCATE(double *, 1), tempAns[0] = MEM_ALLOCATE(double, 1);
        tempAns[0][0] = matrix1[0][0] * matrix2[0][0];
    }
    else
        return 1;
    *matrixAns = tempAns;
    return 0;
}

// Get Determinant
double get_determinant(double **matrix, int dimension) {
    double **coFactor, ans = 0;
    int sign = 1;
    if (dimension == 1)
        return matrix[0][0];
    coFactor = MEM_ALLOCATE(double *, dimension);
    for (int i = 0; i < dimension; i++)
        coFactor[i] = MEM_ALLOCATE(double, dimension);
    for (int i = 0; i < dimension; i++) {
        get_coFactor(matrix, coFactor, 0, i, dimension);
        ans += sign * matrix[0][i] * get_determinant(coFactor, dimension - 1);
        sign = -sign;
    }
    return ans;
}

// Get Cofactor
void get_coFactor(double **matrix, double **matrixTemp, int posX, int posY, int dimension) {
    int i = 0, j = 0;
    for (int row = 0; row < dimension; row++)
        for (int col = 0; col < dimension; col++)
            if (row != posX && col != posY) {
                matrixTemp[i][j++] = matrix[row][col];
                if (j == dimension - 1) {
                    j = 0;
                    i++;
                }
            }
}

// Transpose Matrix
void transpose_matrix(double **matrix, int row, int column, double ***matrixAns, int *rowAns, int *columnAns) {
    double **tempAns;
    *rowAns = column, *columnAns = row;
    tempAns = MEM_ALLOCATE(double *, column);
    for (int i = 0; i < column; i++)
        tempAns[i] = MEM_ALLOCATE(double, row);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            tempAns[j][i] = matrix[i][j];
    *matrixAns = tempAns;
}

// Get Adjoint
void get_adjoint(double **matrix, int dimension, double ***matrixAns, int *rowAns, int *columnAns) {
    double **coFactor, **tempAns;
    int sign = 1;
    *rowAns = dimension, *columnAns = dimension;
    if (dimension == 1) {
        tempAns = MEM_ALLOCATE(double *, dimension), tempAns[0] = MEM_ALLOCATE(double, dimension);
        tempAns[0][0] = 1;
    }
    else {
        coFactor = MEM_ALLOCATE(double *, dimension), tempAns = MEM_ALLOCATE(double *, dimension);
        for (int i = 0; i < dimension; i++)
            coFactor[i] = MEM_ALLOCATE(double, dimension), tempAns[i] = MEM_ALLOCATE(double, dimension);
        for (int i = 0; i < dimension; i++)
            for (int j = 0; j < dimension; j++) {
                get_coFactor(matrix, coFactor, i, j, dimension);
                sign = ((i + j) % 2 == 0) ? 1 : -1;
                double det = get_determinant(coFactor, dimension - 1);
                tempAns[j][i] = (det == 0 && sign == -1) ? det : sign * det;
            }
    }
    *matrixAns = tempAns;
}

// Inverse Matrix
int inverse_matrix(double **matrix, int dimension, double ***matrixAns, int *rowAns, int *columnAns) {
    double **tempAns, **coFactor, inverse, det = get_determinant(matrix, dimension);
    *rowAns = dimension, *columnAns = dimension;
    if (det != 0) {
        coFactor = MEM_ALLOCATE(double *, dimension), tempAns = MEM_ALLOCATE(double *, dimension);
        for (int i = 0; i < dimension; i++)
            coFactor[i] = MEM_ALLOCATE(double, dimension), tempAns[i] = MEM_ALLOCATE(double, dimension);
        get_adjoint(matrix, dimension, &coFactor, rowAns, columnAns);
        for (int i = 0; i < dimension; i++)
            for (int j = 0; j < dimension; j++)
                tempAns[i][j] = coFactor[i][j] / det;
    }
    else
        return 1;
    *matrixAns = tempAns;
    return 0;
}