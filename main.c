/***************************************************************/
/* C Programming Individual Project, Year 1, Semester 1        */
/*                                                             */
/* Course: 13016235 C Programing Lecture                       */
/* Program: Software Engineering Program                       */
/* University: Faculty of Engineering, KMITL                   */
/*                                                             */
/* Project: Matrix-Arithmetic                                  */
/* Repository: https://github.com/DulapahV/Matrix-Arithmetic/  */
/* Written by: Dulapah Vibulsanti (64011388)                   */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MEM_ALLOCATE(dataType, length) (dataType *)malloc((length) * sizeof(dataType))

//--[Function Declaration]---------------------------------------
//  - Pages
//  - Matrix
//  - Matrix Arithmetic
//  - Program Message/Error
//---------------------------------------------------------------
// Pages
void main_menu_page();
void define_matrix_page();
void view_matrix_page();
void compute_matrix_page();

// Matrix
void define_matrix(double ***matrix, int *row, int *column);
void view_matrix(double **matrix, int row, int column);
int select_matrix(double ***matrix, int *row, int *column); // Return -2 if user select 'Go Back', -1 if user select invalid choice, else 0
void free_matrix();

// Matrix Arithmetic (Return 0 if input matrix is valid, else -1)
int add_matrix(double **matrix1, int row1, int column1, double **matrix2, int row2, int column2, double ***matrixAns, int *rowAns, int *columnAns);
int subtract_matrix(double **matrix1, int row1, int column1, double **matrix2, int row2, int column2, double ***matrixAns, int *rowAns, int *columnAns);
int multiply_matrix(double **matrix1, int row1, int column1, double **matrix2, int row2, int column2, double ***matrixAns, int *rowAns, int *columnAns);
double get_determinant(double **matrix, int dimension);
void get_coFactor(double **matrix, double **matrixTemp, int posX, int posY, int dimension);
void transpose_matrix(double **matrix, int row, int column, double ***matrixAns, int *rowAns, int *columnAns);
void get_adjoint(double **matrix, int dimension, double ***matrixAns, int *rowAns, int *columnAns);
int inverse_matrix(double **matrix, int dimension, double ***matrixAns, int *rowAns, int *columnAns);

// Program Messages/Errors
void define_matrix_success_msg(char msg);
void invalid_choice_error();
void incompatible_dimension_error();
void unequal_dimension_error();
void det_equal_zero_error();

//---------------------------------------------------------------
// Structure for Storing Matrixes Values and Dimensions
//---------------------------------------------------------------
struct matrix_A {
    double **matA;
    int row, column;
} matA;

struct matrix_B {
    double **matB;
    int row, column;
} matB;

struct matrix_C {
    double **matC;
    int row, column;
} matC;

struct matrix_D {
    double **matD;
    int row, column;
} matD;

struct matrix_E {
    double **matE;
    int row, column;
} matE;

struct matrix_F {
    double **matF;
    int row, column;
} matF;

struct matrix_Ans {
    double **matAns;
    int row, column;
} matAns;

//---------------------------------------------------------------
// Program Initialization
//---------------------------------------------------------------
int main() {
    main_menu_page();
    return 0;
}

//--[Program UI]-------------------------------------------------
//  - Main Menu
//  - Define Matrix
//  - View Matrix
//  - Compute Matrix
//---------------------------------------------------------------
// Main Menu
void main_menu_page() {
    int choice;
    system("cls");
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
    case 2:
        view_matrix_page();
    case 3:
        compute_matrix_page();
    case 4:
        free_matrix();
        exit(0);
    default:
        printf("\n");
        invalid_choice_error();
        system("pause");
    }
    main_menu_page();
}

// Define Matrix
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
    default:
        printf("\n");
        invalid_choice_error();
        system("pause");
        define_matrix_page();
    }
    printf("\n");
    define_matrix_success_msg('A' + choice - 1);
    system("pause");
    define_matrix_page();
}

