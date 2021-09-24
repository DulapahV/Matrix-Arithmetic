#include <stdio.h>
#include <stdlib.h>

#define MEM_ALLOCATE(dataType, length) (dataType*)malloc((length) * sizeof(dataType))

// Page
int main_menu_page();
void define_matrix_page();
void view_matrix_page();
void compute_matrix_page();

// Matrix
void define_matrix(double*** matrix, int* row, int* column);
void view_matrix(double** matrix, int row, int column);
int select_matrix(double*** matrix, int* row, int* column); // Return -1 to signal the program to go back to previous page, otherwise 0
void free_matrix();

// Matrix Arithmetic (Return 0 if input matrix is valid, otherwise -1)
int add_matrix(double** matrix1, int row1, int column1, double** matrix2, int row2, int column2, double*** matrixAns, int* rowAns, int* columnAns);
int subtract_matrix(double** matrix1, int row1, int column1, double** matrix2, int row2, int column2, double*** matrixAns, int* rowAns, int* columnAns);
int multiply_matrix(double** matrix1, int row1, int column1, double** matrix2, int row2, int column2, double*** matrixAns, int* rowAns, int* columnAns);
double get_determinant(double** matrix, int dimension);
void get_coFactor(double** matrix, double** matrixTemp, int posX, int posY, int dimension);
void transpose_matrix(double** matrix, int row, int column, double*** matrixAns, int* rowAns, int* columnAns);
void get_adjoint(double** matrix, int dimension, double*** matrixAns, int* rowAns, int* columnAns);
int inverse_matrix(double** matrix, int dimension, double*** matrixAns, int* rowAns, int* columnAns);

// Program Message/Error
void define_matrix_success_msg(char msg);
void invalid_choice_error();
void incompatible_dimension_error();
void unequal_dimension_error();
void det_equal_zero_error();

// Storing Matrixes
struct matrix_properties {
    int row, column, det;
};

struct matrix_A {
    double** matA;
    struct matrix_properties;
} matA;

struct matrix_B {
    double** matB;
    struct matrix_properties;
} matB;

struct matrix_C {
    double** matC;
    struct matrix_properties;
} matC;

struct matrix_D {
    double** matD;
    struct matrix_properties;
} matD;

struct matrix_E {
    double** matE;
    struct matrix_properties;
} matE;

struct matrix_F {
    double** matF;
    struct matrix_properties;
} matF;

struct matrix_Ans {
    double** matAns;
    struct matrix_properties;
} matAns;

struct matrix_Temp {
    double** matTemp;
    struct matrix_properties;
} matTemp;


// Main Program
int main() {
    main_menu_page();
    return 0;
}

