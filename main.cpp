#include <stdio.h>
#include <stdlib.h>

void main_menu();
void define_matrix();
void edit_matrix();
void compute_matrix();
void prompt_matrix_size(int* row, int* column);
void prompt_matrix(char matrix, int row, int column);

int** matA;
int** matB;
int** matC;
int** matD;
int** matE;
int** matF;
int** matAns;

int main() {
    main_menu();
    return 0;
}

void main_menu() {
    int choice;
    printf("\n\nWhat would you like to do:\n");
    printf("[1] Define Matrix\n");
    printf("[2] Edit Matrix\n");
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
        prompt_matrix('A' + choice - 1, row, column);
        // for (int i = 0; i < row; i++)
        //     for (int j = 0; j < column; j++)
        //         printf("%d", matA[i][j]);
        // printf("\n");
        
    }
    else if (choice == 7)
        main_menu();
    else {
        printf("\n\nPlease select a valid choice!\n");
        define_matrix();
    }
}

void edit_matrix() {
    int choice;
    printf("\n\nSelect a matrix to edit:\n");
    for (int i = 0; i < 5; i++)
        printf("[%d] Matrix %c\n", i + 1, 'A' + i);
    printf("[7] Matrix Answer\n");
    printf("[8] Go back\n");
    printf("Choice--> ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("[1] Matrix A\n");
            break;
        case 2:
            printf("[2] Matrix B\n");
            break;
        case 3:
            printf("[3] Matrix C\n");
            break;
        case 4:
            printf("[4] Matrix D\n");
            break;
        case 5:
            printf("[5] Matrix E\n");
            break;
        case 6:
            printf("[6] Matrix F\n");
            break;
        case 7:
            printf("[7] Matrix Answer\n");
            break;
        case 8:
            main_menu();
            break;
        default:
            printf("\n\nPlease select a valid choice!\n");
            edit_matrix();
            break;
    }
}

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

void prompt_matrix(char matrix, int row, int column) {   
    switch (matrix) {
        case 'A': {
            matA = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                matA[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &matA[i][j]);
            break;
        }
        case 'B': {
            matB = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                matB[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &matB[i][j]);
            break;
        }
        case 'C': {
            matC = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                matC[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &matC[i][j]);
            break;
        }
        case 'D': {
            matD = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                matD[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &matD[i][j]);
            break;
        }
        case 'E': {
            matE = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                matE[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &matE[i][j]);
            break;
        }
        case 'F': {
            matF = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                matF[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &matF[i][j]);
            break;
        }
        case 'G': { // matrix answer
            matAns = (int**)malloc(row * sizeof(int*));
            for (int i = 0; i < row; i++)
                matAns[i] = (int*)malloc(column * sizeof(int));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    scanf("%d", &matAns[i][j]);
            break;
        }
    default:
        break;
    }
    
    // free(matA);
}