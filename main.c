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
#include "arithmetic.h" // functions for performing matrix calculations
#include "functions.h" // functions for performing matrix manipulations and program messages

// - User can change input and output file name here
// - There should be only 1 input file type in the program's directory. Otherwise, the program will only process INPUT_TXT_FILE
// - Both OUTPUT_TXT_FILE and OUTPUT_CSV_FILE must exist in the program's directory. If there is no OUTPUT_TXT_FILE, the program will also not output OUTPUT_CSV_FILE
//   However, if there is no OUTPUT_CSV_FILE, the program will still output OUTPUT_TXT_FILE
// - Maximum dimensions for reading matrix from a file is 100 x 100 with a maximum of 255 characters per delimiter
#define INPUT_TXT_FILE "input.txt"
#define INPUT_CSV_FILE "input.csv"
#define OUTPUT_TXT_FILE "output.txt"
#define OUTPUT_CSV_FILE "output.csv"

//--[Pages]------------------------------------------------------
void main_menu_page();
int define_matrix_selection_page(char msg); // return 1 if user choose to input through terminal, 2 through file, else -1 to go back
void define_matrix_page();
void view_matrix_page();
void compute_matrix_page();

//--[Program Initialization]-------------------------------------
int main() {
    main_menu_page();
    return 0;
}

//--[Program UI]-------------------------------------------------
//  - Main Menu
//  - Define Matrix Selection (terminal/command line or file input)
//  - Define Matrix
//  - View Matrix
//  - Compute Matrix
//---------------------------------------------------------------
// Main Menu
void main_menu_page() {
    int choice;
    system("cls");
    printf("> What would you like to do?\n");
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
        free_matrix(matA.value, matA.row, matA.column);
        free_matrix(matB.value, matB.row, matB.column);
        free_matrix(matC.value, matC.row, matC.column);
        free_matrix(matD.value, matD.row, matD.column);
        free_matrix(matE.value, matE.row, matE.column);
        free_matrix(matF.value, matF.row, matF.column);
        free_matrix(matAns.value, matAns.row, matAns.column);
        exit(0);
    default:
        invalid_choice_error();
        system("pause");
    }
    main_menu_page();
}

// Define Matrix Selection
int define_matrix_selection_page(char msg) {
    system("cls");
    int choice;
    printf("> How would you like to define matrix %c?\n", msg);
    printf("[1] Input through terminal/command line\n");
    printf("[2] Input through file (%s or %s)\n", INPUT_TXT_FILE, INPUT_CSV_FILE);
    printf("[3] Go back\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    fflush(stdin);
    switch (choice) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        define_matrix_page();
    default:
        invalid_choice_error();
        system("pause");
        define_matrix_selection_page(msg);
    }
}

