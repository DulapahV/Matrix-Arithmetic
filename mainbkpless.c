#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void main_menu();
void define_matrix();
void edit_matrix();
void compute_matrix();
void matrix_selection(char* matrix1, char* matrix2);
void view_matrix(int** matrix);
void prompt_matrix_size(int* row, int* column);
void prompt_matrix_value(char matrix, int row, int column);
void add_matrix(int** matrix1, int** matrix2);
void subtract_matrix(int** matrix1, int** matrix2);
void multiply_matrix(int** matrix1, int** matrix2);
int get_matrix_row(int** matrix);
int get_matrix_column(int** matrix);

// Declaring matrixes
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

struct matrix_C {
    int** matC;
    struct matrix_properties;
} matC;

struct matrix_D {
    int** matD;
    struct matrix_properties;
} matD;

struct matrix_E {
    int** matE;
    struct matrix_properties;
} matE;

struct matrix_F {
    int** matF;
    struct matrix_properties;
} matF;

struct matrix_Ans {
    int** matAns;
    struct matrix_properties;
} matAns;

struct matrix_Temp {
    int** matTemp;
    struct matrix_properties;
} matTemp;

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
    switch (choice) {
    case 1:
        system("cls");
        view_matrix(matA.matA);
        break;
    case 2:
        system("cls");
        view_matrix(matB.matB);
        break;
    case 3:
        system("cls");
        view_matrix(matC.matC);
        break;
    case 4:
        system("cls");
        view_matrix(matD.matD);
        break;
    case 5:
        system("cls");
        view_matrix(matE.matE);
        break;
    case 6:
        system("cls");
        view_matrix(matF.matF);
        break;
    case 7:
        system("cls");
        view_matrix(matAns.matAns);
        break;
    case 8:
        system("cls");
        main_menu();
        break;
    default:
        system("cls");
        printf("Please select a valid choice!\n\n");
        edit_matrix();
        break;
    }
}

void view_matrix(int** matrix) {
    if ((get_matrix_row(matrix) != 0) && (get_matrix_column(matrix) != 0))
        for (int i = 0; i < get_matrix_row(matrix); i++) {
            for (int j = 0; j < get_matrix_column(matrix); j++)
                printf("%d\t", matrix[i][j]);
        printf("\n");
        }
    else {
        printf("[EMPTY]\n\n");
        system("pause");
        system("cls");
        edit_matrix();
    }
    int choice;
    printf("\n[1] Edit matrix\n");
    printf("[2] Go back\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("\n\n> Edit matrix:\n");
        prompt_matrix_value(matrix, get_matrix_row(matrix), get_matrix_column(matrix));
        edit_matrix();
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
            matA.row = row;
            matA.column = column;
            matA.matA = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                matA.matA[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &matA.matA[i][j]);
            break;
        }
        case 'B': {
            matB.row = row;
            matB.column = column;
            matB.matB = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                matB.matB[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &matB.matB[i][j]);
            break;
        }
        case 'C': {
            matC.row = row;
            matC.column = column;
            matC.matC = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                matC.matC[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &matC.matC[i][j]);
            break;
        }
        case 'D': {
            matD.row = row;
            matD.column = column;
            matD.matD = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                matD.matD[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &matD.matD[i][j]);
            break;
        }
        case 'E': {
            matE.row = row;
            matE.column = column;
            matE.matE = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                matE.matE[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &matE.matE[i][j]);
            break;
        }
        case 'F': {
            matF.row = row;
            matF.column = column;
            matF.matF = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                matF.matF[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &matF.matF[i][j]);
            break;
        }
        case 'G': { // matrix answer
            matAns.row = row;
            matAns.column = column;
            matAns.matAns = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                matAns.matAns[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &matAns.matAns[i][j]);
            break;
        }
    }
    printf("\nMatrix %c successfully defined!\n", matrix);
    system("pause");
    system("cls");
}

int get_matrix_row(int** matrix) {
    return matA.row;
    // return sizeof(matrix) / sizeof(matrix[0]);
}

