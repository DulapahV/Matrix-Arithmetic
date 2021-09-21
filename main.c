#include <stdio.h>
#include <stdlib.h>


// Page
void main_menu_page();
void define_matrix_page();
void view_matrix_page();
void compute_matrix_page();
void show_answer_page();

// Matrix
void define_matrix(float*** matrix, int* row, int* column);
void view_matrix(float** matrix, int row, int column);
void matrix_select(float*** matrix1, int* row1, int* column1, float*** matrix2, int* row2, int* column2);

// Matrix Arithmetic
void add_matrix(float** matrix1, int row1, int column1, float** matrix2, int row2, int column2, float*** matrixAns, int* rowAns, int* columnAns);
void subtract_matrix(float** matrix1, int row1, int column1, float** matrix2, int row2, int column2, float*** matrixAns, int* rowAns, int* columnAns);
void multiply_matrix(float** matrix1, int row1, int column1, float** matrix2, int row2, int column2, float*** matrixAns, int* rowAns, int* columnAns);

// Program Message
void define_matrix_success_msg(char msg);
void invalid_choice_msg();
void incompatible_matrix_msg();


// Declaring matrixes
struct matrix_properties {
    int row, column, det;
};

struct matrix_A {
    float** matA;
    struct matrix_properties;
} matA;

struct matrix_B {
    float** matB;
    struct matrix_properties;
} matB;

struct matrix_C {
    float** matC;
    struct matrix_properties;
} matC;

struct matrix_D {
    float** matD;
    struct matrix_properties;
} matD;

struct matrix_E {
    float** matE;
    struct matrix_properties;
} matE;

struct matrix_F {
    float** matF;
    struct matrix_properties;
} matF;

struct matrix_Ans {
    float** matAns;
    struct matrix_properties;
} matAns;

struct matrix_Temp {
    float** matTemp;
    struct matrix_properties;
} matTemp;


// Main Program
int main() {
    main_menu_page();
    return 0;
}