// View Matrix
void view_matrix_page() {
    system("cls");
    printf("> Select a matrix to view\n");
    double **matrix;
    int row, column, choice = select_matrix(&matrix, &row, &column);
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

// Compute Matrix
void compute_matrix_page() {
    system("cls");
    double **matrix1, **matrix2;
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
    switch (choice) {
    case 1:
        system("cls");
        printf("> Select matrixes to add\n");

        // Prompt user to select 2 matrixes. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == -1 || choice == -2)
            compute_matrix_page();
        if ((choice = select_matrix(&matrix2, &row2, &column2)) == -1 || choice == -2)
            compute_matrix_page();
        
        // If matrix dimension is compatible (!= -1), print the result. Else, print Incompatible Dimension Error
        if (add_matrix(matrix1, row1, column1, matrix2, row2, column2, &matAns.matAns, &matAns.row, &matAns.column) != -1) {
            printf("> The sum is\n");
            view_matrix(matAns.matAns, matAns.row, matAns.column);
        }
        else
            incompatible_dimension_error();
        
        system("pause");
        break;
    case 2:
        system("cls");
        printf("> Select matrixes to subtract\n");

        // Prompt user to select 2 matrixes. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == -1 || choice == -2)
            compute_matrix_page();
        if ((choice = select_matrix(&matrix2, &row2, &column2)) == -1 || choice == -2)
            compute_matrix_page();
        
        // If matrix dimension is compatible (!= -1), print the result. Else, print Incompatible Dimension Error
        if (subtract_matrix(matrix1, row1, column1, matrix2, row2, column2, &matAns.matAns, &matAns.row, &matAns.column) != -1) {
            printf("> The difference is\n");
            view_matrix(matAns.matAns, matAns.row, matAns.column);
        }
        else
            incompatible_dimension_error();
        
        system("pause");
        break;
    case 3:
        system("cls");
        printf("> Select matrixes to multiply\n");

        // Prompt user to select 2 matrixes. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix2, &row2, &column2)) == -1 || choice == -2)
            compute_matrix_page();
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == -1 || choice == -2)
            compute_matrix_page();
        
        // If matrix dimension is compatible (!= -1), print the result. Else, print Incompatible Dimension Error
        if (multiply_matrix(matrix1, row1, column1, matrix2, row2, column2, &matAns.matAns, &matAns.row, &matAns.column) != -1) {
            printf("> The product is\n");
            view_matrix(matAns.matAns, matAns.row, matAns.column);
        }
        else
            incompatible_dimension_error();
        
        system("pause");
        break;
    case 4:
        system("cls");
        printf("> Select a matrix to find determinant\n");

        // Prompt user to select a matrix. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == -1 || choice == -2)
            compute_matrix_page();
        
        // If matrix dimension is equal, print the result. Else, print Unequal Dimension Error
        if (row1 == column1) {
            matAns.row = 1;
            matAns.column = 1;
            matAns.matAns = MEM_ALLOCATE(double *, 1);
            matAns.matAns[0] = MEM_ALLOCATE(double, 1);
            matAns.matAns[0][0] = get_determinant(matrix1, row1);
            printf("> The determinant is\n%.2lf\n\n", matAns.matAns[0][0]);
        }
        else
            unequal_dimension_error();
        
        system("pause");
        break;
    case 5:
        system("cls");
        printf("> Select a matrix to transpose\n");

        // Prompt user to select a matrix. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == -1 || choice == -2)
            compute_matrix_page();
        
        transpose_matrix(matrix1, row1, column1, &matAns.matAns, &matAns.row, &matAns.column);
        printf("> The transposition is\n");
        view_matrix(matAns.matAns, matAns.row, matAns.column);
        system("pause");
        break;
    case 6:
        system("cls");
        printf("> Select a matrix to find inverse\n");

        // Prompt user to select a matrix. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == -1 || choice == -2)
            compute_matrix_page();
        
        // If matrix dimension is equal, print the result. Else, print Unequal Dimension Error
        if (row1 == column1) {
            // If matrix determinant is not 0, print the result. Else, print Det Equal Zero Error
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
        system("cls");
        printf("> Select a matrix to find adjoint\n");

        // Prompt user to select a matrix. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == -1 || choice == -2)
            compute_matrix_page();
        
        // If matrix dimension is equal, print the result. Else, print Unequal Dimension Error
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
        printf("\n");
        invalid_choice_error();
        system("pause");
    }
    compute_matrix_page();
}

//--[Matrix]-----------------------------------------------------
//  - Define Matrix
//  - View Matrix
//  - Select Matrix
//  - Free Matrix
//---------------------------------------------------------------
// Define Matrix
void define_matrix(double ***matrix, int *row, int *column) {
    printf("Number of Rows: ");
    scanf("%d", row);
    printf("Number of Columns: ");
    scanf("%d", column);
    printf("Enter value: \n");
    double **tempAns;
    tempAns = MEM_ALLOCATE(double *, *row);
    for (int i = 0; i < *row; i++)
        tempAns[i] = MEM_ALLOCATE(double, *column);
    for (int i = 0; i < *row; i++)
        for (int j = 0; j < *column; j++)
            scanf("%lf", &tempAns[i][j]);
    *matrix = tempAns;
}

// View Matrix
void view_matrix(double **matrix, int row, int column) {
    if (row != 0 && column != 0)
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
                (matrix[i][j] == 0) ? printf("%.2lf\t", 0) : printf("%.2lf\t", matrix[i][j]); // Prevent displaying -0 instead of 0
            printf("\n");
        }
    else
        printf("[Empty]\n");
    printf("\n");
}