// Define Matrix
void define_matrix_page() {
    system("cls");
    int choice;
    char delimiter[255]; // delimiter is limited to 255 characters
    printf("> Select a matrix to define\n");
    for (int i = 0; i < 6; i++)
        printf("[%d] Matrix %c\n", i + 1, 'A' + i);
    printf("[7] Go back\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        if (define_matrix_selection_page('A' + choice - 1) == 1)
            define_matrix(&matA.value, &matA.row, &matA.column);
        else {
            printf("\nDelimiter: ");
            fgets(delimiter, 255, stdin);
            if (read_matrix(INPUT_TXT_FILE, INPUT_CSV_FILE, delimiter, &matA.value, &matA.row, &matA.column) == 1) {
                cannot_read_error();
                system("pause");
                define_matrix_page();
            }
            printf("Read value:\n");
            view_matrix(matA.value, matA.row, matA.column);
        }
        break;
    case 2:
        if (define_matrix_selection_page('A' + choice - 1) == 1)
            define_matrix(&matB.value, &matB.row, &matB.column);
        else {
            printf("\nDelimiter: ");
            fgets(delimiter, 255, stdin);
            if (read_matrix(INPUT_TXT_FILE, INPUT_CSV_FILE, delimiter, &matB.value, &matB.row, &matB.column) == 1) {
                cannot_read_error();
                system("pause");
                define_matrix_page();
            }
            printf("Read value:\n");
            view_matrix(matB.value, matB.row, matB.column);
        }
        break;
    case 3:
        if (define_matrix_selection_page('A' + choice - 1) == 1)
            define_matrix(&matC.value, &matC.row, &matC.column);
        else {
            printf("\nDelimiter: ");
            fgets(delimiter, 255, stdin);
            if (read_matrix(INPUT_TXT_FILE, INPUT_CSV_FILE, delimiter, &matC.value, &matC.row, &matC.column) == 1) {
                cannot_read_error();
                system("pause");
                define_matrix_page();
            }
            printf("Read value:\n");
            view_matrix(matC.value, matC.row, matC.column);
        }
        break;
    case 4:
        if (define_matrix_selection_page('A' + choice - 1) == 1)
            define_matrix(&matD.value, &matD.row, &matD.column);
        else {
            printf("\nDelimiter: ");
            fgets(delimiter, 255, stdin);
            if (read_matrix(INPUT_TXT_FILE, INPUT_CSV_FILE, delimiter, &matD.value, &matD.row, &matD.column) == 1) {
                cannot_read_error();
                system("pause");
                define_matrix_page();
            }
            printf("Read value:\n");
            view_matrix(matD.value, matD.row, matD.column);
        }
        break;
    case 5:
        if (define_matrix_selection_page('A' + choice - 1) == 1)
            define_matrix(&matE.value, &matE.row, &matE.column);
        else {
            printf("\nDelimiter: ");
            fgets(delimiter, 255, stdin);
            if (read_matrix(INPUT_TXT_FILE, INPUT_CSV_FILE, delimiter, &matE.value, &matE.row, &matE.column) == 1) {
                cannot_read_error();
                system("pause");
                define_matrix_page();
            }
            printf("Read value:\n");
            view_matrix(matE.value, matE.row, matE.column);
        }
        break;
    case 6:
        if (define_matrix_selection_page('A' + choice - 1) == 1)
            define_matrix(&matF.value, &matF.row, &matF.column);
        else {
            printf("\nDelimiter: ");
            fgets(delimiter, 255, stdin);
            if (read_matrix(INPUT_TXT_FILE, INPUT_CSV_FILE, delimiter, &matF.value, &matF.row, &matF.column) == 1) {
                cannot_read_error();
                system("pause");
                define_matrix_page();
            }
            printf("Read value:\n");
            view_matrix(matF.value, matF.row, matF.column);
        }
        break;
    case 7:
        main_menu_page();
    default:
        invalid_choice_error();
        system("pause");
        define_matrix_page();
    }
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
    case 2:
        main_menu_page();
    case 1:
        view_matrix_page();
    default:
        printf("\nValue:\n");
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
    printf("> What operation would you like to perform?\n");
    printf("[1] Addition\n");
    printf("[2] Subtraction\n");
    printf("[3] Multiplication\n");
    printf("[4] Scalar Multiplication\n");
    printf("[5] Exponentiation\n");
    printf("[6] Determinant\n");
    printf("[7] Transposition\n");
    printf("[8] Inverse\n");
    printf("[9] Adjoint\n");
    printf("[10] Go back\n");
    printf("\nChoice--> ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        system("cls");
        printf("> Select matrixes to add\n");

        // Prompt user to select 2 matrixes. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == 1 || choice == 2)
            compute_matrix_page();
        if ((choice = select_matrix(&matrix2, &row2, &column2)) == 1 || choice == 2)
            compute_matrix_page();
        
        // If matrix dimension is compatible (!= 1), print the result. Else, print Incompatible Dimension Error
        if (add_matrix(matrix1, row1, column1, matrix2, row2, column2, &matAns.value, &matAns.row, &matAns.column) != 1) {
            printf("\n> The sum is\n");
            view_matrix(matAns.value, matAns.row, matAns.column);
        }
        else
            incompatible_dimension_error();
        
        system("pause");
        break;
    case 2:
        system("cls");
        printf("> Select matrixes to subtract\n");

        // Prompt user to select 2 matrixes. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == 1 || choice == 2)
            compute_matrix_page();
        if ((choice = select_matrix(&matrix2, &row2, &column2)) == 1 || choice == 2)
            compute_matrix_page();
        
        // If matrix dimension is compatible (!= 1), print the result. Else, print Incompatible Dimension Error
        if (subtract_matrix(matrix1, row1, column1, matrix2, row2, column2, &matAns.value, &matAns.row, &matAns.column) != 1) {
            printf("\n> The difference is\n");
            view_matrix(matAns.value, matAns.row, matAns.column);
        }
        else
            incompatible_dimension_error();
        
        system("pause");
        break;
    case 3:
        system("cls");
        printf("> Select matrixes to multiply\n");

        // Prompt user to select 2 matrixes. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix2, &row2, &column2)) == 1 || choice == 2)
            compute_matrix_page();
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == 1 || choice == 2)
            compute_matrix_page();
        
        // If matrix dimension is compatible (!= 1), print the result. Else, print Incompatible Dimension Error
        if (multiply_matrix(matrix1, row1, column1, matrix2, row2, column2, &matAns.value, &matAns.row, &matAns.column) != 1) {
            printf("\n> The product is\n");
            view_matrix(matAns.value, matAns.row, matAns.column);
        }
        else
            incompatible_dimension_error();
        
        system("pause");
        break;
    case 4:
        system("cls");
        printf("> Select a matrix to scalar multiply\n");

        // Prompt user to select a matrix. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == 1 || choice == 2)
            compute_matrix_page();
        
        double multiplier;
        printf("\nMultiplier: ");
        scanf("%lf", &multiplier);
        scalar_multiply_matrix(matrix1, row1, column1, multiplier, &matAns.value, &matAns.row, &matAns.column);
        printf("\n> The product is\n");
        view_matrix(matAns.value, matAns.row, matAns.column);
        system("pause");
        break;
    case 5:
        system("cls");
        printf("> Select a matrix to exponentiate\n");

        // Prompt user to select a matrix. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == 1 || choice == 2)
            compute_matrix_page();
        
        double exponent;
        printf("\nExponent: ");
        scanf("%lf", &exponent);
        exponentiation_matrix(matrix1, row1, column1, exponent, &matAns.value, &matAns.row, &matAns.column);
        printf("\n> The result is\n");
        view_matrix(matAns.value, matAns.row, matAns.column);
        system("pause");
        break;
    case 6:
        system("cls");
        printf("> Select a matrix to find determinant\n");

        // Prompt user to select a matrix. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == 1 || choice == 2)
            compute_matrix_page();
        
        // If matrix dimension is equal, print the result. Else, print Unequal Dimension Error
        if (row1 == column1) {
            matAns.row = 1, matAns.column = 1;
            matAns.value = MEM_ALLOCATE(double *, 1);
            matAns.value[0] = MEM_ALLOCATE(double, 1);
            matAns.value[0][0] = get_determinant(matrix1, row1);
            printf("\n> The determinant is\n%.2lf\n\n", matAns.value[0][0]);
        }
        else
            unequal_dimension_error();
        
        system("pause");
        break;
    case 7:
        system("cls");
        printf("> Select a matrix to transpose\n");

        // Prompt user to select a matrix. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == 1 || choice == 2)
            compute_matrix_page();
        
        transpose_matrix(matrix1, row1, column1, &matAns.value, &matAns.row, &matAns.column);
        printf("\n> The transposition is\n");
        view_matrix(matAns.value, matAns.row, matAns.column);
        system("pause");
        break;
    case 8:
        system("cls");
        printf("> Select a matrix to find inverse\n");

        // Prompt user to select a matrix. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == 1 || choice == 2)
            compute_matrix_page();
        
        // If matrix dimension is equal, print the result. Else, print Unequal Dimension Error
        if (row1 == column1) {
            // If matrix determinant is not 0, print the result. Else, print Det Equal Zero Error
            if (inverse_matrix(matrix1, row1, &matAns.value, &matAns.row, &matAns.column) != 1) {
                printf("\n> The inverse is\n");
                view_matrix(matAns.value, matAns.row, matAns.column);
            }
            else
                det_equal_zero_error();
        }
        else
            unequal_dimension_error();
        
        system("pause");
        break;
    case 9:
        system("cls");
        printf("> Select a matrix to find adjoint\n");

        // Prompt user to select a matrix. If user select invalid choice (-1) or choose to go back (-2), go back to Compute Matrix Page
        if ((choice = select_matrix(&matrix1, &row1, &column1)) == 1 || choice == 2)
            compute_matrix_page();
        
        // If matrix dimension is equal, print the result. Else, print Unequal Dimension Error
        if (row1 == column1) {
            get_adjoint(matrix1, row1, &matAns.value, &matAns.row, &matAns.column);
            printf("\n> The adjoint is\n");
            view_matrix(matAns.value, matAns.row, matAns.column);
        }
        else
            unequal_dimension_error();
        
        system("pause");
        break;
    case 10:
        main_menu_page();
        break;
    default:
        invalid_choice_error();
        system("pause");
        compute_matrix_page();
    }
    if (output_matrix(OUTPUT_TXT_FILE, OUTPUT_CSV_FILE, matAns.value, matAns.row, matAns.column) == 1) {
        cannot_print_error();
        system("pause");
    }
    compute_matrix_page();
}