//---------------------------------------------------------------- Page
void main_menu_page() {
    system("cls");
    int choice;
    printf("> What would you like to do\n");
    printf("[1] Define Matrix\n");
    printf("[2] View Matrix\n");
    printf("[3] Compute Matrix\n");
    printf("[4] Exit\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
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
            exit(0);
        default:
            main_menu_page();
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
    system("cls");
    switch (choice) {
        case 1:
            printf("> Define matrix %c\n", 'A' + choice - 1);
            define_matrix(&matA.matA, &matA.row, &matA.column);
            define_matrix_success_msg('A' + choice - 1);
            break;
        case 2:
            printf("> Define matrix %c\n", 'A' + choice - 1);
            define_matrix(&matB.matB, &matB.row, &matB.column);
            define_matrix_success_msg('A' + choice - 1);
            break;
        case 3:
            printf("> Define matrix %c\n", 'A' + choice - 1);
            define_matrix(&matC.matC, &matC.row, &matC.column);
            define_matrix_success_msg('A' + choice - 1);
            break;
        case 4:
            printf("> Define matrix %c\n", 'A' + choice - 1);
            define_matrix(&matD.matD, &matD.row, &matD.column);
            define_matrix_success_msg('A' + choice - 1);
            break;
        case 5:
            printf("> Define matrix %c\n", 'A' + choice - 1);
            define_matrix(&matE.matE, &matE.row, &matE.column);
            define_matrix_success_msg('A' + choice - 1);
            break;
        case 6:
            printf("> Define matrix %c\n", 'A' + choice - 1);
            define_matrix(&matF.matF, &matF.row, &matF.column);
            define_matrix_success_msg('A' + choice - 1);
            break;
        case 7:
            main_menu_page();
            break;
        default:
            invalid_choice_msg();
            break;
    }
    define_matrix_page();
}

void view_matrix_page() {
    system("cls");
    int choice;
    printf("> Select a matrix to view\n");
    for (int i = 0; i < 6; i++)
        printf("[%d] Matrix %c\n", i + 1, 'A' + i);
    printf("[7] Matrix Answer\n");
    printf("[8] Go back\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    system("cls");
    switch (choice) {
        case 1:
            printf("> View matrix %c\n", 'A' + choice - 1);
            view_matrix(matA.matA, matA.row, matA.column);
            system("pause");
            break;
        case 2:
            printf("> View matrix %c\n", 'A' + choice - 1);
            view_matrix(matB.matB, matB.row, matB.column);
            system("pause");
            break;
        case 3:
            printf("> View matrix %c\n", 'A' + choice - 1);
            view_matrix(matC.matC, matC.row, matC.column);
            system("pause");
            break;
        case 4:
            printf("> View matrix %c\n", 'A' + choice - 1);
            view_matrix(matD.matD, matD.row, matD.column);
            system("pause");
            break;
        case 5:
            printf("> View matrix %c\n", 'A' + choice - 1);
            view_matrix(matE.matE, matE.row, matE.column);
            system("pause");
            break;
        case 6:
            printf("> View matrix %c\n", 'A' + choice - 1);
            view_matrix(matF.matF, matF.row, matF.column);
            system("pause");
            break;
        case 7:
            printf("> View matrix Answer\n");
            view_matrix(matAns.matAns, matAns.row, matAns.column);
            system("pause");
            break;
        case 8:
            main_menu_page();
            break;
        default:
            invalid_choice_msg();
            break;
    }
    view_matrix_page();
}

void compute_matrix_page() {
    system("cls");
    int choice;
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
    system("cls");
    float** matrix1, **matrix2;
    int row1, column1, row2, column2;
    switch (choice) {
        case 1:
            matrix_select(&matrix1, &row1, &column1, &matrix2, &row2, &column2);
            add_matrix(matrix1, row1, column1, matrix2, row2, column2, &matAns.matAns, &matAns.row, &matAns.column);
            show_answer_page();
            system("pause");
            break;
        case 2:
            matrix_select(&matrix1, &row1, &column1, &matrix2, &row2, &column2);
            subtract_matrix(matrix1, row1, column1, matrix2, row2, column2, &matAns.matAns, &matAns.row, &matAns.column);
            show_answer_page();
            system("pause");
            break;
        case 3:
            matrix_select(&matrix1, &row1, &column1, &matrix2, &row2, &column2);
            multiply_matrix(matrix1, row1, column1, matrix2, row2, column2, &matAns.matAns, &matAns.row, &matAns.column);
            show_answer_page();
            system("pause");
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            main_menu_page();
            break;
        default:
            invalid_choice_msg();
            break;
    }
    compute_matrix_page();
}

void show_answer_page() {
    system("cls");
    printf("> The result is\n");
    for (int i = 0; i < matAns.row; i++) {
        for (int j = 0; j < matAns.column; j++) {
            printf("%.2f\t", matAns.matAns[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//---------------------------------------------------------------- Page


//---------------------------------------------------------------- Matrix
void define_matrix(float*** matrix, int* row, int* column) {
    printf("Number of Rows: ");
    scanf("%d", row);
    printf("Number of Columns: ");
    scanf("%d", column);
    printf("Enter value: \n");
    float** temp;
    temp = (float**)malloc(*row * sizeof(float*));
    for (int i = 0; i < *row; i++)
        temp[i] = (float*)malloc(*column * sizeof(float));
    for (int i = 0; i < *row; i++)
        for (int j = 0; j < *column; j++) {
            scanf("%f", &temp[i][j]);
            *matrix = temp;
        }
}

void view_matrix(float** matrix, int row, int column) {

    if (row != 0 && column != 0) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
                printf("%.2f\t", matrix[i][j]);
        printf("\n");
        }
    }
    else
        printf("\n[Empty]");
    printf("\n");
}
//---------------------------------------------------------------- Matrix


//---------------------------------------------------------------- Matrix Arithmetic
void matrix_select(float*** matrix1, int* row1, int* column1, float*** matrix2, int* row2, int* column2) {
    system("cls");
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
            *matrix1 = matA.matA;
            *row1 = matA.row;
            *column1 = matA.column;
            break;
        case 2:
            *matrix1 = matB.matB;
            *row1 = matB.row;
            *column1 = matB.column;
            break;
        case 3:
            *matrix1 = matC.matC;
            *row1 = matC.row;
            *column1 = matC.column;
            break;
        case 4:
            *matrix1 = matD.matD;
            *row1 = matD.row;
            *column1 = matD.column;
            break;
        case 5:
            *matrix1 = matE.matE;
            *row1 = matE.row;
            *column1 = matE.column;
            break;
        case 6:
            *matrix1 = matF.matF;
            *row1 = matF.row;
            *column1 = matF.column;
            break;
        case 7:
            *matrix1 = matAns.matAns;
            *row1 = matAns.row;
            *column1 = matAns.column;
            break;
        case 8:
            compute_matrix_page();
            break;
        default:
            invalid_choice_msg();
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
            *matrix2 = matA.matA;
            *row2 = matA.row;
            *column2 = matA.column;
            break;
        case 2:
            *matrix2 = matB.matB;
            *row2 = matB.row;
            *column2 = matB.column;
            break;
        case 3:
            *matrix2 = matC.matC;
            *row2 = matC.row;
            *column2 = matC.column;
            break;
        case 4:
            *matrix2 = matD.matD;
            *row2 = matD.row;
            *column2 = matD.column;
            break;
        case 5:
            *matrix2 = matE.matE;
            *row2 = matE.row;
            *column2 = matE.column;
            break;
        case 6:
            *matrix2 = matF.matF;
            *row2 = matF.row;
            *column2 = matF.column;
            break;
        case 7:
            *matrix2 = matAns.matAns;
            *row2 = matAns.row;
            *column2 = matAns.column;
            break;
        case 8:
            compute_matrix_page();
            break;
        default:
            invalid_choice_msg();
            break;
    }
}
void add_matrix(float** matrix1, int row1, int column1, float** matrix2, int row2, int column2, float*** matrixAns, int* rowAns, int* columnAns) {
    if ((row1 == row2) && (column1 == column2)) {
        *rowAns = row1;
        *columnAns = column1;
        float** temp;
        temp = (float**)malloc(row1 * sizeof(float*));
        for (int i = 0; i < row1; i++)
            temp[i] = (float*)malloc(column1 * sizeof(float));
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < column1; j++) {
                temp[i][j] = matrix1[i][j] + matrix2[i][j];
                *matrixAns = temp;
            }
    }
    else {
        system("cls");
        incompatible_matrix_msg();
        compute_matrix_page();
    }
}

void subtract_matrix(float** matrix1, int row1, int column1, float** matrix2, int row2, int column2, float*** matrixAns, int* rowAns, int* columnAns) {
    if ((row1 == row2) && (column1 == column2)) {
        *rowAns = row1;
        *columnAns = column1;
        float** temp;
        temp = (float**)malloc(row1 * sizeof(float*));
        for (int i = 0; i < row1; i++)
            temp[i] = (float*)malloc(column1 * sizeof(float));
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < column1; j++) {
                temp[i][j] = matrix1[i][j] - matrix2[i][j];
                *matrixAns = temp;
            }
    }
    else {
        system("cls");
        incompatible_matrix_msg();
        compute_matrix_page();
    }
}

void multiply_matrix(float** matrix1, int row1, int column1, float** matrix2, int row2, int column2, float*** matrixAns, int* rowAns, int* columnAns) {
    if (column1 == row2) {
        *rowAns = row1;
        *columnAns = column2;
        float** temp;
        temp = (float**)malloc(row1 * sizeof(float*));
        for (int i = 0; i < row1; i++)
            temp[i] = (float*)malloc(column2 * sizeof(float));
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < column2; j++)
                for (int k = 0; k < column1; k++) {
                    temp[i][j] += matrix1[i][k] * matrix2[k][j];
                    *matrixAns = temp;
                }
    }
    else {
        system("cls");
        incompatible_matrix_msg();
        compute_matrix_page();
    }
}
//---------------------------------------------------------------- Matrix Arithmetic


//---------------------------------------------------------------- Program Message
void define_matrix_success_msg(char msg) {
    printf("\nMatrix %c successfully defined!\n\n", msg);
    system("pause");
}

void invalid_choice_msg() {
    printf("Please select a valid choice!\n\n");
    system("pause");
}

void incompatible_matrix_msg() {
    printf("\nIncompatible matrix dimensions!\n\n");
    system("pause");
}
//---------------------------------------------------------------- Program Message