// Select Matrix
int select_matrix(double ***matrix, int *row, int *column) {
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
        *matrix = matA.matA, *row = matA.row, *column = matA.column;
        break;
    case 2:
        *matrix = matB.matB, *row = matB.row, *column = matB.column;
        break;
    case 3:
        *matrix = matC.matC, *row = matC.row, *column = matC.column;
        break;
    case 4:
        *matrix = matD.matD, *row = matD.row, *column = matD.column;
        break;
    case 5:
        *matrix = matE.matE, *row = matE.row, *column = matE.column;
        break;
    case 6:
        *matrix = matF.matF, *row = matF.row, *column = matF.column;
        break;
    case 7:
        *matrix = matAns.matAns, *row = matAns.row, *column = matAns.column;
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

// Free Matrix (I know these are incorrect, will rewrite soon)
void free_matrix() {
    free(matA.matA);
    free(matB.matB);
    free(matC.matC);
    free(matD.matD);
    free(matE.matE);
    free(matF.matF);
    free(matAns.matAns);
}

//--[Matrix Arithmetic]------------------------------------------
//  - Add Matrix
//  - Subtract Matrix
//  - Multiply Matrix
//  - Get Determinant
//  - Get Cofactor
//  - Transpose Matrix
//  - Get Adjoint
//  - Inverse Matrix
//---------------------------------------------------------------
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
        return -1;
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
        return -1;
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
        return -1;
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
        return -1;
    *matrixAns = tempAns;
    return 0;
}

//--[Program Messages/Errors]------------------------------------
//  - Define Matrix Success
//  - Invalid Choice Error
//  - Incompatible Dimension Error
//  - Unequal Dimension Error
//  - Det Equal Zero Error
//---------------------------------------------------------------
// Define Matrix Success
void define_matrix_success_msg(char msg) {
    printf("Matrix %c successfully defined!\n\n", msg);
}

// Invalid Choice Error
void invalid_choice_error() {
    printf("Please select a valid choice!\n\n");
}

// Incompatible Dimension Error
void incompatible_dimension_error() {
    printf("Incompatible matrix dimension!\n\n");
}

// Unequal Dimension Error
void unequal_dimension_error() {
    printf("Matrix dimension must be equal!\n\n");
}

// Unequal Dimension Error
void det_equal_zero_error() {
    printf("Cannot find inverse of singular matrix!\n\n");
}