int get_matrix_column(int** matrix) {
    return matA.column;
    // return sizeof(matrix[0]) / sizeof(matrix[0][0]);
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

void add_matrix(int** matrix1, int** matrix2) {
    if ((get_matrix_row(matrix1) == get_matrix_row(matrix2)) && (get_matrix_column(matrix1) == get_matrix_column(matrix2))) {
        matTemp.row = get_matrix_row(matrix1);
        matTemp.column = get_matrix_column(matrix1);
        matTemp.matTemp = (int**)malloc(get_matrix_row(matrix1) * sizeof(int*));
        for (int i = 0; i < get_matrix_row(matrix1); i++)
            matTemp.matTemp[i] = (int*)malloc(get_matrix_column(matrix1) * sizeof(int));
        for (int i = 0; i < get_matrix_row(matrix1); i++)
            for (int j = 0; j < get_matrix_column(matrix1); j++)
                matTemp.matTemp[i][j] = matrix1[i][j] + matrix2[i][j];
    }
    else {
        printf("\nIncompatible matrix dimensions!\n\n");
        system("pause");
        system("cls");
        compute_matrix();
    }
    matAns.row = get_matrix_row(matrix1);
    matAns.column = get_matrix_column(matrix1);
    matAns.matAns = (int**)malloc(get_matrix_row(matrix1) * sizeof(int*));
    for (int i = 0; i < get_matrix_row(matrix1); i++)
        matAns.matAns[i] = (int*)malloc(get_matrix_column(matrix1) * sizeof(int));
    for (int i = 0; i < get_matrix_row(matrix1); i++)
        for (int j = 0; j < get_matrix_column(matrix1); j++)
            matAns.matAns[i][j] = matTemp.matTemp[i][j];
    system("cls");
    printf("The sum of Matrix is:\n");
    for (int i = 0; i < get_matrix_row(matrix1); i++) {
        for (int j = 0; j < get_matrix_column(matrix1); j++)
            printf("%d\t", matAns.matAns[i][j]);
        printf("\n");
    }
    printf("\n");
    system("pause");
    system("cls");
    compute_matrix();
}

void subtract_matrix(int** matrix1, int** matrix2) {
    if ((get_matrix_row(matrix1) == get_matrix_row(matrix2)) && (get_matrix_column(matrix1) == get_matrix_column(matrix2))) {
        matTemp.row = get_matrix_row(matrix1);
        matTemp.column = get_matrix_column(matrix1);
        matTemp.matTemp = (int**)malloc(get_matrix_row(matrix1) * sizeof(int*));
        for (int i = 0; i < get_matrix_row(matrix1); i++)
            matTemp.matTemp[i] = (int*)malloc(get_matrix_column(matrix1) * sizeof(int));
        for (int i = 0; i < get_matrix_row(matrix1); i++)
            for (int j = 0; j < get_matrix_column(matrix1); j++)
                matTemp.matTemp[i][j] = matrix1[i][j] - matrix2[i][j];
    }
    else {
        printf("\nIncompatible matrix dimensions!\n\n");
        system("pause");
        system("cls");
        compute_matrix();
    }
    matAns.row = get_matrix_row(matrix1);
    matAns.column = get_matrix_column(matrix1);
    matAns.matAns = (int**)malloc(get_matrix_row(matrix1) * sizeof(int*));
    for (int i = 0; i < get_matrix_row(matrix1); i++)
        matAns.matAns[i] = (int*)malloc(get_matrix_column(matrix1) * sizeof(int));
    for (int i = 0; i < get_matrix_row(matrix1); i++)
        for (int j = 0; j < get_matrix_column(matrix1); j++)
            matAns.matAns[i][j] = matTemp.matTemp[i][j];
    system("cls");
    printf("The difference of Matrix is:\n");
    for (int i = 0; i < get_matrix_row(matrix1); i++) {
        for (int j = 0; j < get_matrix_column(matrix1); j++)
            printf("%d\t", matAns.matAns[i][j]);
        printf("\n");
    }
    printf("\n");
    system("pause");
    system("cls");
    compute_matrix();
}

void multiply_matrix(int** matrix1, int** matrix2) {
    if (get_matrix_column(matrix1) == get_matrix_row(matrix2)) {
        matTemp.row = get_matrix_row(matrix1);
        matTemp.column = get_matrix_column(matrix1);
        matTemp.matTemp = (int**)malloc(get_matrix_row(matrix1) * sizeof(int*));
        for (int i = 0; i < get_matrix_row(matrix1); i++)
            matTemp.matTemp[i] = (int*)malloc(get_matrix_column(matrix1) * sizeof(int));
        for (int i = 0; i < get_matrix_row(matrix1); i++)
            for (int j = 0; j < get_matrix_column(matrix2); j++)
                    matTemp.matTemp[i][j] = 0;
        for (int i = 0; i < get_matrix_row(matrix1); i++)
            for (int j = 0; j < get_matrix_column(matrix2); j++)
                for (int k = 0; k < get_matrix_column(matrix1); k++)
                    matTemp.matTemp[i][j] += matrix1[i][k] * matrix2[k][j];
    }
    else {
        printf("\nIncompatible matrix dimensions!\n\n");
        system("pause");
        system("cls");
        compute_matrix();
    }
    matAns.row = get_matrix_row(matrix1);
    matAns.column = get_matrix_row(matrix2);
    matAns.matAns = (int**)malloc(get_matrix_row(matrix1) * sizeof(int*));
    for (int i = 0; i < get_matrix_row(matrix1); i++)
        matAns.matAns[i] = (int*)malloc(get_matrix_column(matrix2) * sizeof(int));
    for (int i = 0; i < get_matrix_row(matrix1); i++)
        for (int j = 0; j < get_matrix_column(matrix2); j++)
            matAns.matAns[i][j] = matTemp.matTemp[i][j];
    system("cls");
    printf("The product of Matrix is:\n");
    for (int i = 0; i < get_matrix_row(matrix1); i++) {
        for (int j = 0; j < get_matrix_column(matrix2); j++)
            printf("%d\t", matAns.matAns[i][j]);
        printf("\n");
    }
    printf("\n");
    system("pause");
    system("cls");
    compute_matrix();
}