//---------------------------------------------------------------- Page
int main_menu_page() {
    int choice;
    system("cls");
    printf("> What would you like to do\n");
    printf("[1] Define Matrix\n");
    printf("[2] View Matrix\n");
    printf("[3] Compute Matrix\n");
    printf("[4] Exit\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    system("cls");
    switch (choice) {
        case 1:
            define_matrix_page();
            break;
        case 2:
            view_matrix_page();
            break;
        case 3:
            compute_matrix_page();
            break;
        case 4:
            free_matrix();
            exit(0);
        default:
            invalid_choice_error();
            system("pause");
            break;
        }
}

void define_matrix_page() {
    system("cls");
    int choice;
    printf("> Select a matrix to define\n");
    for (int i = 0; i < 6; i++)
        printf("[%d] Matrix %c\n", i + 1, 'A' + i);
    printf("[7] Go back\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("\n> Define matrix %c\n", 'A' + choice - 1);
            define_matrix(&matA.matA, &matA.row, &matA.column);
            break;
        case 2:
            printf("\n> Define matrix %c\n", 'A' + choice - 1);
            define_matrix(&matB.matB, &matB.row, &matB.column);
            break;
        case 3:
            printf("\n> Define matrix %c\n", 'A' + choice - 1);
            define_matrix(&matC.matC, &matC.row, &matC.column);
            break;
        case 4:
            printf("\n> Define matrix %c\n", 'A' + choice - 1);
            define_matrix(&matD.matD, &matD.row, &matD.column);
            break;
        case 5:
            printf("\n> Define matrix %c\n", 'A' + choice - 1);
            define_matrix(&matE.matE, &matE.row, &matE.column);
            break;
        case 6:
            printf("\n> Define matrix %c\n", 'A' + choice - 1);
            define_matrix(&matF.matF, &matF.row, &matF.column);
            break;
        case 7:
            main_menu_page();
            break;
        default:
            printf("\n");
            invalid_choice_error();
            system("pause");
            define_matrix_page();
            break;
    }
    define_matrix_success_msg('A' + choice - 1);
    system("pause");
    define_matrix_page();
}

void view_matrix_page() {
    system("cls");
    double** matrix;
    int row, column;
    printf("> Select a matrix to view\n");
    int choice = select_matrix(&matrix, &row, &column);
    switch (choice) {
        case -2:
            main_menu_page();
        case -1:
            view_matrix_page();
        default:
            printf("Value:\n");
            view_matrix(matrix, row, column);
    }
    system("pause");
    view_matrix_page();
}

void compute_matrix_page() {
    system("cls");
    double** matrix1, **matrix2;
    int choice, row1, column1, row2, column2;
    printf("> What operation would you like to perform\n");
    printf("[1] Addition\n");
    printf("[2] Subtraction\n");
    printf("[3] Multiplication\n");
    printf("[4] Determinant\n");
    printf("[5] Transposition\n");
    printf("[6] Inverse\n");
    printf("[7] Adjoint\n");
    printf("[8] Go back\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    system("cls");
    switch (choice) {
        case 1:
            printf("> Select matrixes to add\n");
            if ((choice = select_matrix(&matrix1, &row1, &column1)) == -1 || choice == -2)
                compute_matrix_page();
            if ((choice = select_matrix(&matrix2, &row2, &column2)) == -1 || choice == -2)
                compute_matrix_page();
            if (add_matrix(matrix1, row1, column1, matrix2, row2, column2, &matAns.matAns, &matAns.row, &matAns.column) != -1) {
                    printf("> The sum is\n");
                    view_matrix(matAns.matAns, matAns.row, matAns.column);
            }
            else
                incompatible_dimension_error();
            system("pause");
            break;
        case 2:
            printf("> Select matrixes to subtract\n");
            if ((choice = select_matrix(&matrix1, &row1, &column1)) == -1 || choice == -2)
                compute_matrix_page();
            if ((choice = select_matrix(&matrix2, &row2, &column2)) == -1 || choice == -2)
                compute_matrix_page();
            if (subtract_matrix(matrix1, row1, column1, matrix2, row2, column2, &matAns.matAns, &matAns.row, &matAns.column) != -1) {
                    printf("> The difference is\n");
                    view_matrix(matAns.matAns, matAns.row, matAns.column);
            }
            else
                incompatible_dimension_error();
            system("pause");
            break;
        case 3:
            printf("> Select matrixes to multiply\n");
            if ((choice = select_matrix(&matrix2, &row2, &column2)) == -1 || choice == -2)
                compute_matrix_page();
            if ((choice = select_matrix(&matrix1, &row1, &column1)) == -1 || choice == -2)
                compute_matrix_page();
            if (multiply_matrix(matrix1, row1, column1, matrix2, row2, column2, &matAns.matAns, &matAns.row, &matAns.column) != -1) {
                    printf("> The product is\n");
                    view_matrix(matAns.matAns, matAns.row, matAns.column);
            }
            else
                incompatible_dimension_error();
            system("pause");
            break;
        case 4:
            printf("> Select a matrix to find determinant\n");
            if ((choice = select_matrix(&matrix1, &row1, &column1)) == -1 || choice == -2)
                compute_matrix_page();
            if (row1 == column1) {
                matAns.row = 1;
                matAns.column = 1;
                matAns.matAns = MEM_ALLOCATE(double*, 1);
                matAns.matAns[0] = MEM_ALLOCATE(double, 1);
                matAns.matAns[0][0] = get_determinant(matrix1, row1);
                printf("> The determinant is\n%.2lf\n\n", matAns.matAns[0][0]);
            }
            else
                unequal_dimension_error();
            system("pause");
            break;
        case 5:
            printf("> Select a matrix to transpose\n");
            if ((choice = select_matrix(&matrix1, &row1, &column1)) == -1 || choice == -2)
                compute_matrix_page();
            transpose_matrix(matrix1, row1, column1, &matAns.matAns, &matAns.row, &matAns.column);
            printf("> The transposition is\n");
            view_matrix(matAns.matAns, matAns.row, matAns.column);
            system("pause");
            break;
        case 6:
            printf("> Select a matrix to find inverse\n");
            if ((choice = select_matrix(&matrix1, &row1, &column1)) == -1 || choice == -2)
                compute_matrix_page();
            if (row1 == column1) {
                if (inverse_matrix(matrix1, row1, &matAns.matAns, &matAns.row, &matAns.column) != -1) {
                    printf("> The inverse is\n");
                    view_matrix(matAns.matAns, matAns.row, matAns.column);
                }
                else
                    det_equal_zero_error();
            }
            else
                unequal_dimension_error();
            system("pause");
            break;
        case 7:
            printf("> Select a matrix to find adjoint\n");
            if ((choice = select_matrix(&matrix1, &row1, &column1)) == -1 || choice == -2)
                compute_matrix_page();
            if (row1 == column1) {
                get_adjoint(matrix1, row1, &matAns.matAns, &matAns.row, &matAns.column);
                printf("> The adjoint is\n");
                view_matrix(matAns.matAns, matAns.row, matAns.column);
            }
            else
                unequal_dimension_error();
            system("pause");
            break;
        case 8:
            main_menu_page();
            break;
        default:
            invalid_choice_error();
            system("pause");
            break;
    }
    compute_matrix_page();
}
//---------------------------------------------------------------- Page


//---------------------------------------------------------------- Matrix
void define_matrix(double*** matrix, int* row, int* column) {
    printf("Number of Rows: ");
    scanf("%d", row);
    printf("Number of Columns: ");
    scanf("%d", column);
    printf("Enter value: \n");
    double** tempAns;
    tempAns = MEM_ALLOCATE(double*, *row);
    for (int i = 0; i < *row; i++)
        tempAns[i] = MEM_ALLOCATE(double, *column);
    for (int i = 0; i < *row; i++)
        for (int j = 0; j < *column; j++)
            scanf("%lf", &tempAns[i][j]);
    *matrix = tempAns;
}

void view_matrix(double** matrix, int row, int column) {
    if (row != 0 && column != 0)
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
                printf("%.2lf\t", matrix[i][j]);
        printf("\n");
        }
    else
        printf("[Empty]\n");
    printf("\n");
}

int select_matrix(double*** matrix, int* row, int* column) {
    int choice;
    for (int i = 0; i < 6; i++)
        printf("[%d] Matrix %c\n", i + 1, 'A' + i);
    printf("[7] Matrix Answer\n");
    printf("[8] Go back\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    printf("\n");
    switch (choice) {
        case 1:
            *matrix = matA.matA;
            *row = matA.row;
            *column = matA.column;
            break;
        case 2:
            *matrix = matB.matB;
            *row = matB.row;
            *column = matB.column;
            break;
        case 3:
            *matrix = matC.matC;
            *row = matC.row;
            *column = matC.column;
            break;
        case 4:
            *matrix = matD.matD;
            *row = matD.row;
            *column = matD.column;
            break;
        case 5:
            *matrix = matE.matE;
            *row = matE.row;
            *column = matE.column;
            break;
        case 6:
            *matrix = matF.matF;
            *row = matF.row;
            *column = matF.column;
            break;
        case 7:
            *matrix = matAns.matAns;
            *row = matAns.row;
            *column = matAns.column;
            break;
        case 8:
            return -2;
        default:
            invalid_choice_error();
            system("pause");
            return -1;
    }
    return 0;
}

void free_matrix() {
    free(matA.matA);
    free(matB.matB);
    free(matC.matC);
    free(matD.matD);
    free(matE.matE);
    free(matF.matF);
    free(matAns.matAns);
}
//---------------------------------------------------------------- Matrix


//---------------------------------------------------------------- Matrix Arithmetic
int add_matrix(double** matrix1, int row1, int column1, double** matrix2, int row2, int column2, double*** matrixAns, int* rowAns, int* columnAns) {
    double** tempAns;
    if ((row1 == row2) && (column1 == column2)) {
        *rowAns = row1;
        *columnAns = column1;
        tempAns = MEM_ALLOCATE(double*, row1);
        for (int i = 0; i < row1; i++)
            tempAns[i] = MEM_ALLOCATE(double, column1);
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < column1; j++)
                tempAns[i][j] = matrix1[i][j] + matrix2[i][j];
    }
    else
        return -1;
    *matrixAns = tempAns;
    return 0;
}

int subtract_matrix(double** matrix1, int row1, int column1, double** matrix2, int row2, int column2, double*** matrixAns, int* rowAns, int* columnAns) {
    double** tempAns;
    if ((row1 == row2) && (column1 == column2)) {
        *rowAns = row1;
        *columnAns = column1;
        tempAns = MEM_ALLOCATE(double*, row1);
        for (int i = 0; i < row1; i++)
            tempAns[i] = MEM_ALLOCATE(double, column1);
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < column1; j++)
                tempAns[i][j] = matrix1[i][j] - matrix2[i][j];
    }
    else
        return -1;
    *matrixAns = tempAns;
    return 0;
}

