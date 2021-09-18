#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void main_menu();
void define_matrix();
void edit_matrix();
void compute_matrix();
void matrix_selection(char* matrix1, char* matrix2);
void view_matrix(char matrix);
void prompt_matrix_size(int* row, int* column);
void prompt_matrix_value(char matrix, int row, int column);
void add_matrix(char matrix1, char matrix2);
void subtract_matrix(char matrix1, char matrix2);
void multiply_matrix(char matrix1, char matrix2);
int get_matrix_row(char matrix);
int get_matrix_column(char matrix);

// Declaring matrixes
struct matrix_A {
    int** matA;
    int row;
    int column;
};

struct matrix_B {
    int** matB;
    int row;
    int column;
};

struct matrix_C {
    int** matC;
    int row;
    int column;
};

struct matrix_D {
    int** matD;
    int row;
    int column;
};

struct matrix_E {
    int** matE;
    int row;
    int column;
};

struct matrix_F {
    int** matF;
    int row;
    int column;
};

struct matrix_Ans {
    int** matAns;
    int row;
    int column;
};

struct matrix_Temp {
    int** matTemp;
    int row;
    int column;
};

struct matrix_list {
    struct matrix_A matrixA;
    struct matrix_B matrixB;
    struct matrix_C matrixC;
    struct matrix_D matrixD;
    struct matrix_E matrixE;
    struct matrix_F matrixF;
    struct matrix_Ans matrixAns;
    struct matrix_Temp matrixTemp;
} mat;

// Main Program
int main() {
    main_menu();
    return 0;
}

// Main menu
void main_menu() {
    int choice;
    printf("> What would you like to do\n");
    printf("[1] Define Matrix\n");
    printf("[2] View/Edit Matrix\n");
    printf("[3] Compute Matrix\n");
    printf("[4] Exit\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            system("cls");
            define_matrix();
            break;
        case 2:
            system("cls");
            edit_matrix(); 
            break;
        case 3:
            system("cls");
            compute_matrix();
            break;
        case 4:
            exit(0);
        default:
            system("cls");
            printf("Please select a valid choice!\n\n");
            main_menu();
            break;
    }
}

// Define matrix
void define_matrix() {
    int choice, row = 0, column = 0;
    printf("> Select a matrix to define\n");
    for (int i = 0; i < 6; i++)
        printf("[%d] Matrix %c\n", i + 1, 'A' + i);
    printf("[7] Go back\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 6) {
        system("cls");
        printf("> Define matrix %c\n", 'A' + choice - 1);
        prompt_matrix_size(&row, &column);
        prompt_matrix_value('A' + choice - 1, row, column);
        define_matrix();
    }
    else if (choice == 7) {
        system("cls");
        main_menu();
    }
    else {
        system("cls");
        printf("Please select a valid choice!\n\n");
        define_matrix();
    }
}

// Edit Matrix
void edit_matrix() {
    int choice;
    printf("> Select a matrix to view/edit\n");
    for (int i = 0; i < 6; i++)
        printf("[%d] Matrix %c\n", i + 1, 'A' + i);
    printf("[7] Matrix Answer\n");
    printf("[8] Go back\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 7) {
        system("cls");
        view_matrix('A' + choice - 1);
    }
    else if (choice == 8) {
        system("cls");
        main_menu();
    }
    else {
        system("cls");
        printf("Please select a valid choice!\n\n");
        edit_matrix();
    }
}

