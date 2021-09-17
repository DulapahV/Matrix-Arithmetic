#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void main_menu();
void define_matrix();
void edit_matrix();
void compute_matrix();
void view_matrix(char matrix);
void prompt_matrix_size(int* row, int* column);
void prompt_matrix_value(char matrix, int row, int column);
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

struct matrix_list {
    struct matrix_A matrixA;
    struct matrix_B matrixB;
    struct matrix_C matrixC;
    struct matrix_D matrixD;
    struct matrix_E matrixE;
    struct matrix_F matrixF;
    struct matrix_Ans matrixAns;
} mat;

// Main Program
int main() {
    main_menu();
    return 0;
}

// Main menu
void main_menu() {
    int choice;
    printf("\n\nWhat would you like to do:\n");
    printf("[1] Define Matrix\n");
    printf("[2] View/Edit Matrix\n");
    printf("[3] Compute Matrix\n");
    printf("[4] Exit\n");
    printf("Choice--> ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            define_matrix();
            break;
        case 2:
            edit_matrix();
            break;
        case 3:
            compute_matrix();
            break;
        case 4:
            exit(0);
        default:
            printf("\n\nPlease select a valid choice!\n");
            main_menu();
            break;
    }
}

// Define matrix
void define_matrix() {
    int choice, row = 0, column = 0;
    printf("\n\nSelect a matrix to define:\n");
    for (int i = 0; i < 5; i++)
        printf("[%d] Matrix %c\n", i + 1, 'A' + i);
    printf("[7] Go back\n");
    printf("Choice--> ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 6) {
        printf("\n\nMatrix %c:\n", 'A' + choice - 1);
        prompt_matrix_size(&row, &column);
        prompt_matrix_value('A' + choice - 1, row, column);
        // for (int i = 0; i < row; i++)
        //     for (int j = 0; j < column; j++)
        //         printf("%d", mat.matrixA.matA[i][j]);
        // printf("\n");
        define_matrix();
    }
    else if (choice == 7)
        main_menu();
    else {
        printf("\n\nPlease select a valid choice!\n");
        define_matrix();
    }
}

// Edit Matrix
void edit_matrix() {
    int choice;
    printf("\n\nSelect a matrix to view/edit:\n");
    for (int i = 0; i < 5; i++)
        printf("[%d] Matrix %c\n", i + 1, 'A' + i);
    printf("[7] Matrix Answer\n");
    printf("[8] Go back\n");
    printf("Choice--> ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 7)
        view_matrix('A' + choice - 1);
    else if (choice == 8)
        main_menu();
    else {
        printf("\n\nPlease select a valid choice!\n");
        edit_matrix();
    }
}

void view_matrix(char matrix) {
    int choice;
    printf("\n\nViewing matrix %c:\n", matrix);
    switch (matrix) {
        case 'A':
            for (int i = 0; i < mat.matrixA.row; i++) {
                for (int j = 0; j < mat.matrixA.column; j++)
                    printf("%d ", mat.matrixA.matA[i][j]);
            printf("\n");
            }
            break;
        case 'B':
            for (int i = 0; i < mat.matrixB.row; i++) {
                for (int j = 0; j < mat.matrixB.column; j++)
                    printf("%d ", mat.matrixB.matB[i][j]);
            printf("\n");
            }
            break;
        case 'C':
            for (int i = 0; i < mat.matrixC.row; i++) {
                for (int j = 0; j < mat.matrixC.column; j++)
                    printf("%d ", mat.matrixC.matC[i][j]);
            printf("\n");
            }
            break;
        case 'D':
            for (int i = 0; i < mat.matrixD.row; i++) {
                for (int j = 0; j < mat.matrixD.column; j++)
                    printf("%d ", mat.matrixD.matD[i][j]);
            printf("\n");
            }
            break;
        case 'E':
            for (int i = 0; i < mat.matrixE.row; i++) {
                for (int j = 0; j < mat.matrixE.column; j++)
                    printf("%d ", mat.matrixE.matE[i][j]);
            printf("\n");
            }
            break;
        case 'F':
            for (int i = 0; i < mat.matrixF.row; i++) {
                for (int j = 0; j < mat.matrixF.column; j++)
                    printf("%d ", mat.matrixF.matF[i][j]);
            printf("\n");
            }
            break;
        case 'G':
            for (int i = 0; i < mat.matrixAns.row; i++) {
                for (int j = 0; j < mat.matrixAns.column; j++)
                    printf("%d ", mat.matrixAns.matAns[i][j]);
            printf("\n");
            }
            break;
    }
    printf("\n[1] Edit matrix\n");
    printf("[2] Go back\n");
    printf("Choice--> ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("\n\nEdit matrix %c:\n", matrix);
        prompt_matrix_value(matrix, get_matrix_row(matrix), get_matrix_column(matrix));
        view_matrix(matrix);
    }
    else if (choice == 2)
        edit_matrix();
    else {
        printf("\n\nPlease select a valid choice!\n");
        view_matrix(matrix);
    }
}

// Compute matrix
void compute_matrix() {
    int choice;
    printf("\n\nWhat operation would you like to perform:\n");
    printf("[1] Addition\n");
    printf("[2] Subtraction\n");
    printf("[3] Multiplication\n");
    printf("[4] Division\n");
    printf("[5] Determinant\n");
    printf("[6] Transposition\n");
    printf("[7] Inverse\n");
    printf("[8] Go back\n");
    printf("Choice--> ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("[1] Addition\n");
            break;
        case 2:
            printf("[2] Subtraction\n");
            break;
        case 3:
            printf("[3] Multiplication\n");
            break;
        case 4:
            printf("[4] Division\n");
            break;
        case 5:
            printf("[5] Determinant\n");
            break;
        case 6:
            printf("[6] Transposition\n");
            break;
        case 7:
            printf("[7] Inverse\n");
            break;
        case 8:
            main_menu();
            break;
        default:
            printf("\n\nPlease select a valid choice!\n");
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