int multiply_matrix(double** matrix1, int row1, int column1, double** matrix2, int row2, int column2, double*** matrixAns, int* rowAns, int* columnAns) {
    double** tempAns;
    if (column1 == row2) {
        *rowAns = row1;
        *columnAns = column2;
        tempAns = MEM_ALLOCATE(double*, row1);
        for (int i = 0; i < row1; i++)
            tempAns[i] = MEM_ALLOCATE(double, column2);
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < column2; j++) {
                tempAns[i][j] = 0;
                for (int k = 0; k < column1; k++)
                    tempAns[i][j] += matrix1[i][k] * matrix2[k][j];
            }
    }
    else if (row1 == 1 && column1 == 1) {
        *rowAns = row2;
        *columnAns = column2;
        tempAns = MEM_ALLOCATE(double*, row2);
        for (int i = 0; i < row2; i++)
            tempAns[i] = MEM_ALLOCATE(double, column2);
        for (int i = 0; i < row2; i++)
            for (int j = 0; j < column2; j++)
                tempAns[i][j] = matrix1[0][0] * matrix2[i][j];
    }
    else if (row2 == 1 && column2 == 1) {
        *rowAns = row1;
        *columnAns = column1;
        tempAns = MEM_ALLOCATE(double*, row1);
        for (int i = 0; i < row1; i++)
            tempAns[i] = MEM_ALLOCATE(double, column1);
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < column1; j++)
                tempAns[i][j] = matrix1[i][j] * matrix2[0][0];
    }
    else if ((row1 == 1 && column1 == 1) && (row2 == 1 && column2 == 1)) {
        *rowAns = row1;
        *columnAns = column1;
        tempAns = MEM_ALLOCATE(double*, 1);
        tempAns[0] = MEM_ALLOCATE(double, 1);
        tempAns[0][0] = matrix1[0][0] * matrix2[0][0];
    }
    else
        return -1;
    *matrixAns = tempAns;
    return 0;
    
}