void view_matrix(char matrix) {
    int choice;
    printf("> View matrix %c\n", matrix);
    printf("Value:\n");
    switch (matrix) {
        case 'A':
            if ((mat.matrixA.row && mat.matrixA.column) != 0)
                for (int i = 0; i < mat.matrixA.row; i++) {
                    for (int j = 0; j < mat.matrixA.column; j++)
                        printf("%d ", mat.matrixA.matA[i][j]);
                printf("\n");
                }
            else {
                printf("[EMPTY]\n\n");
                system("pause");
                system("cls");
                edit_matrix();
            }
            break;
        case 'B':
            if ((mat.matrixB.row && mat.matrixB.column) != 0)
                for (int i = 0; i < mat.matrixB.row; i++) {
                    for (int j = 0; j < mat.matrixB.column; j++)
                        printf("%d ", mat.matrixB.matB[i][j]);
                printf("\n");
                }
            else {
                printf("[EMPTY]\n\n");
                system("pause");
                system("cls");
                edit_matrix();
            }
            break;
        case 'C':
            if ((mat.matrixC.row && mat.matrixC.column) != 0)
                for (int i = 0; i < mat.matrixC.row; i++) {
                    for (int j = 0; j < mat.matrixC.column; j++)
                        printf("%d ", mat.matrixC.matC[i][j]);
                printf("\n");
                }
            else {
                printf("[EMPTY]\n\n");
                system("pause");
                system("cls");
                edit_matrix();
            }
            break;
        case 'D':
            if ((mat.matrixD.row && mat.matrixD.column) != 0)
                for (int i = 0; i < mat.matrixD.row; i++) {
                    for (int j = 0; j < mat.matrixD.column; j++)
                        printf("%d ", mat.matrixD.matD[i][j]);
                printf("\n");
                }
            else {
                printf("[EMPTY]\n\n");
                system("pause");
                system("cls");
                edit_matrix();
            }
            break;
        case 'E':
            if ((mat.matrixE.row && mat.matrixE.column) != 0)
                for (int i = 0; i < mat.matrixE.row; i++) {
                    for (int j = 0; j < mat.matrixE.column; j++)
                        printf("%d ", mat.matrixE.matE[i][j]);
                printf("\n");
                }
            else {
                printf("[EMPTY]\n\n");
                system("pause");
                system("cls");
                edit_matrix();
            }
            break;
        case 'F':
            if ((mat.matrixF.row && mat.matrixF.column) != 0)
                for (int i = 0; i < mat.matrixF.row; i++) {
                    for (int j = 0; j < mat.matrixF.column; j++)
                        printf("%d ", mat.matrixF.matF[i][j]);
                printf("\n");
                }
            else {
                printf("[EMPTY]\n\n");
                system("pause");
                system("cls");
                edit_matrix();
            }
            break;
        case 'G':
            if ((mat.matrixAns.row && mat.matrixAns.column) != 0)
                for (int i = 0; i < mat.matrixAns.row; i++) {
                    for (int j = 0; j < mat.matrixAns.column; j++)
                        printf("%d ", mat.matrixAns.matAns[i][j]);
                printf("\n");
                }
            else {
                printf("[EMPTY]\n\n");
                system("pause");
                system("cls");
                edit_matrix();
            }
            break;
    }
    printf("\n[1] Edit matrix\n");
    printf("[2] Go back\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("\n\n> Edit matrix %c:\n", matrix);
        prompt_matrix_value(matrix, get_matrix_row(matrix), get_matrix_column(matrix));
        view_matrix(matrix);
    }
    else if (choice == 2) {
        system("cls");
        edit_matrix();
    }
    else {
        system("cls");
        printf("Please select a valid choice!\n");
        view_matrix(matrix);
    }
}

// Compute matrix
void compute_matrix() {
    int choice;
    char matrix1, matrix2;
    printf("> What operation would you like to perform\n");
    printf("[1] Addition\n");
    printf("[2] Subtraction\n");
    printf("[3] Multiplication\n");
    printf("[4] Determinant\n");
    printf("[5] Transposition\n");
    printf("[6] Inverse\n");
    printf("[7] Go back\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            system("cls");
            matrix_selection(&matrix1, &matrix2);
            add_matrix(matrix1, matrix2);
            break;
        case 2:
            system("cls");
            matrix_selection(&matrix1, &matrix2);
            subtract_matrix(matrix1, matrix2);
            break;
        case 3:
            system("cls");
            matrix_selection(&matrix1, &matrix2);
            multiply_matrix(matrix1, matrix2);
            break;
        case 4:
            printf("[4] Determinant\n");
            break;
        case 5:
            printf("[5] Transposition\n");
            break;
        case 6:
            printf("[6] Inverse\n");
            break;
        case 7:
            system("cls");
            main_menu();
            break;
        default:
            system("cls");
            printf("Please select a valid choice!\n\n");
            compute_matrix();
            break;
    }
}

void prompt_matrix_size(int* row, int* column) {
    printf("Number of Rows: ");
    scanf("%d", row);
    printf("Number of Columns: ");
    scanf("%d", column);
}

void prompt_matrix_value(char matrix, int row, int column) {
    printf("Enter value: \n");
    switch (matrix) {
        case 'A': {
            mat.matrixA.row = row;
            mat.matrixA.column = column;
            mat.matrixA.matA = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                mat.matrixA.matA[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &mat.matrixA.matA[i][j]);
            break;
        }
        case 'B': {
            mat.matrixB.row = row;
            mat.matrixB.column = column;
            mat.matrixB.matB = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                mat.matrixB.matB[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &mat.matrixB.matB[i][j]);
            break;
        }
        case 'C': {
            mat.matrixC.row = row;
            mat.matrixC.column = column;
            mat.matrixC.matC = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                mat.matrixC.matC[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &mat.matrixC.matC[i][j]);
            break;
        }
        case 'D': {
            mat.matrixD.row = row;
            mat.matrixD.column = column;
            mat.matrixD.matD = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                mat.matrixD.matD[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &mat.matrixD.matD[i][j]);
            break;
        }
        case 'E': {
            mat.matrixE.row = row;
            mat.matrixE.column = column;
            mat.matrixE.matE = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                mat.matrixE.matE[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &mat.matrixE.matE[i][j]);
            break;
        }
        case 'F': {
            mat.matrixF.row = row;
            mat.matrixF.column = column;
            mat.matrixF.matF = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                mat.matrixF.matF[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &mat.matrixF.matF[i][j]);
            break;
        }
        case 'G': { // matrix answer
            mat.matrixAns.row = row;
            mat.matrixAns.column = column;
            mat.matrixAns.matAns = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                mat.matrixAns.matAns[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &mat.matrixAns.matAns[i][j]);
            break;
        }
    }
    printf("\nMatrix %c successfully defined!\n", matrix);
    system("pause");
    system("cls");
}

int get_matrix_row(char matrix) {
    int row;
    switch (matrix) {
        case 'A':
            row = mat.matrixA.row;
            break;
        case 'B':
            row = mat.matrixB.row;
            break;
        case 'C':
            row = mat.matrixC.row;
            break;
        case 'D':
            row = mat.matrixD.row;
            break;
        case 'E':
            row = mat.matrixE.row;
            break;
        case 'F':
            row = mat.matrixF.row;
            break;
        case 'G':
            row = mat.matrixAns.row;
            break;
    }
    return row;
}

int get_matrix_column(char matrix) {
    int column;
    switch (matrix) {
        case 'A':
            column = mat.matrixA.column;
            break;
        case 'B':
            column = mat.matrixB.column;
            break;
        case 'C':
            column = mat.matrixC.column;
            break;
        case 'D':
            column = mat.matrixD.column;
            break;
        case 'E':
            column = mat.matrixE.column;
            break;
        case 'F':
            column = mat.matrixF.column;
            break;
        case 'G':
            column = mat.matrixAns.column;
            break;
    }
    return column;
}
void matrix_selection(char* matrix1, char* matrix2) {
    int choice;
    printf("> Select the first matrix\n");
    for (int i = 0; i < 6; i++)
        printf("[%d] Matrix %c\n", i + 1, 'A' + i);
    printf("[7] Matrix Answer\n");
    printf("[8] Go back\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            *matrix1 = 'A';
            break;
        case 2:
            *matrix1 = 'B';
            break;
        case 3:
            *matrix1 = 'C';
            break;
        case 4:
            *matrix1 = 'D';
            break;
        case 5:
            *matrix1 = 'E';
            break;
        case 6:
            *matrix1 = 'F';
            break;
        case 7:
            *matrix1 = 'G';
            break;
        case 8:
            system("cls");
            compute_matrix();
            break;
        default:
            system("cls");
            printf("Please select a valid choice!\n\n");
            matrix_selection(matrix1, matrix2);
            break;
    }
    system("cls");
    printf("> Select the Second matrix\n");
    for (int i = 0; i < 6; i++)
        printf("[%d] Matrix %c\n", i + 1, 'A' + i);
    printf("[7] Matrix Answer\n");
    printf("[8] Go back\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            *matrix2 = 'A';
            break;
        case 2:
            *matrix2 = 'B';
            break;
        case 3:
            *matrix2 = 'C';
            break;
        case 4:
            *matrix2 = 'D';
            break;
        case 5:
            *matrix2 = 'E';
            break;
        case 6:
            *matrix2 = 'F';
            break;
        case 7:
            *matrix2 = 'G';
            break;
        case 8:
            system("cls");
            compute_matrix();
            break;
        default:
            system("cls");
            printf("Please select a valid choice!\n\n");
            matrix_selection(matrix1, matrix2);
            break;
    }
}