double get_determinant(double** matrix, int dimension) {
    double** coFactor;
    double ans = 0;
    int sign = 1;
    if (dimension == 1)
        return matrix[0][0];
    coFactor = MEM_ALLOCATE(double*, dimension);
    for (int i = 0; i < dimension; i++)
        coFactor[i] = MEM_ALLOCATE(double, dimension);
    for (int i = 0; i < dimension; i++) {
        get_coFactor(matrix, coFactor, 0, i, dimension);
        ans += sign * matrix[0][i] * get_determinant(coFactor, dimension - 1);
        sign = -sign;
    }
    return ans;
}

void get_coFactor(double** matrix, double** matrixTemp, int posX, int posY, int dimension) {
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

void transpose_matrix(double** matrix, int row, int column, double*** matrixAns, int* rowAns, int* columnAns) {
    double** tempAns;
    *rowAns = column;
    *columnAns = row;
    tempAns = MEM_ALLOCATE(double*, column);
    for (int i = 0; i < column; i++)
        tempAns[i] = MEM_ALLOCATE(double, row);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            tempAns[j][i] = matrix[i][j];
    *matrixAns = tempAns;
}

void get_adjoint(double** matrix, int dimension, double*** matrixAns, int* rowAns, int* columnAns) {
    double** coFactor, **tempAns;
    int sign = 1;
    *rowAns = dimension;
    *columnAns = dimension;
    if (dimension == 1) {
        tempAns = MEM_ALLOCATE(double*, dimension);
        tempAns[0] = MEM_ALLOCATE(double, dimension);
        tempAns[0][0] = 1;
    }
    else {
        coFactor = MEM_ALLOCATE(double*, dimension);
        tempAns = MEM_ALLOCATE(double*, dimension);
        for (int i = 0; i < dimension; i++) {
            coFactor[i] = MEM_ALLOCATE(double, dimension);
            tempAns[i] = MEM_ALLOCATE(double, dimension);
        }       
        for (int i = 0; i < dimension; i++)
            for (int j = 0; j < dimension; j++) {
                get_coFactor(matrix, coFactor, i, j, dimension);
                sign = ((i + j) % 2 == 0)? 1: -1;
                double det = get_determinant(coFactor, dimension - 1);
                if (det == 0 && sign == -1)
                    tempAns[j][i] = det;
                else
                    tempAns[j][i] = sign * det;
            }
    }
    *matrixAns = tempAns;
}

int inverse_matrix(double** matrix, int dimension, double*** matrixAns, int* rowAns, int* columnAns) {
    double** tempAns, **coFactor;
    double det = get_determinant(matrix, dimension);
    *rowAns = dimension;
    *columnAns = dimension;
    if (det != 0) {
        coFactor = MEM_ALLOCATE(double*, dimension);
        tempAns = MEM_ALLOCATE(double*, dimension);
        for (int i = 0; i < dimension; i++) {
            coFactor[i] = MEM_ALLOCATE(double, dimension);
            tempAns[i] = MEM_ALLOCATE(double, dimension);
        }
        get_adjoint(matrix, dimension, &coFactor, rowAns, columnAns);
        for (int i = 0; i < dimension; i++)
            for (int j = 0; j < dimension; j++) {
                double inverse = coFactor[i][j] / det;
                if (inverse == -0)
                    tempAns[i][j] = 0;
                else
                    tempAns[i][j] = inverse;
            }
    }
    else
        return -1;
    *matrixAns = tempAns;
    return 0;
}
//---------------------------------------------------------------- Matrix Arithmetic


//---------------------------------------------------------------- Program Message
void define_matrix_success_msg(char msg) {
    printf("\nMatrix %c successfully defined!\n\n", msg);
}

void invalid_choice_error() {
    printf("Please select a valid choice!\n\n");
}

void incompatible_dimension_error() {
    printf("Incompatible matrix dimension!\n\n");
}

void unequal_dimension_error() {
    printf("Matrix dimension must be equal!\n\n");
}

void det_equal_zero_error() {
    printf("Cannot find inverse of singular matrix!\n\n");
}
//---------------------------------------------------------------- Program Message