void add_matrix(char matrix1, char matrix2) {
    int rowMatrix1 = get_matrix_row(matrix1);
    int rowMatrix2 = get_matrix_row(matrix2);
    int columnMatrix1 = get_matrix_column(matrix1);
    int columnMatrix2 = get_matrix_column(matrix2);
    if ((rowMatrix1 == rowMatrix2) && (columnMatrix1 == columnMatrix2)) {
        mat.matrixTemp.row = rowMatrix1;
        mat.matrixTemp.column = columnMatrix1;
        mat.matrixTemp.matTemp = (int**)malloc(rowMatrix1 * sizeof(int*));
        for (int i = 0; i < rowMatrix1; i++)
            mat.matrixTemp.matTemp[i] = (int*)malloc(columnMatrix1 * sizeof(int));
        switch (matrix1) {
        case 'A':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] = mat.matrixA.matA[i][j];
                break;
            case 'B':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] = mat.matrixB.matB[i][j];
                break;
            case 'C':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] = mat.matrixC.matC[i][j];
                break;
            case 'D':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] = mat.matrixD.matD[i][j];
                break;
            case 'E':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] = mat.matrixE.matE[i][j];
                break;
            case 'F':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] = mat.matrixF.matF[i][j];
                break;
            case 'G':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] = mat.matrixAns.matAns[i][j];
                break;
        }
        switch (matrix2) {
            case 'A':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] += mat.matrixA.matA[i][j];
                break;
            case 'B':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] += mat.matrixB.matB[i][j];
                break;
            case 'C':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] += mat.matrixC.matC[i][j];
                break;
            case 'D':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] += mat.matrixD.matD[i][j];
                break;
            case 'E':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] += mat.matrixE.matE[i][j];
                break;
            case 'F':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] += mat.matrixF.matF[i][j];
                break;
            case 'G':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] += mat.matrixAns.matAns[i][j];
                break;
        }
    }
    else {
        printf("\nIncompatible matrix dimensions!\n\n");
        system("pause");
        system("cls");
        compute_matrix();
    }
    mat.matrixAns.row = rowMatrix1;
    mat.matrixAns.column = columnMatrix1;
    mat.matrixAns.matAns = (int**)malloc(rowMatrix1 * sizeof(int*));
    for (int i = 0; i < rowMatrix1; i++)
        mat.matrixAns.matAns[i] = (int*)malloc(columnMatrix1 * sizeof(int));
    for (int i = 0; i < rowMatrix1; i++)
        for (int j = 0; j < columnMatrix1; j++)
            mat.matrixAns.matAns[i][j] = mat.matrixTemp.matTemp[i][j];
    system("cls");
    if (matrix2 == 'G')
        printf("The sum of Matrix %c and Matrix Ans is:\n", matrix1);
    else
        printf("The sum of Matrix %c and Matrix %c is:\n", matrix1, matrix2);
    for (int i = 0; i < rowMatrix1; i++) {
        for (int j = 0; j < columnMatrix1; j++)
            printf("%d ", mat.matrixAns.matAns[i][j]);
        printf("\n");
    }
    printf("\n");
    system("pause");
    system("cls");
    compute_matrix();
}

void subtract_matrix(char matrix1, char matrix2) {
    int rowMatrix1 = get_matrix_row(matrix1);
    int rowMatrix2 = get_matrix_row(matrix2);
    int columnMatrix1 = get_matrix_column(matrix1);
    int columnMatrix2 = get_matrix_column(matrix2);
    if ((rowMatrix1 == rowMatrix2) && (columnMatrix1 == columnMatrix2)) {
        mat.matrixTemp.row = rowMatrix1;
        mat.matrixTemp.column = columnMatrix1;
        mat.matrixTemp.matTemp = (int**)malloc(rowMatrix1 * sizeof(int*));
        for (int i = 0; i < rowMatrix1; i++)
            mat.matrixTemp.matTemp[i] = (int*)malloc(columnMatrix1 * sizeof(int));
        switch (matrix1) {
            case 'A':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] = mat.matrixA.matA[i][j];
                break;
            case 'B':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] = mat.matrixB.matB[i][j];
                break;
            case 'C':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] = mat.matrixC.matC[i][j];
                break;
            case 'D':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] = mat.matrixD.matD[i][j];
                break;
            case 'E':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] = mat.matrixE.matE[i][j];
                break;
            case 'F':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] = mat.matrixF.matF[i][j];
                break;
            case 'G':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] = mat.matrixAns.matAns[i][j];
                break;
        }
        switch (matrix2) {
            case 'A':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] -= mat.matrixA.matA[i][j];
                break;
            case 'B':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] -= mat.matrixB.matB[i][j];
                break;
            case 'C':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] -= mat.matrixC.matC[i][j];
                break;
            case 'D':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] -= mat.matrixD.matD[i][j];
                break;
            case 'E':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] -= mat.matrixE.matE[i][j];
                break;
            case 'F':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] -= mat.matrixF.matF[i][j];
                break;
            case 'G':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix1; j++)
                        mat.matrixTemp.matTemp[i][j] -= mat.matrixAns.matAns[i][j];
                break;
        }
    }
    else {
        printf("\nIncompatible matrix dimensions!\n\n");
        system("pause");
        system("cls");
        compute_matrix();
    }
    mat.matrixAns.row = rowMatrix1;
    mat.matrixAns.column = columnMatrix1;
    mat.matrixAns.matAns = (int**)malloc(rowMatrix1 * sizeof(int*));
    for (int i = 0; i < rowMatrix1; i++)
        mat.matrixAns.matAns[i] = (int*)malloc(columnMatrix1 * sizeof(int));
    for (int i = 0; i < rowMatrix1; i++)
        for (int j = 0; j < columnMatrix1; j++)
            mat.matrixAns.matAns[i][j] = mat.matrixTemp.matTemp[i][j];
    system("cls");
    if (matrix2 == 'G')
        printf("The difference between Matrix %c and Matrix Ans is:\n", matrix1);
    else
        printf("The difference between Matrix %c and Matrix %c is:\n", matrix1, matrix2);
    for (int i = 0; i < rowMatrix1; i++) {
        for (int j = 0; j < columnMatrix1; j++)
            printf("%d ", mat.matrixAns.matAns[i][j]);
        printf("\n");
    }
    printf("\n");
    system("pause");
    system("cls");
    compute_matrix();
}

void multiply_matrix(char matrix1, char matrix2) {
    int rowMatrix1 = get_matrix_row(matrix1);
    int rowMatrix2 = get_matrix_row(matrix2);
    int columnMatrix1 = get_matrix_column(matrix1);
    int columnMatrix2 = get_matrix_column(matrix2);
    if (columnMatrix1 == rowMatrix2) {
        mat.matrixTemp.row = rowMatrix1;
        mat.matrixTemp.column = columnMatrix2;
        mat.matrixTemp.matTemp = (int**)malloc(rowMatrix1 * sizeof(int*));
        for (int i = 0; i < rowMatrix1; i++)
            mat.matrixTemp.matTemp[i] = (int*)malloc(columnMatrix2 * sizeof(int));
        for (int i = 0; i < rowMatrix1; i++)
            for (int j = 0; j < columnMatrix2; j++)
                    mat.matrixTemp.matTemp[i][j] = 0;
        switch (matrix1) {
            case 'A':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix2; j++) {
                        for (int k = 0; k < columnMatrix1; k++) {
                            if (matrix2 == 'A')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixA.matA[i][k] * mat.matrixA.matA[k][j];
                            else if (matrix2 == 'B')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixA.matA[i][k] * mat.matrixB.matB[k][j];
                            else if (matrix2 == 'C')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixA.matA[i][k] * mat.matrixC.matC[k][j];
                            else if (matrix2 == 'D')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixA.matA[i][k] * mat.matrixD.matD[k][j];
                            else if (matrix2 == 'E')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixA.matA[i][k] * mat.matrixE.matE[k][j];
                            else if (matrix2 == 'F')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixA.matA[i][k] * mat.matrixF.matF[k][j];
                            else if (matrix2 == 'G')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixA.matA[i][k] * mat.matrixAns.matAns[k][j];
                        }
                    }
                break;
            case 'B':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix2; j++) {
                        for (int k = 0; k < columnMatrix1; k++) {
                            if (matrix2 == 'A')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixB.matB[k][j] * mat.matrixA.matA[k][j];
                            else if (matrix2 == 'B')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixB.matB[k][j] * mat.matrixB.matB[k][j];
                            else if (matrix2 == 'C')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixB.matB[k][j] * mat.matrixC.matC[k][j];
                            else if (matrix2 == 'D')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixB.matB[k][j] * mat.matrixD.matD[k][j];
                            else if (matrix2 == 'E')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixB.matB[k][j] * mat.matrixE.matE[k][j];
                            else if (matrix2 == 'F')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixB.matB[k][j] * mat.matrixF.matF[k][j];
                            else if (matrix2 == 'G')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixB.matB[k][j] * mat.matrixAns.matAns[k][j];
                        }
                    }
                break;
            case 'C':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix2; j++) {
                        for (int k = 0; k < columnMatrix1; k++) {
                            if (matrix2 == 'A')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixC.matC[k][j] * mat.matrixA.matA[k][j];
                            else if (matrix2 == 'B')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixC.matC[k][j] * mat.matrixB.matB[k][j];
                            else if (matrix2 == 'C')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixC.matC[k][j] * mat.matrixC.matC[k][j];
                            else if (matrix2 == 'D')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixC.matC[k][j] * mat.matrixD.matD[k][j];
                            else if (matrix2 == 'E')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixC.matC[k][j] * mat.matrixE.matE[k][j];
                            else if (matrix2 == 'F')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixC.matC[k][j] * mat.matrixF.matF[k][j];
                            else if (matrix2 == 'G')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixC.matC[k][j] * mat.matrixAns.matAns[k][j];
                        }
                    }
                break;
            case 'D':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix2; j++) {
                        for (int k = 0; k < columnMatrix1; k++) {
                            if (matrix2 == 'A')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixD.matD[k][j] * mat.matrixA.matA[k][j];
                            else if (matrix2 == 'B')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixD.matD[k][j] * mat.matrixB.matB[k][j];
                            else if (matrix2 == 'C')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixD.matD[k][j] * mat.matrixC.matC[k][j];
                            else if (matrix2 == 'D')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixD.matD[k][j] * mat.matrixD.matD[k][j];
                            else if (matrix2 == 'E')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixD.matD[k][j] * mat.matrixE.matE[k][j];
                            else if (matrix2 == 'F')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixD.matD[k][j] * mat.matrixF.matF[k][j];
                            else if (matrix2 == 'G')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixD.matD[k][j] * mat.matrixAns.matAns[k][j];
                        }
                    }
                break;
            case 'E':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix2; j++) {
                        for (int k = 0; k < columnMatrix1; k++) {
                            if (matrix2 == 'A')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixE.matE[k][j] * mat.matrixA.matA[k][j];
                            else if (matrix2 == 'B')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixE.matE[k][j] * mat.matrixB.matB[k][j];
                            else if (matrix2 == 'C')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixE.matE[k][j] * mat.matrixC.matC[k][j];
                            else if (matrix2 == 'D')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixE.matE[k][j] * mat.matrixD.matD[k][j];
                            else if (matrix2 == 'E')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixE.matE[k][j] * mat.matrixE.matE[k][j];
                            else if (matrix2 == 'F')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixE.matE[k][j] * mat.matrixF.matF[k][j];
                            else if (matrix2 == 'G')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixE.matE[k][j] * mat.matrixAns.matAns[k][j];
                        }
                    }
                break;
            case 'F':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix2; j++) {
                        for (int k = 0; k < columnMatrix1; k++) {
                            if (matrix2 == 'A')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixF.matF[k][j] * mat.matrixA.matA[k][j];
                            else if (matrix2 == 'B')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixF.matF[k][j] * mat.matrixB.matB[k][j];
                            else if (matrix2 == 'C')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixF.matF[k][j] * mat.matrixC.matC[k][j];
                            else if (matrix2 == 'D')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixF.matF[k][j] * mat.matrixD.matD[k][j];
                            else if (matrix2 == 'E')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixF.matF[k][j] * mat.matrixE.matE[k][j];
                            else if (matrix2 == 'F')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixF.matF[k][j] * mat.matrixF.matF[k][j];
                            else if (matrix2 == 'G')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixF.matF[k][j] * mat.matrixAns.matAns[k][j];
                        }
                    }
                break;
            case 'G':
                for (int i = 0; i < rowMatrix1; i++)
                    for (int j = 0; j < columnMatrix2; j++) {
                        for (int k = 0; k < columnMatrix1; k++) {
                            if (matrix2 == 'A')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixAns.matAns[k][j] * mat.matrixA.matA[k][j];
                            else if (matrix2 == 'B')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixAns.matAns[k][j] * mat.matrixB.matB[k][j];
                            else if (matrix2 == 'C')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixAns.matAns[k][j] * mat.matrixC.matC[k][j];
                            else if (matrix2 == 'D')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixAns.matAns[k][j] * mat.matrixD.matD[k][j];
                            else if (matrix2 == 'E')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixAns.matAns[k][j] * mat.matrixE.matE[k][j];
                            else if (matrix2 == 'F')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixAns.matAns[k][j] * mat.matrixF.matF[k][j];
                            else if (matrix2 == 'G')
                                mat.matrixTemp.matTemp[i][j] += mat.matrixAns.matAns[k][j] * mat.matrixAns.matAns[k][j];
                        }
                    }
                break;
        }
    }
    else {
        printf("\nIncompatible matrix dimensions!\n\n");
        system("pause");
        system("cls");
        compute_matrix();
    }
    mat.matrixAns.row = rowMatrix1;
    mat.matrixAns.column = columnMatrix2;
    mat.matrixAns.matAns = (int**)malloc(rowMatrix1 * sizeof(int*));
    for (int i = 0; i < rowMatrix1; i++)
        mat.matrixAns.matAns[i] = (int*)malloc(columnMatrix2 * sizeof(int));
    for (int i = 0; i < rowMatrix1; i++)
        for (int j = 0; j < columnMatrix1; j++)
            mat.matrixAns.matAns[i][j] = mat.matrixTemp.matTemp[i][j];
    system("cls");
    if (matrix2 == 'G')
        printf("The product of Matrix %c and Matrix Ans is:\n", matrix1);
    else
        printf("The product of Matrix %c and Matrix %c is:\n", matrix1, matrix2);
    for (int i = 0; i < rowMatrix1; i++) {
        for (int j = 0; j < columnMatrix2; j++)
            printf("%d ", mat.matrixAns.matAns[i][j]);
        printf("\n");
    }
    printf("\n");
    system("pause");
    system("cls");
    compute_matrix();
}